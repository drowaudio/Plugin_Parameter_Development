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

#ifndef __JUCE_PLUGINPARAMETER_JUCEHEADER__
#define __JUCE_PLUGINPARAMETER_JUCEHEADER__

#include "../JuceLibraryCode/JuceHeader.h"

#include "juce_PluginParameterHelpers.h"

/**	This file defines a parameter used in an application.
 
	Both full-scale and normalised values must be present for
	AU and VST host campatability.
 */
class PluginParameter
{
public:
	/** Create a default parameter.
	 
		This just uses some standard default values so it can be used as a placeholder.
		Call init() once you know the parameter values.
     
		@see init()
	 */
	PluginParameter();

    /** Creates a copy of another parameter.
     */
    PluginParameter (const PluginParameter& other);
    
	/** Initialise the parameter.
		Used to set up the parameter as required.
	 */
	void init (const String& name_, ParameterUnit unit_, String description_,
               double value_, double min_ =0.0f, double max_ =1.0f, double default_ =0.0f,
               double skewFactor_ =1.0f, double smoothCoeff_ =0.1f, double step_ =0.01, String unitSuffix_ =String::empty);

    inline Value& getValueObject()                              {   return valueObject;     }
    
	inline double getValue()                                    {   return double (valueObject.getValue()); }
	inline double getNormalisedValue()                          {   return normaliseValue (getValue());     }
	void setValue (double value_);
	void setNormalisedValue (double normalisedValue);
	inline double getSmoothedValue()                            {   return smoothValue;     }
	inline double getSmoothedNormalisedValue()                  {   return normaliseValue (smoothValue);     }
	
	inline double getMin()                                      {   return min;             }
	inline double getMax()                                      {   return max;             }
	inline double getDefault()                                  {   return defaultValue;    }
	
	void smooth();
	void setSmoothCoeff (double newSmoothCoef);
	inline double getSmoothCoeff()                              {   return smoothCoeff;     }
	
	void setSkewFactor (const double newSkewFactor);
	void setSkewFactorFromMidPoint (const double valueToShowAtMidPoint);
	inline double getSkewFactor()                               {   return skewFactor;      }
	
	void setStep (double newStep);
	inline double getStep()                                     {   return step;            }
	
	inline const String getName()                               {   return name;            }
	inline ParameterUnit getUnit()                              {   return unit;            }
	inline const String getUnitSuffix()                         {   return unitSuffix;      }
	void setUnitSuffix (String newSuffix);
	
	void writeXml (XmlElement& xmlState);
	void readXml (const XmlElement* xmlState);
	
	/** Sets up a given slider with the parmeters properties.
     */
	void setupSlider (Slider& slider);
	
private:
    
    Value valueObject;
	String name, description, unitSuffix;
	double min, max, defaultValue;
	double smoothCoeff, smoothValue;
	double skewFactor, step;
	ParameterUnit unit;
	
    double normaliseValue (double scaledValue);

	JUCE_LEAK_DETECTOR (PluginParameter);
};

#endif //__JUCE_PLUGINPARAMETER_JUCEHEADER__