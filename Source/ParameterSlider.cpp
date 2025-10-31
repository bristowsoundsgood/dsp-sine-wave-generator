//
// Created by Joe on 31/10/2025.
//

#include "ParameterSlider.h"
#include <juce_gui_basics/juce_gui_basics.h>
#pragma once

ParameterSlider::ParameterSlider()
{
    setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, DEFAULT_IS_READ_ONLY, DEFAULT_TEXTBOX_WIDTH, DEFAULT_TEXTBOX_HEIGHT);
    setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    setRange(DEFAULT_MIN_VALUE, DEFAULT_MAX_VALUE, DEFAULT_STEP_VALUE);
}

ParameterSlider::ParameterSlider(const int width, const int height, const int textBoxWidth, const int textBoxHeight, const bool isReadOnly)
{
    // Custom Values
    setSize(width, height);
    setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, isReadOnly, textBoxWidth, textBoxHeight);

    // Default Values
    setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    setRange(0.0f, 100.0f, 0.01f);
}
