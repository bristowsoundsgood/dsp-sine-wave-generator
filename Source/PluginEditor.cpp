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
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::slategrey);
    g.setColour(juce::Colours::white);
    g.drawFittedText("Sine Waves Test", getLocalBounds(), juce::Justification::centredTop, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    juce::Rectangle<int> bounds = getLocalBounds();
    freqSlider.setBounds(bounds.getCentreX() - freqSlider.getWidth() / 2, bounds.getCentreY() - freqSlider.getHeight() / 2,
        freqSlider.getWidth(), freqSlider.getHeight());
}
