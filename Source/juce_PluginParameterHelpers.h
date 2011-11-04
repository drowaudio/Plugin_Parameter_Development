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

#ifndef __JUCE_PLUGINPARAMETERHELPERS_JUCEHEADER__
#define __JUCE_PLUGINPARAMETERHELPERS_JUCEHEADER__

/** Parameter Units - currently values are the same as the AudioUnit enums
 */
enum ParameterUnit
{
	UnitGeneric				= 0,	/* untyped value generally between 0.0 and 1.0 */
	UnitIndexed				= 1,	/* takes an integer value (good for menu selections) */
	UnitBoolean				= 2,	/* 0.0 means FALSE, non-zero means TRUE */
	UnitPercent				= 3,	/* usually from 0 -> 100, sometimes -50 -> +50 */
	UnitSeconds				= 4,	/* absolute or relative time */
	UnitSampleFrames		= 5,	/* one sample frame equals (1.0/sampleRate) seconds */
	UnitPhase				= 6,	/* -180 to 180 degrees */
	UnitRate				= 7,	/* rate multiplier, for playback speed, etc. (e.g. 2.0 == twice as fast) */
	UnitHertz				= 8,	/* absolute frequency/pitch in cycles/second */
	UnitCents				= 9,	/* unit of relative pitch */
	UnitRelativeSemiTones	= 10,	/* useful for coarse detuning */
	UnitMIDINoteNumber		= 11,	/* absolute pitch as defined in the MIDI spec (exact freq may depend on tuning table) */
	UnitMIDIController		= 12,	/* a generic MIDI controller value from 0 -> 127 */
	UnitDecibels			= 13,	/* logarithmic relative gain */
	UnitLinearGain			= 14,	/* linear relative gain */
	UnitDegrees				= 15,	/* -180 to 180 degrees, similar to phase but more general (good for 3D coord system) */
	UnitEqualPowerCrossfade = 16,	/* 0 -> 100, crossfade mix two sources according to sqrt(x) and sqrt(1.0 - x) */
	UnitMixerFaderCurve1	= 17,	/* 0.0 -> 1.0, pow(x, 3.0) -> linear gain to simulate a reasonable mixer channel fader response */
	UnitPan					= 18,	/* standard left to right mixer pan */
	UnitMeters				= 19,	/* distance measured in meters */
	UnitAbsoluteCents		= 20,	/* absolute frequency measurement : if f is freq in hertz then 	*/
                                    /* absoluteCents = 1200 * log2(f / 440) + 6900					*/
	UnitOctaves				= 21,	/* octaves in relative pitch where a value of 1 is equal to 1200 cents*/
	UnitBPM					= 22,	/* beats per minute, ie tempo */
    UnitBeats               = 23,	/* time relative to tempo, ie. 1.0 at 120 BPM would equal 1/2 a second */
	UnitMilliseconds		= 24,	/* parameter is expressed in milliseconds */
	UnitRatio				= 25,	/* for compression, expansion ratio, etc. */
	
	UnitCustomUnit			= 26	/* this is the parameter unit type for parameters that present a custom unit name */
};

namespace {
    
    /** Checks to see if two values are equal within a given precision.
     */
    inline bool almostEqual (double firstValue, double secondValue, double precision = 0.00001)
    {
        if (fabs (firstValue - secondValue) < precision)
            return true;
        else
            return false;
    }    
}

#endif //__JUCE_PLUGINPARAMETERHELPERS_JUCEHEADER__