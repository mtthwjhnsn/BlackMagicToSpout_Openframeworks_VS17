#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	w = ofGetWidth();
	h = ofGetHeight();

	auto deviceList = ofxBlackmagic::Iterator::getDeviceList();

	for (auto device : deviceList) {
		auto input = shared_ptr<ofxBlackmagic::Input>(new ofxBlackmagic::Input());

		static int index = 0;
		auto mode = index++ == 0 ? bmdModeHD1080p25 : bmdModeHD1080p24;
		input->startCapture(device, mode);
		this->inputs.push_back(input);
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	for (auto input : this->inputs) {
		input->update();
	}


}

//--------------------------------------------------------------
void ofApp::draw() {
	float x = 0; float y = 0;
	float width = w; float height = h;

	for (auto input : this->inputs) {

		tex = input->getTexture();

		x += width;
		if (x >= ofGetWidth()) {
			x = 0;
			y += ofGetHeight();
		}
	}

	if (this->inputs.empty()) {

		ofDrawBitmapString("No BlackMagic input devices found", 20, 20);

	}

	if (tex.isAllocated()) {
		tex.draw(0, 0, w, h);

		spout.sendTexture(tex, "Input");
	}
}

void ofApp::exit() {
	spout.exit();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
