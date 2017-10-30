#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetBackgroundAuto(false);
    ofNoFill();
    ofSetCircleResolution(60);

    // initialize global variables
    totalRays = 20;
    stepSize = 50;
    radius = 100;
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
    if(mouseX != 0 || mouseY != 0)
    {
        // follow mouse at slow rate
        sunLocX += (mouseX - sunLocX)*0.01;
        sunLocY += (mouseY - sunLocY)*0.01;
    }
    ofTranslate(sunLocX,sunLocY);
    ofSetColor(0,30);

    // draw sun rays
    ofBeginShape();
        ofPoint initPointLocation;
        float initNoisedRadius = (ofNoise(noiseSeeds[totalRays-1])* stepSize) + radius;
        // equally space rays around the center
        initPointLocation.x = cos(ofDegToRad(-angleStep)) * initNoisedRadius;
        initPointLocation.y = sin(ofDegToRad(-angleStep)) * initNoisedRadius;
        ofCurveVertex(initPointLocation);
        for (int i=0; i<totalRays; i++)
        {
            ofPoint pointLocation;
            // map mouse position on screen to 0-1 float
            // sets 'noised' distance from default sun body radius
            float noisedRadius = (ofNoise(noiseSeeds[i])* stepSize) + radius;
            // equally space rays around the center
            pointLocation.x = cos(ofDegToRad(angleStep*i)) * noisedRadius;
            pointLocation.y = sin(ofDegToRad(angleStep*i)) * noisedRadius;

            ofCurveVertex(pointLocation);
            noiseSeeds[i] += 0.01;
        }
        ofPoint endPointLocation;
        float endNoisedRadius = (ofNoise(noiseSeeds[0])* stepSize) + radius;
        // equally space rays around the center
        endPointLocation.x = cos(ofDegToRad(angleStep)* 0) * endNoisedRadius;
        endPointLocation.y = sin(ofDegToRad(angleStep) * 0) * endNoisedRadius;
        ofCurveVertex(endPointLocation);
        ofPoint controlPointLocation;
        float controlNoisedRadius = (ofNoise(noiseSeeds[1])* stepSize) + radius;
        // equally space rays around the center
        controlPointLocation.x = cos(ofDegToRad(angleStep)) * controlNoisedRadius;
        controlPointLocation.y = sin(ofDegToRad(angleStep)) * controlNoisedRadius;
        ofCurveVertex(controlPointLocation);
    ofEndShape();
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
