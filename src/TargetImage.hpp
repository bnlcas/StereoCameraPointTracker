//
//  targetImage.hpp
//  StereoVideoTracking
//
//  Created by Ben Lucas on 2/23/19.
//

#ifndef targetImage_hpp
#define targetImage_hpp

#include <stdio.h>
#include "ofMain.h"
#include <math.h>


class TargetImage{
public:
    TargetImage(){
        isHit = false;
        position_x = 0;
        position_y = 0;
    }
    
    void LoadImages();
    
    void MoveTarget(double x, double y);
    
    void CheckHit(double hit_x, double hit_y);
    
    void RenderTarget();
    
    
private:
    ofImage targetMissImage;
    ofImage targetHitImage;
    ofImage targetHitStrobe;
    bool isHit = false;
    double position_x;
    double position_y;
    
    //Strobe Effect?
    int strobeCount = 0;
    int strobeSwitchFrames = 10;
    bool ToggleStrobe();
    
    const double WIDTH = 300;
    const double HEIGHT = 300;
};


#endif /* targetImage_hpp */
