#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	midiIn.listInPorts();
	midiIn.openPort("APC40 mkII 0");//マシンによって違うかも
	midiIn.ignoreTypes(false, false, false);
	midiIn.addListener(this);
	midiIn.setVerbose(false);

	midiOut.listOutPorts();
	midiOut.openPort("APC40 mkII 1");//マシンによって違うかも

	////akai apc40 mkii
	vector<unsigned char> sysexMsg;
	sysexMsg.push_back(MIDI_SYSEX);

	sysexMsg.push_back(0x47);
	sysexMsg.push_back(0x7F);
	sysexMsg.push_back(0x29);
	sysexMsg.push_back(0x60);
	sysexMsg.push_back(0x00);
	sysexMsg.push_back(0x04);
	//---change mode
	///0x40 Generic (Startup Default) Track select Radio- Channel Toggle
	///0x41 Ableton Live(LED Ring Remote Controlled) Momentary All
	///0x42 Alternate Ableton Live Momentary All
	sysexMsg.push_back(0x42);
	//---
	sysexMsg.push_back(0x09);
	sysexMsg.push_back(0x07);
	sysexMsg.push_back(0x01);
	sysexMsg.push_back(MIDI_SYSEX_END);
	midiOut.sendMidiBytes(sysexMsg);
	exit();
}

void ofApp::update() {
}
void ofApp::draw() {
}
void ofApp::exit() {
	_Exit(0);
}
void ofApp::newMidiMessage(ofxMidiMessage& msg) {

}