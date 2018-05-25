#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    starfieldBackgroundImage.load("starfield.jpg");
    
    //test 3d camera perspective
    //ofSetOrientation(OF_ORIENTATION_DEFAULT, false);
    camera.enableOrtho();
    
    first_fbo.allocate(1280, 800);
    second_fbo.allocate(1280, 800);
    third_fbo.allocate(1280, 800);
    
    
    warpManager.setup(10);
    warpManager.addFbo(&first_fbo);
    warpManager.addFbo(&second_fbo);
    warpManager.addFbo(&third_fbo);
    
    //Load settings from XML file
    warpManager.loadSettings();
    
    mousePositionX = 0;
    mousePositionY = 0;
    
    img_1_PositionX = 0;
    img_1_PositionY = 0;
    
    warpManager.toggleGuideVisible();
    
    xPos = 0;
    dX = 0;
    
    point.x = 0;
    point.y = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    mouseCurrentPositionX = ofGetMouseX();
    
    mousePositionX = ofGetMouseX();
    mousePositionY = ofGetMouseY();
    
    point.x = ofGetMouseX()/2;
    point.y = ofGetMouseY()/2 * -1;
    
    img_1_PositionX = mousePositionX - 2880;
    img_1_PositionY = mousePositionY - 200;
    
    img_2_PositionX = mousePositionX - 4160;
    img_2_PositionY = mousePositionY - 200;
    
    img_3_PositionX = mousePositionX - 5440;
    img_3_PositionY = mousePositionY - 200;
    
    dX = mousePositionX - xPos;
    xPos = xPos + (dX/10);
    
    mouseCurrentPositionX = mousePositionX - xPos;
    
    //cout << mouseCurrentPositionX << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofClear(0);
    
    first_fbo.begin();
    starfieldBackgroundImage.draw(img_1_PositionX, img_1_PositionY);
    starfieldBackgroundImage.draw(img_1_PositionX-9600, img_1_PositionY);
    camera.begin();
    ofDrawSphere(point, 100);
    camera.end();
    first_fbo.end();
    
    second_fbo.begin();
    starfieldBackgroundImage.draw(img_2_PositionX, img_2_PositionY);
    second_fbo.end();
    
    third_fbo.begin();
    starfieldBackgroundImage.draw(img_3_PositionX, img_3_PositionY);
    third_fbo.end();
    
    
    
    warpManager.draw();
    
    string _help = "[ENTER] key : Toggle guide visible.\n";
    _help += "[S] key : Save settings.\n";
    _help += "[L] key : Load settings.\n";
    _help += "Left drag the control point : Move Corners/Anchors.\n";
    _help += "Right click the control point : Toggle bezier/homoglaphy mode.\n";
    _help += "Arrow key : Move Corners/Anchors. (selected control point)\n";
    ofDrawBitmapString(_help, 10, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    warpManager.keyPressed(key);
    
    if (key == OF_KEY_RETURN) {
        warpManager.toggleGuideVisible();
    }
    
    if (key == 's') {
        warpManager.saveSettings();
    }
    
    if (key == 'l') {
        warpManager.loadSettings();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    warpManager.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    warpManager.mousePressed(x, y, button);
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
