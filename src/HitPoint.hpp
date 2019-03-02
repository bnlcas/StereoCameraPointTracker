//
//  hitPoint.hpp
//  StereoVideoTracking
//
//  Created by Ben Lucas on 2/23/19.
//

#ifndef hitPoint_hpp
#define hitPoint_hpp

#include <stdio.h>
#include <math.h>
#include "ofMain.h"

class HitPoint{
public:
    HitPoint(){
        renderHit = false;
        xCoord = 0.0;
        yCoord = 0.0;
    }
    
    void PositionHit(double angle1, double angle2);
    
    void DrawHit();
    
    bool renderHit = false;
    double xCoord = 0.0;
    double yCoord = 0.0;
    
private:
    const double SMOOTHING = 0.95;
    const double HIT_RADIUS = 20;
    
    double SmoothCoord(double priorVal, double newVal);
};

#endif /* hitPoint_hpp */
