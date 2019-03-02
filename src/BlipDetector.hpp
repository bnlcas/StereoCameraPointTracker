//
//  blipDetector.hpp
//  StereoVideoTracking
//
//  Created by Ben Lucas on 2/21/19.
//

#ifndef blipDetector_hpp
#define blipDetector_hpp

#include "ofMain.h"
#include <stdio.h>
#include <math.h>

class BlipDetector {
public:
    BlipDetector() {
        initialized = false;
        blipThresh = 25;
        blipInd = 0;
        cameraAngle = 45;
    }
    
    void InitializeDetector(ofPixels & px);
    
    bool FindBlip(ofPixels & px);
    
    double GetBlipAngle();
    
private:
    int blipInd;
    bool initialized;
    double blipThresh;
    double cameraAngle;
    std::vector<int> background;
};

#endif /* blipDetector_hpp */
