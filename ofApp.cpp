#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetCircleResolution(60);

    // initialize global variables
    totalRays = 100;
    stepSize = 200;
    radius = 300;
    angleStep = 360.0/totalRays;
    sunLocX = ofGetWidth()/2;
    sunLocY = ofGetHeight()/2;
    for(int i = 0; i < totalRays; i++)
    {
        noiseSeeds.push_back(ofRandom(0,10000));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // center all elements
    ofTranslate(sunLocX,sunLocY);
    ofSetColor(253,202,19);

    // draw sun rays
    ofBeginShape();
        for (int i=0; i<totalRays; i++)
        {
            ofPoint pointLocation;
            // map mouse position on screen to 0-1 float
            float amt = ofMap(mouseX, 0, ofGetWidth(), 0, 1, true);
            // sets 'noised' distance from default sun body radius
            float noisedRadius = (ofNoise(noiseSeeds[i])* stepSize) + radius;
            // equally space rays around the center
            pointLocation.x = cos(ofDegToRad(angleStep*i)) * noisedRadius;
            pointLocation.y = sin(ofDegToRad(angleStep*i)) * noisedRadius;
            pointLocation = pointLocation * amt;

            ofVertex(pointLocation);
            noiseSeeds[i] += 0.01;
        }
    ofEndShape();
    // draw sun body
    ofSetColor(255,215,13);
    ofDrawCircle(0,0,300);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
