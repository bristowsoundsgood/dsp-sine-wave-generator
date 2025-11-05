#include "PluginProcessor.h"
#include "PluginEditor.h"

namespace EditorLayout
{
    static constexpr int sliderWidth {300};
    static constexpr int sliderHeight {200};
    static constexpr int sliderTextBoxWidth {100};
    static constexpr int sliderTextBoxHeight {50};
    static constexpr float sliderMinValue {20.0f};
    static constexpr float sliderMaxValue {20000.0f};
    static constexpr float sliderStepValue {0.01f};
    static constexpr bool sliderIsReadOnly {true};
    static constexpr int labelWidth {100};
    static constexpr int labelHeight {20};
    static constexpr int labelBottomMargin {60};
    static constexpr int btnWidth {50};
    static constexpr int btnHeight {20};
    static constexpr int btnBottomMargin {100};
}

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p),
        freqSliderAttachment(processorRef.getState(), "sineFreq", freqSlider), playButtonAttachment(processorRef.getState(), "play", playButton)
{
    juce::ignoreUnused (processorRef);

    // Set bounds of main window
    setSize (400, 300);

    // Configure child components
    addAndMakeVisible(freqSlider);
    addAndMakeVisible(freqLabel);
    addAndMakeVisible(playButton);

    playButton.setButtonText("Playing");
    // bypassButton.setToggleState(true, juce::NotificationType::dontSendNotification);
    playButton.setClickingTogglesState(true);

    playButton.onClick = [this] () -> void
    {
        // Get current state
        const bool isPlaying = playButton.getToggleState();

        // Conditional rendering based on current state
        playButton.setButtonText(isPlaying ? "Playing" : "Bypassed");
    };
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::slategrey);
    g.setColour(juce::Colours::white);
    g.drawFittedText("Sine Wave Generator", getLocalBounds(), juce::Justification::centredTop, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    juce::Rectangle<int> bounds = getLocalBounds();

    // Render child components
    freqSlider.setBounds(bounds.getCentreX() - EditorLayout::sliderWidth / 2, bounds.getCentreY() - EditorLayout::sliderHeight / 2,
        EditorLayout::sliderWidth, EditorLayout::sliderHeight);

    freqSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, EditorLayout::sliderIsReadOnly, EditorLayout::sliderTextBoxWidth, EditorLayout::sliderTextBoxHeight);

    freqLabel.setBounds(bounds.getCentreX() - EditorLayout::labelWidth / 2, bounds.getCentreY() - EditorLayout::labelBottomMargin, EditorLayout::labelWidth, EditorLayout::labelHeight);
    freqLabel.setJustificationType(juce::Justification::centred);

    playButton.setBounds(bounds.getCentreX() - EditorLayout::btnWidth / 2, freqSlider.getBounds().getY() + EditorLayout::btnBottomMargin, EditorLayout::btnWidth, EditorLayout::btnHeight);
    playButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);
    playButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::limegreen);
}
