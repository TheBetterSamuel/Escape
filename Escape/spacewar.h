// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 spacewar.h v1.0

#ifndef _SPACEWAR_H             // Prevent multiple definitions if this 
#define _SPACEWAR_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "planet.h"
#include "ship.h"

//=============================================================================
// This class is the core of the game
//=============================================================================
class Spacewar : public Game
{
private:
    // game items
    TextureManager gameTextures;    // game texture
    //sprite texture Manager
    TextureManager playerTexture;
    TextureManager killboxTexture;
    TextureManager finishboxTexture;
    TextureManager groundTexture;
    Ship    ship1, ship2;           // spaceships
    Planet  planet;         // the planet

public:
    // Constructor
    Spacewar();

    // Destructor
    virtual ~Spacewar();

    // Initialize the game
    void initialize(HWND hwnd);
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
};

#endif
