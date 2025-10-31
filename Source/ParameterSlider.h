//
// Created by Joe on 31/10/2025.
//

#ifndef SINEOSCILLATOR_PARAMETERSLIDER_H
#define SINEOSCILLATOR_PARAMETERSLIDER_H

#include <juce_gui_basics/juce_gui_basics.h>

class ParameterSlider : public juce::Slider
{
public:
    // Default values for default constructor
    static constexpr int DEFAULT_WIDTH = 300;
    static constexpr int DEFAULT_HEIGHT = 200;
    static constexpr int DEFAULT_TEXTBOX_WIDTH = 100;
    static constexpr int DEFAULT_TEXTBOX_HEIGHT = 50;
    static constexpr float DEFAULT_MIN_VALUE = 0.0f;
    static constexpr float DEFAULT_MAX_VALUE = 100.0f;
    static constexpr float DEFAULT_STEP_VALUE = 0.01f;
    static constexpr bool DEFAULT_IS_READ_ONLY = true;

    // Constructors
    ParameterSlider();
    ParameterSlider(const int width, const int height, const int textBoxWidth, const int textBoxHeight, bool isReadOnly);
};

#endif //SINEOSCILLATOR_PARAMETERSLIDER_H
