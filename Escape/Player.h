// GPP Assignment 1


#ifndef _PLAYER_H                 // Prevent multiple definitions if this 
#define _PLAYER_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace playerNS
{
    const int WIDTH = 16;             // image width
    const int HEIGHT = 16;            // image height
    const float SPEED = MOVESPEED;          // Move based on move speed from constants.h
    const float SCALE = SPRITE_SCALE;       // Scaling up sprites to fit map
    const float G = entityNS::GRAVITY;      // Gravitional constant
    const int COLLISION_DIST = (BOX_SIZE / 4) - 2; // Distance from center of player to edge of player, with 2 pixels of leeway
    const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
    const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
    const float MASS = 3000.0f;              // mass
    const bool ONGROUND = true;
}

// inherits from Entity class
class Player : public Entity
{
private:
    bool onGround;

public:
    // constructor
    Player();

    // inherited member functions
    virtual void draw();
    virtual bool initialize(Game* gamePtr, int width, int height, int ncols, TextureManager* textureM);
    void update(float frameTime);

    // set and set onGround
    virtual bool getOnGround() const { return onGround; }
    virtual void setOnGround(bool onground) { onGround = onground; }

    //get and set velocity.x and velocity.y
    virtual float getVelX() const { return velocity.x; }
    virtual void setVelX(float VelX) { velocity.x = VelX; }
    virtual float getVelY() const { return velocity.y; }
    virtual void setVelY(float VelY) { velocity.y = VelY; }
};
#endif

