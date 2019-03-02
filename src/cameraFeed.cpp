//
//  cameraFeed.cpp
//  StereoVideoTracking
//
//  Created by Ben Lucas on 2/24/19.
//

#include "cameraFeed.hpp"

void CameraFeed::SetupCamera(int deviceID, int frameRate, int width, int height)
{
    //Find Cameras...
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    int deviceInd = 0;
    for(size_t i = 0; i < devices.size(); i ++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }
        else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable";
        }
        if(deviceID == 1 && devices[i].deviceName == "GENERAL - UVC")
        {
            deviceInd = i;
        }
        if(deviceID == 2 && devices[i].deviceName == "GENERAL - UVC  #2")
        {
            deviceInd = i;
        }
    }
    
    camWidth = width;
    camHeight = height;
    centerStripInd = camHeight * (camWidth/2);
    vidGrabber.setDeviceID(deviceInd);
    vidGrabber.setDesiredFrameRate(frameRate);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    videoPixels.allocate(camWidth, camHeight, OF_PIXELS_GRAY);
    videoTexture.allocate(videoPixels);
}

bool CameraFeed::UpdateCamera()
{
    vidGrabber.update();
    
    if(vidGrabber.isFrameNew()){
        ofPixels & pixels = vidGrabber.getPixels();
        
        for(int i = 0; i < (camWidth); i++){
            videoPixels[i] = pixels[centerStripInd + i];
        }
        videoTexture.loadData(videoPixels);
        return true;
    }
    else
    {
        return false;
    }
}

bool CameraFeed::DetectBlip()
{
    return detector.FindBlip(videoPixels);
}

void CameraFeed::DrawVideo()
{
    videoTexture.draw(2, 2, camWidth, camHeight);
}

void CameraFeed::InitializeDetector()
{
    detector.InitializeDetector(videoPixels);
}

double CameraFeed::GetBlipAngle()
{
    return detector.GetBlipAngle();
}
