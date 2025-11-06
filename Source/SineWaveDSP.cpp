//
// Created by Joe on 23/10/2025.
//

#include "SineWaveDSP.h"
#include <cmath>
#include <numbers>

SineWaveDSP::SineWaveDSP()
{
    m_amplitude = SineWaveDefaults::defaultAmplitude;
    m_currentTime = SineWaveDefaults::defaultCurrentTime;
    m_timeIncrement = SineWaveDefaults::defaultTimeIncrement;
    m_sampleRate = SineWaveDefaults::defaultSampleRate;
}


void SineWaveDSP::prepare(const double sampleRate)
{
    m_sampleRate = static_cast<float>(sampleRate);
    m_timeIncrement = static_cast<float>(1 / sampleRate);
    m_freqSmooth.reset(sampleRate, SineWaveDefaults::defaultFreqSmoothTime);
    m_freqSmooth.setCurrentAndTargetValue(getFrequency());
}

void SineWaveDSP::process(float* output, const int numSamples)
{
    // For all samples in buffer
    for (int sample = 0; sample < numSamples; ++sample)
    {
        // Use smoother frequency
        const float currentFreq = m_freqSmooth.getNextValue();

        // Process sample
        output[sample] = m_amplitude * sinf(2.0f * std::numbers::pi_v<float> * currentFreq * m_currentTime);
        m_currentTime += m_timeIncrement;
    }
}
