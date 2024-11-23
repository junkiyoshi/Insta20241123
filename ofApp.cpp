#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofNoFill();
	ofSetCircleResolution(60);

	this->seed_value = ofRandom(1000);
}

//--------------------------------------------------------------
void ofApp::update() {
	
	ofSeedRandom(this->seed_value);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 120;
	for (int x = span * 1; x <= ofGetWindowWidth() - span * 1; x += span) {

		for (int y = span * 1; y <= ofGetWindowHeight() - span * 1; y += span) {

			auto center = glm::vec2(x, y);
			auto radius = span * 0.4;
			auto flag = ofRandom(100) < 50 ? true : false;

			for (int draw_radius = radius; draw_radius > 10;) {

				ofSetColor(239);
				ofDrawCircle(center, draw_radius * 0.99);

				flag = !flag;

				auto tmp_radius = draw_radius;
				draw_radius *= ofRandom(0.5, 0.8);

				auto deg = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -720, 720);
				auto center_radius = tmp_radius - draw_radius;
				center = center + glm::vec2(center_radius * cos(deg * DEG_TO_RAD), center_radius * sin(deg * DEG_TO_RAD));
			}
		}
	}

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}