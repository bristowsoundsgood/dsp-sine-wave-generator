//
// Created by Joe on 23/10/2025.
//

#ifndef SINEOSCILLATOR_SINEWAVEDSP_H
#define SINEOSCILLATOR_SINEWAVEDSP_H


class SineWaveDSP {
public:
    SineWaveDSP(const float amplitude, const float frequency);

    void prepare(const double sampleRate);
    void process(float* output, const int numSamples);

    float getAmplitude() const { return m_amplitude; }
    float getFrequency() const { return m_frequency; }
    void setAmplitude(const float newAmplitude) { m_amplitude = newAmplitude; }
    void setFrequency(const float newFrequency) { m_frequency = newFrequency; }

private:
    float m_amplitude;
    float m_frequency;
    float m_sampleRate;
    float m_timeIncrement;
    float m_currentTime;
};


#endif //SINEOSCILLATOR_SINEWAVEDSP_H