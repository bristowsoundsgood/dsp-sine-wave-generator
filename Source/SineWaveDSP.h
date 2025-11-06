//
// Created by Joe on 23/10/2025.
//

#ifndef SINEOSCILLATOR_SINEWAVEDSP_H
#define SINEOSCILLATOR_SINEWAVEDSP_H

#include <juce_audio_basics/juce_audio_basics.h>

namespace SineWaveDefaults
{
    static constexpr float defaultMinValue {20.0f};
    static constexpr float defaultMaxValue {20000.0f};
    static constexpr float defaultAmplitude {0.2f};
    static constexpr float defaultFrequency {220.0f};
    static constexpr float defaultCurrentTime {0.0f};
    static constexpr float defaultTimeIncrement {0.0f};
    static constexpr float defaultFreqSmoothTime {0.05f};
    static constexpr float defaultSampleRate {0.0f};
}

class SineWaveDSP {
public:
    SineWaveDSP();

    void prepare(double sampleRate);
    void process(float* output, int numSamples);

    [[nodiscard]] float getAmplitude() const { return m_amplitude; }
    [[nodiscard]] float getFrequency() { return m_freqSmooth.getNextValue(); }
    void setAmplitude(const float newAmplitude) { m_amplitude = newAmplitude; }
    void setFrequency(const float newFrequency) { m_freqSmooth.setTargetValue(newFrequency); }

private:
    float m_amplitude;
    float m_sampleRate;
    float m_timeIncrement;
    float m_currentTime;
    juce::SmoothedValue<float> m_freqSmooth;
};


#endif //SINEOSCILLATOR_SINEWAVEDSP_H