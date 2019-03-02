//
//  hitPoint.cpp
//  StereoVideoTracking
//
//  Created by Ben Lucas on 2/23/19.
//

#include "HitPoint.hpp"

void HitPoint::PositionHit(double angle1, double angle2)
{
    xCoord = HitPoint::SmoothCoord(xCoord, angle1);
    yCoord = angle2;
}

void HitPoint::DrawHit()
{
    if(renderHit)
    {
        ofDrawCircle(xCoord, yCoord, HIT_RADIUS);
    }
}

double HitPoint::SmoothCoord(double priorVal, double newVal){
    return SMOOTHING * priorVal + (1.0 - SMOOTHING) * newVal;
}
