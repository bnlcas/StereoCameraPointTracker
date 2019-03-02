//
//  StereoBlipPosition.hpp
//  StereoVideoTracking
//
//  Created by Ben Lucas on 2/25/19.
//

#ifndef StereoBlipPosition_hpp
#define StereoBlipPosition_hpp
#define DEG2RAD 0.0174532925

#include <stdio.h>
#include <math.h>

class StereoBlipPosition
{
public:
    StereoBlipPosition()
    {
        baseLine = 20;
        angle_cam1 = 60;
        angle_cam2 = 60;
    }
    
    void FindBlipPosition(double angle1, double angle2)
    {
        double theta1 = angle_cam1 + angle1;
        double theta2 = angle_cam2 + angle2;
        double theta3 = 180 - (theta1 + theta2);
        //Law of Sines to get angle 1's hypotenuse
        double hypot1 = sin(theta1 * DEG2RAD) * (baseLine / sin(theta3 * DEG2RAD));
        blipX = hypot1 * cos(theta1 * DEG2RAD);
        blipY = hypot1 * sin(theta1 * DEG2RAD);
    }
    
    double blipX;
    
    double blipY;
    
private:
    double baseLine;
    double angle_cam1;
    double angle_cam2;
};

#endif /* StereoBlipPosition_hpp */
