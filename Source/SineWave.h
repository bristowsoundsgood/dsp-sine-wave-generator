//
// Created by Joe on 23/10/2025.
//

#ifndef SINEOSCILLATOR_SINEWAVE_H
#define SINEOSCILLATOR_SINEWAVE_H

#include <juce_audio_basics/juce_audio_basics.h>

class SineWave
{
public:
    void prepare(double sampleRate);
    void process(juce::AudioBuffer<float>& buffer);
private:
};


#endif //SINEOSCILLATOR_SINEWAVE_H