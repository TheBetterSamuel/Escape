// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "spaceWar.h"

//=============================================================================
// Constructor
//=============================================================================
Spacewar::Spacewar()
{}

//=============================================================================
// Destructor
//=============================================================================
Spacewar::~Spacewar()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Spacewar::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

    // main game textures
    if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player textures"));
    if (!groundTexture.initialize(graphics, GROUND_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ground textures"));
    if (!finishboxTexture.initialize(graphics, FINISHBOX_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing finishbox textures"));
    if (!killboxTexture.initialize(graphics, TEXTURES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing killbox textures"));

    // ground
    if (!ground.initialize(this, groundNS::WIDTH, groundNS::HEIGHT, 2, &groundTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ground"));
    ground.setX(0);
    ground.setY(GAME_HEIGHT - (BOX_SIZE));

    //player
    if (!player.initialize(this, playerNS::WIDTH, playerNS::HEIGHT, 0, &playerTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
    player.setX(0);
    player.setY(GAME_HEIGHT - (BOX_SIZE * 2));

    // killbox
    if (!killbox.initialize(this, killboxNS::WIDTH, killboxNS::HEIGHT, 2, &killboxTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing killbox"));
    killbox.setX(0);
    killbox.setY(GAME_HEIGHT - (BOX_SIZE) - 100);

    // finishbox
    if (!finishbox.initialize(this, finishboxNS::WIDTH, finishboxNS::HEIGHT, 2, &finishboxTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing finishbox"));
    finishbox.setX(0);
    finishbox.setY(GAME_HEIGHT - (BOX_SIZE) - 200);

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Spacewar::update()
{
    //check if player is inside the map
    if (player.getX() >= 0)
    {
        if (player.getX() <= (GAME_WIDTH - BOX_SIZE)) {
            // checks kep presses for movement left and right
            if (input->isKeyDown(A_KEY))            // if move right
            {
                player.setVelocity(VECTOR2(-playerNS::SPEED, 0));
            }
            else if (input->isKeyDown(D_KEY))            // if move right
            {
                player.setVelocity(VECTOR2(playerNS::SPEED, 0));
            }
            else {
                player.setVelocity(VECTOR2(0, 0));
            }
        }
        else {
            player.setX(GAME_WIDTH - BOX_SIZE - 2);
        }
    }
    else {
        player.setX(2);
    }

    ground.update(frameTime);
    player.update(frameTime);
    killbox.update(frameTime);
    finishbox.update(frameTime);
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Spacewar::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Spacewar::collisions()
{
}

//=============================================================================
// Render game items
//=============================================================================
void Spacewar::render()
{
    graphics->spriteBegin();                // begin drawing sprites

    ground.draw();
    player.draw();
    killbox.draw();
    finishbox.draw();

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Spacewar::releaseAll()
{
    groundTexture.onLostDevice();
    playerTexture.onLostDevice();
    killboxTexture.onLostDevice();
    finishboxTexture.onLostDevice();
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Spacewar::resetAll()
{
    groundTexture.onResetDevice();
    playerTexture.onResetDevice();
    killboxTexture.onResetDevice();
    finishboxTexture.onResetDevice();
    Game::resetAll();
    return;
}
