/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SgdsamplerAudioProcessorEditor::SgdsamplerAudioProcessorEditor (SgdsamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    mLoadButton.onClick = [&]() { p.loadFile(); };
    addAndMakeVisible(mLoadButton);

    setSize (400, 300);
}

SgdsamplerAudioProcessorEditor::~SgdsamplerAudioProcessorEditor()
{
}

//==============================================================================
void SgdsamplerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void SgdsamplerAudioProcessorEditor::resized()
{
    mLoadButton.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 50, 100, 100);
}
