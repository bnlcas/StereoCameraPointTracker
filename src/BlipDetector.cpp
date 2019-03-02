//
//  blipDetector.cpp
//  StereoVideoTracking
//
//  Created by Ben Lucas on 2/21/19.
//

#include "BlipDetector.hpp"

void BlipDetector::InitializeDetector(ofPixels & px)
{
    //get the background and subtract it
    for(size_t i = 0; i < px.size(); i ++)
    {
        if(i < background.size())
        {
            background[i] = px[i];
        }
        else
        {
            background.push_back(px[i]);
        }
    }
    initialized = true;
}

bool BlipDetector::FindBlip(ofPixels & px) {
    //look for points with deviation above thresh from baseline
    if(!initialized)
    {
        InitializeDetector(px);
        return false;
    }
    else
    {
        blipInd = 0;
        double maxDiff = 0;
        bool exceedsThresh = false;
        for(int i = 0; i < px.size(); i ++)
        {
            double diff = abs(px[i] - background[i]);
            if(diff > maxDiff)
            {
                maxDiff = diff;
                blipInd = i;
            }
            if(!exceedsThresh && (maxDiff > blipThresh))
            {
                exceedsThresh = true;
            }
        }
        
        return exceedsThresh;
    }
}

double BlipDetector::GetBlipAngle() {
    return blipInd;//cameraAngle * ((double)(blipInd/background.size()) - 0.5);
    //return (double) blipInd;
}
