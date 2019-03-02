//
//  targetImage.cpp
//  StereoVideoTracking
//
//  Created by Ben Lucas on 2/23/19.
//

#include "TargetImage.hpp"

void TargetImage::LoadImages(){
    targetHitStrobe.load("sprites/target_hit_strobe_img.png");
    targetHitImage.load("sprites/target_hit_img.png");
    targetMissImage.load("sprites/target_img.png");
}

void TargetImage::MoveTarget(double x, double y){
    position_x = x;
    position_y = y;
    //double SMOOTHING = 0.9;
    //position_x += (1-SMOOTHING) * ((double)ofRandom(1) - 0.5) + SMOOTHING * position_x;
    //position_x += (1 - SMOOTHING) * ((double)ofRandom(1) - 0.5) + SMOOTHING * position_y;
}

void TargetImage::CheckHit(double hit_x, double hit_y){
    bool hitX = (abs(hit_x - (position_x + WIDTH/2)) < WIDTH / 2);
    bool hitY = (abs(hit_y - (position_y + HEIGHT/2)) < HEIGHT / 2);
    isHit = hitX && hitY;
}

void TargetImage::RenderTarget(){
    if(isHit)
    {
        if(ToggleStrobe())
        {
            targetHitImage.draw(position_x,position_y, WIDTH, HEIGHT);
        }
        else
        {
            targetHitStrobe.draw(position_x, position_y, WIDTH, HEIGHT);
        }
    }
    else
    {
        targetMissImage.draw(position_x, position_y, WIDTH, HEIGHT);
    }
}


bool TargetImage::ToggleStrobe()
{
    strobeCount ++;
    return ((strobeCount / strobeSwitchFrames) % 2 == 0);
}

