#pragma once

#include "ofMain.h"
#include "cameraFeed.hpp"
#include "HitPoint.hpp"
#include "TargetImage.hpp"
#include "StereoBlipPosition.hpp"

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
    
    private:
        int cam1Width = 640;
        int cam1Height = 480;
        CameraFeed cam1;
        CameraFeed cam2;
        StereoBlipPosition StereoPosition;
        HitPoint hit;
        TargetImage target;
    
        double blipAngle1 = 0;
        double blipAngle2 = 0;
        bool blipDetected = false;
    
};
