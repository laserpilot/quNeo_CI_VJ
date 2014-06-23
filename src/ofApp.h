#pragma once

#include "ofMain.h"
#include "ofxQuNeo.h"
#include "ofxCoreImage.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
   // void setupFilters();
    
    ofVideoGrabber cam;
    bool camEnable;
    
    int filterNum;
    
    ofxCI coreBase;
    ofxCIBlur blurFilter;
    ofxCIHue hueFilter;
      ofxCIHexagonalPixellate hexFilter;
    ofxCIBumpDistortion pinchFilter;
    ofxCIExposureAdjust exposureFilter;
    ofxCIPointillize pointyFilter;
    ofxCIZoomBlur zoomFilter;
    
      ofFbo sourceFbo;
    
    ofxQuNeo quNeo;
    
    
		
};
