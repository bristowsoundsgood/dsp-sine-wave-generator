//
// Created by Joe on 23/10/2025.
//

#include "SineWave.h"
#include <juce_core/juce_core.h>

SineWave::SineWave(const float amplitude, const float frequency) {
    m_amplitude = amplitude;
    m_frequency = frequency;
}

void SineWave::prepare(const double sampleRate, const int nChannels) {              // Preparing all member variables before processing. Called by PluginProcessor.cpp during preparation.
    m_currentSampleRate = sampleRate;
    m_currentTime.resize(nChannels, 0.0f);
    m_timeIncrement = static_cast<float>(1 / sampleRate);
}

void SineWave::process(juce::AudioBuffer<float> &buffer) {              // 'Process' refers to the actions taken by this audio processing unit on the samples within a buffer.

    if (m_currentTime.size() != buffer.getNumChannels()) return;        // Safety check

    // For each channel, populate the buffer
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {

        auto* output = buffer.getWritePointer(channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
            output[sample] = m_amplitude * std::sinf(juce::MathConstants<float>::twoPi * m_frequency * m_currentTime[channel]);
            m_currentTime[channel] += m_timeIncrement;
        }
    }
}

