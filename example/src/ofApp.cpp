#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(120);
    
    //numSteps (the outputImage will be n-Times bigger than the windowsize), border(most times zero), save as one big image?
    //-> depends on your RAM, if you want to go bigger than 12k*12k you should propably set this to false and stich the tiles
    // offline.
    saver.init(5, 0, true);
    r = ofRandom(0,100);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSeedRandom(r);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //use this is you have custom camera setup:
    //saver.setCameraData(ofVec3f(1000, 10, 1000), ofVec3f(1000, 10, 1000), ofVec3f(1000, 10, 1000));
    //saver.setPerspectiveData(fov, aspect, zNear, zFar);
    
    saver.begin();
    ofSetCircleResolution(100);
    ofNoFill();
    ofSetColor(255,255,255,255);
    ofDrawCircle(200,200,ofRandom(10,200));
    ofDrawCircle(200,200,ofRandom(10,200));
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255),150);
    ofDrawCircle(150,150,ofRandom(50,150));
    ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255),150);
    ofDrawCircle(250,150,ofRandom(50,150));
    ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255),150);
    ofDrawCircle(200,250,ofRandom(50,150));
    ofDisableAlphaBlending();
    saver.end();
    
    ofSetColor(255,255,255,255);
    ofDrawBitmapString("press s to save an image",20,20);
    ofDrawBitmapString("press r to randomize",20,30);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    //fileName (supports all image types ofImage does), flipY?
    if(key=='s') saver.finish("frame_" + ofToString(ofGetFrameNum()) + "_high.png", true);
    if(key=='r') {r = ofRandom(0,100); }
    
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
void ofApp::windowResized(int w, int h){
    
}

