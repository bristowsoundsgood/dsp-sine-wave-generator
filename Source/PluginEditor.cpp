#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), freqSlider ()
{
    juce::ignoreUnused (processorRef);

    setSize (400, 300);

    // Configure child components
    addAndMakeVisible(freqSlider);
    addAndMakeVisible(freqLabel);
    addAndMakeVisible(playButton);

    playButton.setButtonText("Playing");
    playButton.setToggleState(true, juce::NotificationType::dontSendNotification);
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

    // Position child components
    freqSlider.setBounds(bounds.getCentreX() - freqSlider.getWidth() / 2, bounds.getCentreY() - freqSlider.getHeight() / 2,
        freqSlider.getWidth(), freqSlider.getHeight());

    freqLabel.setBounds(bounds.getCentreX() - 50, bounds.getCentreY() - 60, 100, 20);
    freqLabel.setJustificationType(juce::Justification::centred);

    playButton.setBounds(bounds.getCentreX() - 20, freqSlider.getBounds().getY() + 100, 40, 20);
    playButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::red);
    playButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::limegreen);
}
