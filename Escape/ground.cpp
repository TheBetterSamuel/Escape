// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 version 1.0

#include "ground.h"

//=============================================================================
// default constructor
//=============================================================================
Ground::Ground() : Entity()
{
    spriteData.x = groundNS::X;              // location on screen
    spriteData.y = groundNS::Y;
    radius = groundNS::COLLISION_DIST;
    mass = groundNS::MASS;
    startFrame = groundNS::START_FRAME;    // first frame of ship animation
    endFrame = groundNS::END_FRAME;      // last frame of ship animation
    setCurrentFrame(startFrame);
}