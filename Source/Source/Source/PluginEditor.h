#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class ReverbAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit ReverbAudioProcessorEditor (ReverbAudioProcessor&);
    ~ReverbAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    ReverbAudioProcessor& audioProcessor;

    const juce::Colour colBackground  { 0xFF1A1A2E };
    const juce::Colour colPanel       { 0xFF16213E };
    const juce::Colour colAccent      { 0xFF7B68EE };
    const juce::Colour colAccentLight { 0xFFAA99FF };
    const juce::Colour colText        { 0xFFE0E0F0 };
    const juce::Colour colTextMuted   { 0xFF8888AA };

    struct KnobSection
    {
        std::unique_ptr<juce::Slider> slider;
        std::unique_ptr<juce::Label>  label;
        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attachment;
    };

    KnobSection roomSizeKnob;
    KnobSection dampingKnob;
    KnobSection widthKnob;
    KnobSection mixKnob;

    void setupKnob (KnobSection& section,
                    const juce::String& paramID,
                    const juce::String& labelText);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbAudioProcessorEditor)
};
