#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    sourceFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); //32-bit framebuffer for smoothness
    sourceFbo.begin();
    ofClear(0);
    sourceFbo.end();
    
    //setupFilters();
    
    cam.initGrabber(640, 480);
    
    quNeo.setup();
    
    coreBase.setup();
    blurFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    hueFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    hexFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    pinchFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    exposureFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    pointyFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    zoomFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
    
}

//--------------------------------------------------------------
void ofApp::update(){
 
        cam.update();
    
    blurFilter.update(sourceFbo.getTextureReference());
    
    blurFilter.setRadius(ofMap(quNeo.getControlVals()[1],0,127, 0, 20));
    
    
    hueFilter.update(blurFilter.getCIImage());
    
    hueFilter.setAngle(ofMap(quNeo.getControlVals()[2],0,127, 0, PI));
    
    
    hexFilter.update(hueFilter.getCIImage());
    hexFilter.setScale(ofMap(quNeo.getControlVals()[3], 0, 127, 0, 30));
    hexFilter.setCenter(ofMap(quNeo.getControlVals()[21], 0, 127, 0, ofGetWidth()), ofMap(quNeo.getControlVals()[22], 127, 0, 0, ofGetHeight()));
    pinchFilter.update(hexFilter.getCIImage());
    pinchFilter.setRadius(ofMap(quNeo.getControlVals()[4], 0, 127,0,350));
    pinchFilter.setCenter(ofMap(quNeo.getControlVals()[23], 0, 127, 0, ofGetWidth()), ofMap(quNeo.getControlVals()[24], 127, 0, 0, ofGetHeight()));
    exposureFilter.update(pinchFilter.getCIImage());
    exposureFilter.setIntensity(ofMap(quNeo.getControlVals()[5], 0, 127, 0, 3));
    if(quNeo.getControlVals()[6]>0){
    pointyFilter.update(exposureFilter.getCIImage());
    pointyFilter.setRadius(ofMap(quNeo.getControlVals()[6], 0, 127, 0, 80));
    pointyFilter.setCenter(ofMap(quNeo.getControlVals()[27], 0, 127, 0, ofGetWidth()), ofMap(quNeo.getControlVals()[28], 127, 0, 0, ofGetHeight()));
    zoomFilter.update(pointyFilter.getCIImage());
        zoomFilter.setCenter(ofMap(quNeo.getControlVals()[29], 0, 127, 0, ofGetWidth()), ofMap(quNeo.getControlVals()[30], 127, 0, 0, ofGetHeight()));
    zoomFilter.setAmount(ofMap(quNeo.getControlVals()[7], 0, 127, 0, 30));
    }else{
        zoomFilter.update(exposureFilter.getCIImage());
        zoomFilter.setCenter(ofMap(quNeo.getControlVals()[29], 0, 127, 0, ofGetWidth()), ofMap(quNeo.getControlVals()[30], 127, 0, 0, ofGetHeight()));
        zoomFilter.setAmount(ofMap(quNeo.getControlVals()[7], 0, 127, 0, 20));

    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    sourceFbo.begin();
    ofClear(0,0,0,255); //can set this alpha to 0 to make the FBO transparent but your effects won't necessarily be seen
    ofSetColor(255);
    cam.draw(0,0,ofGetWidth(), ofGetHeight());
    sourceFbo.end();
    
    zoomFilter.draw(0, 0);
    
    quNeo.drawInterface(0,0);

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
