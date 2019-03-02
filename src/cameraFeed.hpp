//
//  cameraFeed.hpp
//  StereoVideoTracking
//
//  Created by Ben Lucas on 2/24/19.
//

#ifndef cameraFeed_hpp
#define cameraFeed_hpp

#include <stdio.h>
#include "ofMain.h"
#include "BlipDetector.hpp"

class CameraFeed
{
public:
    CameraFeed(){
        camWidth = 640;
        camHeight = 380;
    }
    
    void SetupCamera(int deviceID, int frameRate, int width, int height);
    
    bool UpdateCamera();
    
    void DrawVideo();
    
    bool DetectBlip();
    
    void InitializeDetector();
    
    double GetBlipAngle();
    
private:
    BlipDetector detector;
    
    ofVideoGrabber vidGrabber;
    ofPixels videoPixels;
    ofTexture videoTexture;
    
    int camWidth;
    int camHeight;
    int centerStripInd;
};



#endif /* cameraFeed_hpp */
