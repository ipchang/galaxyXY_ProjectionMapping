#pragma once

#include "ofMain.h"
#include "ofxBezierWarpManager.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxBezierWarpManager warpManager;
    bool showWarpGuide;
    
    ofFbo first_fbo;
    ofFbo second_fbo;
    ofFbo third_fbo;
    
    ofImage starfieldBackgroundImage;
    
    ofPoint point;
    
    int mousePositionX, mousePositionY;
    
    int img_1_PositionX, img_1_PositionY;
    int img_2_PositionX, img_2_PositionY;
    int img_3_PositionX, img_3_PositionY;
    
    int mouseCurrentPositionX;
    int xPos, dX;
    
};
