#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Set up screen
    ofSetWindowPosition(100, 10);//Use this to push window off to another screen
    
    //Setup background Display:
    target.LoadImages();
    
    //Setup Video
    int frameRate = 30;
    int cam1ID = 2;
    int cam2ID = 2;
    
    cam1.SetupCamera(cam1ID, frameRate, cam1Width, cam1Height);
    
    //cam2.SetupCamera(cam2ID, frameRate, cam1Width, cam1Height);

    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100,100,100);
    
    if(cam1.UpdateCamera())
    {
        blipDetected = cam1.DetectBlip();// && cam2.DetectBlip();
        
        hit.renderHit = blipDetected;
        if(blipDetected)
        {
            blipAngle1 = cam1.GetBlipAngle();
            blipAngle2 = cam2.GetBlipAngle();
            StereoPosition.FindBlipPosition(blipAngle1, blipAngle2);
            //hit.positionHit(StereoPosition.blipX, StereoPosition.blipY);
            // change to blipX, blipY
            //StereoPosition
            hit.PositionHit(blipAngle1, 300);
        }
        target.MoveTarget(ofGetMouseX(), ofGetMouseY());
        target.CheckHit(hit.xCoord, hit.yCoord);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapStringHighlight("Everything works!", 20, 20);
    ofSetHexColor(0xffffff);
    //vidGrabber.draw(20,20);
    cam1.DrawVideo();
    target.RenderTarget();
    hit.DrawHit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //ofLogNotice() << blipAngle;
    cam1.InitializeDetector();
    //detector.initializeDetector();
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
