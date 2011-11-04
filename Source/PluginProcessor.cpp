/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
PluginTestAudioProcessor::PluginTestAudioProcessor()
{
    for (int i = 0; i < totalNumParams; i++)
    {
        parameters.add (new PluginParameter());
    }
    
    parameters[param0]->init ("Gain",           // name
                              UnitGeneric,		// unit
                              "Gain Param",     // description
                              1.0,				// value
                              0.0,				// min
                              5.0,				// max
                              1.0);				// default
;
}

PluginTestAudioProcessor::~PluginTestAudioProcessor()
{
}

//==============================================================================
const String PluginTestAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int PluginTestAudioProcessor::getNumParameters()
{
    return parameters.size();
}

float PluginTestAudioProcessor::getParameter (int index)
{
    return parameters[index]->getNormalisedValue();
}

void PluginTestAudioProcessor::setParameter (int index, float newValue)
{
    parameters[index]->setNormalisedValue (newValue);
}

const String PluginTestAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String PluginTestAudioProcessor::getParameterText (int index)
{
    return String (parameters[index]->getNormalisedValue(), 2);
}

const String PluginTestAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String PluginTestAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool PluginTestAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool PluginTestAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool PluginTestAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool PluginTestAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

//==============================================================================
float PluginTestAudioProcessor::getScaledParameter (int index)
{
    return parameters[index]->getValue();
}

void PluginTestAudioProcessor::setScaledParameter (int index, float newValue)
{
    parameters[index]->setValue (newValue);
}

float PluginTestAudioProcessor::getParameterMin (int index)
{
    return parameters[index]->getMin();
}

float PluginTestAudioProcessor::getParameterMax (int index)
{
    return parameters[index]->getMax();
}

float PluginTestAudioProcessor::getParameterDefault (int index)
{
    return parameters[index]->getDefault();
}

//==============================================================================
int PluginTestAudioProcessor::getNumPrograms()
{
    return 0;
}

int PluginTestAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PluginTestAudioProcessor::setCurrentProgram (int index)
{
}

const String PluginTestAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void PluginTestAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void PluginTestAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void PluginTestAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void PluginTestAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getSampleData (channel);

        // ..do something to the data...
    }

    // just apply a gain for now
    buffer.applyGain (0, buffer.getNumSamples(), parameters[param0]->getValue());
    
    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
bool PluginTestAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* PluginTestAudioProcessor::createEditor()
{
    return new PluginTestAudioProcessorEditor (this);
}

//==============================================================================
void PluginTestAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PluginTestAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginTestAudioProcessor();
}