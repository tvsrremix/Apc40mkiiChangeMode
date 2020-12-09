#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

class ofApp : public ofBaseApp, public ofxMidiListener {

public:
	void setup();
	void update();
	void draw();
	void exit();
	ofxMidiIn midiIn;
	void newMidiMessage(ofxMidiMessage& eventArgs);
	ofxMidiOut midiOut;
};
