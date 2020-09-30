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
    g.fillAll (juce::Colours::black);

    // sound loaded ? "sound loaded" : "load a sound"

    g.fillAll(juce::Colours::aliceblue);

    g.setColour (juce::Colours::antiquewhite);
    g.setFont (15.0f);

    if (audioProcessor.getNumSamplerSounds() > 0)
    {

        g.drawText("Sound Loaded",
                   getWidth() / 2,
                   getHeight() / 2 - 10,
                   100,
                   20,
                   juce::Justification::centred);
    }
    else
    {
        g.drawText("Load a sound",
                   getWidth() / 2,
                   getHeight() / 2 - 10,
                   100,
                   20,
                    juce::Justification::centred);
    }
}

void SgdsamplerAudioProcessorEditor::resized()
{
    // mLoadButton.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 50, 100, 100);
}

bool SgdsamplerAudioProcessorEditor::isInterestedInFileDrag (const juce::StringArray& files)
{
    for (auto& file : files)
        return (file.contains(".wav") || file.contains(".mp3") || file.contains(".aif"));

    return false;
}

void SgdsamplerAudioProcessorEditor::filesDropped (const juce::StringArray& files, int x, int y)
{
    for (auto file : files)
        if (isInterestedInFileDrag (files))
            audioProcessor.loadFile (file);

    repaint();
}
