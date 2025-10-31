//
// Created by Joe on 23/10/2025.
//

#include "SineWaveDSP.h"
#include <cmath>
#include <numbers>

SineWaveDSP::SineWaveDSP(float amplitude, float frequency)
{
    m_amplitude = amplitude;
    m_frequency = frequency;
    m_sampleRate = 0.0f;
    m_currentTime = 0.0f;
    m_timeIncrement = 0.0f;
}

void SineWaveDSP::prepare(const double sampleRate)
{
    m_sampleRate = static_cast<float>(sampleRate);
    m_timeIncrement = static_cast<float>(1 / sampleRate);
}

void SineWaveDSP::process(float* output, const int numSamples)
{
    // Pass each sample through sine wave function
    for (int sample = 0; sample < numSamples; ++sample)
    {
        output[sample] = m_amplitude * sinf(2.0f * std::numbers::pi_v<float> * m_frequency * m_currentTime);
        m_currentTime += m_timeIncrement;
    }
}
