//
// Created by Joe on 23/10/2025.
//

#ifndef SINEOSCILLATOR_SINEWAVE_H
#define SINEOSCILLATOR_SINEWAVE_H

#include <juce_audio_basics/juce_audio_basics.h>

class SineWave
{
public:
    SineWave(float amplitude, float frequency);

    void prepare(double sampleRate, int nChannels);
    void process(juce::AudioBuffer<float>& buffer);

    [[nodiscard]] float getAmplitude() const { return m_amplitude; }
    [[nodiscard]] float getFrequency() const { return m_frequency; }
    void setAmplitude (const float newAmplitude) { m_amplitude = newAmplitude; }
    void setFrequency (const float newFrequency) { m_frequency = newFrequency; }

private:
    float m_amplitude {};
    float m_frequency {};
    float m_currentSampleRate {};
    float m_timeIncrement {};
    std::vector<float> m_currentTime;
};


#endif //SINEOSCILLATOR_SINEWAVE_H