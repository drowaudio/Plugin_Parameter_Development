/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-11 by Raw Material Software Ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the GNU General
   Public License (Version 2), as published by the Free Software Foundation.
   A copy of the license is included in the JUCE distribution, or can be found
   online at www.gnu.org/licenses.

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.rawmaterialsoftware.com/juce for more information.

  ==============================================================================
*/

#ifndef __JUCE_AUDIOPROCESSOREXT_JUCEHEADER__
#define __JUCE_AUDIOPROCESSOREXT_JUCEHEADER__

//#include "juce_AudioProcessorExtEditor.h"
//#include "juce_AudioProcessorExtListener.h"
//#include "juce_AudioPlayHead.h"
#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
    Base class for audio processing filters or plugins.

    This is intended to act as a base class of audio filter that is general enough to
    be wrapped as a VST, AU, RTAS, etc, or used internally.

    It is also used by the plugin hosting code as the wrapper around an instance
    of a loaded plugin.

    Derive your filter class from this base class, and if you're building a plugin,
    you should implement a global function called createPluginFilter() which creates
    and returns a new instance of your subclass.
*/
class JUCE_API  AudioProcessorExt : public AudioProcessor
{
protected:
    //==============================================================================
    /** Constructor.

        You can also do your initialisation tasks in the initialiseFilterInfo()
        call, which will be made after this object has been created.
    */
    AudioProcessorExt();

public:    
    /** Destructor. */
    virtual ~AudioProcessorExt();

    //==============================================================================
    virtual const String getName() const = 0;

    //==============================================================================
    virtual void prepareToPlay (double sampleRate,
                                int estimatedSamplesPerBlock) = 0;

    virtual void releaseResources() = 0;

    virtual void processBlock (AudioSampleBuffer& buffer,
                               MidiBuffer& midiMessages) = 0;

    //==============================================================================
    AudioPlayHead* getPlayHead() const noexcept               { return playHead; }

    //==============================================================================
    double getSampleRate() const noexcept                     { return sampleRate; }

    int getBlockSize() const noexcept                         { return blockSize; }

    //==============================================================================
    int getNumInputChannels() const noexcept                  { return numInputChannels; }

    int getNumOutputChannels() const noexcept                 { return numOutputChannels; }

    virtual const String getInputChannelName (int channelIndex) const = 0;

    virtual const String getOutputChannelName (int channelIndex) const = 0;

    virtual bool isInputChannelStereoPair (int index) const = 0;

    virtual bool isOutputChannelStereoPair (int index) const = 0;

    int getLatencySamples() const noexcept                            { return latencySamples; }

    void setLatencySamples (int newLatency);

    virtual bool acceptsMidi() const = 0;

    virtual bool producesMidi() const = 0;

    //==============================================================================
    const CriticalSection& getCallbackLock() const noexcept             { return callbackLock; }

    void suspendProcessing (bool shouldBeSuspended);

    bool isSuspended() const noexcept                                   { return suspended; }

    virtual void reset();

    //==============================================================================
    bool isNonRealtime() const noexcept                                 { return nonRealtime; }

    void setNonRealtime (bool isNonRealtime) noexcept;

    //==============================================================================
    virtual AudioProcessorEditor* createEditor() = 0;

    virtual bool hasEditor() const = 0;

    //==============================================================================
    AudioProcessorEditor* getActiveEditor() const noexcept             { return activeEditor; }

    AudioProcessorEditor* createEditorIfNeeded();

    //==============================================================================
    virtual int getNumParameters() = 0;

    virtual const String getParameterName (int parameterIndex) = 0;

    virtual float getParameter (int parameterIndex) = 0;

    virtual const String getParameterText (int parameterIndex) = 0;

    virtual void setParameter (int parameterIndex,
                               float newValue) = 0;

    void setParameterNotifyingHost (int parameterIndex,
                                    float newValue);

    virtual bool isParameterAutomatable (int parameterIndex) const;

    virtual bool isMetaParameter (int parameterIndex) const;

    void beginParameterChangeGesture (int parameterIndex);

    void endParameterChangeGesture (int parameterIndex);

    void updateHostDisplay();

    //==============================================================================
    //***
    /** Some hosts may call this if they support parameter ranges outside of the
     0 - 1.0 range. This should return the value of your full-scale parameter.
     
     By default this just returns your normalised parameter by calling getParameter().
     */
    virtual float getScaledParameter (int parameterIndex);
    
    /** Some hosts may call this if they support parameter ranges outside of the
     0 - 1.0 range. The newValue argument could be any number so you should allow
     for this in your code.
     
     By default this just sets your normalised parameter by calling setParameter().
     */
    virtual void setScaledParameter (int parameterIndex, float newValue);
    
    /** Sets a full scale parameter and notifies the host, similar to
     setParameterNotifyingHost().
     */
    void setScaledParameterNotifyingHost (int parameterIndex, float newValue);
    
    /** Some hosts may call this if they support parameter ranges outside of the
     0 - 1.0 range. This should return the minimum value your parameter can have.
     */
    virtual float getParameterMin (int parameterIndex);
    
    /** Some hosts may call this if they support parameter ranges outside of the
     0 - 1.0 range. This should return the maximum value your parameter can have.
     */
    virtual float getParameterMax (int parameterIndex);
    
    /** Some hosts may call this if they support parameter ranges outside of the
     0 - 1.0 range. This should return the default value your parameter has.
     */
    virtual float getParameterDefault (int parameterIndex);
    
    //==============================================================================
    virtual int getNumPrograms() = 0;

    virtual int getCurrentProgram() = 0;

    virtual void setCurrentProgram (int index) = 0;

    virtual const String getProgramName (int index) = 0;

    virtual void changeProgramName (int index, const String& newName) = 0;

    //==============================================================================
    virtual void getStateInformation (juce::MemoryBlock& destData) = 0;

    virtual void getCurrentProgramStateInformation (juce::MemoryBlock& destData);

    virtual void setStateInformation (const void* data, int sizeInBytes) = 0;

    virtual void setCurrentProgramStateInformation (const void* data, int sizeInBytes);


    //==============================================================================
    void addListener (AudioProcessorListener* newListener);

    void removeListener (AudioProcessorListener* listenerToRemove);

    //==============================================================================
    void setPlayHead (AudioPlayHead* newPlayHead) noexcept;

    //==============================================================================
    void editorBeingDeleted (AudioProcessorEditor* editor) noexcept;

    void setPlayConfigDetails (int numIns, int numOuts,
                               double sampleRate,
                               int blockSize) noexcept;

protected:
    //==============================================================================
    static void copyXmlToBinary (const XmlElement& xml,
                                 juce::MemoryBlock& destData);

    static XmlElement* getXmlFromBinary (const void* data, int sizeInBytes);

    AudioPlayHead* playHead;

    void sendParamChangeMessageToListeners (int parameterIndex, float newValue);

private:
    Array <AudioProcessorListener*> listeners;
    Component::SafePointer<AudioProcessorEditor> activeEditor;
    double sampleRate;
    int blockSize, numInputChannels, numOutputChannels, latencySamples;
    bool suspended, nonRealtime;
    CriticalSection callbackLock, listenerLock;

   #if JUCE_DEBUG
    BigInteger changingParams;
   #endif

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProcessorExt);
};


#endif   // __JUCE_AUDIOPROCESSOREXT_JUCEHEADER__
