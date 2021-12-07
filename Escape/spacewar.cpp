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
    if (!gameTextures.initialize(graphics,TEXTURES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

    if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player textures"));
    if (!groundTexture.initialize(graphics, GROUND_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ground textures"));
    if (!finishboxTexture.initialize(graphics, FINISHBOX_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing finishbox textures"));
    if (!killboxTexture.initialize(graphics, TEXTURES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing killbox textures"));

    // planet
    if (!planet.initialize(this, planetNS::WIDTH, planetNS::HEIGHT, 2, &gameTextures))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing planet"));

    //player
    if (!player.initialize(this, playerNS::WIDTH, playerNS::HEIGHT, 0, &playerTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
    player.setX(GAME_WIDTH / 4);
    player.setY(GAME_HEIGHT / 4);

    // ship
    if (!ship1.initialize(this, shipNS::WIDTH, shipNS::HEIGHT, shipNS::TEXTURE_COLS, &gameTextures))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship1"));
    ship1.setFrames(shipNS::SHIP1_START_FRAME, shipNS::SHIP1_END_FRAME);
    ship1.setCurrentFrame(shipNS::SHIP1_START_FRAME);
    ship1.setX(GAME_WIDTH/4);
    ship1.setY(GAME_HEIGHT/4);
    ship1.setVelocity(VECTOR2(shipNS::SPEED,-shipNS::SPEED)); // VECTOR2(X, Y)
    // ship2
    if (!ship2.initialize(this, shipNS::WIDTH, shipNS::HEIGHT, shipNS::TEXTURE_COLS, &gameTextures))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship2"));
    ship2.setFrames(shipNS::SHIP2_START_FRAME, shipNS::SHIP2_END_FRAME);
    ship2.setCurrentFrame(shipNS::SHIP2_START_FRAME);
    ship2.setX(GAME_WIDTH - GAME_WIDTH/4);
    ship2.setY(GAME_HEIGHT/4);
    ship2.setVelocity(VECTOR2(-shipNS::SPEED,-shipNS::SPEED)); // VECTOR2(X, Y)

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Spacewar::update()
{

    // checks kep presses for movement left and right
    if (input->isKeyDown(0x41)) {
        player.setVelocity(VECTOR2(-playerNS::SPEED, 0));
    }
    if (input->isKeyDown(0x44)) {
        player.setVelocity(VECTOR2(playerNS::SPEED, 0));
    }

    planet.update(frameTime);
    ship1.update(frameTime);
    ship2.update(frameTime);
    player.update(frameTime);
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
    VECTOR2 collisionVector;
    // if collision between ship and planet
    if(ship1.collidesWith(planet, collisionVector))
    {
        // bounce off planet
        ship1.bounce(collisionVector, planet);
        ship1.damage(PLANET);
    }
    if(ship2.collidesWith(planet, collisionVector))
    {
        // bounce off planet
        ship2.bounce(collisionVector, planet);
        ship2.damage(PLANET);
    }
    // if collision between ships
    if(ship1.collidesWith(ship2, collisionVector))
    {
        // bounce off ship
        ship1.bounce(collisionVector, ship2);
        ship1.damage(SHIP);
        // change the direction of the collisionVector for ship2
        ship2.bounce(collisionVector*-1, ship1);
        ship2.damage(SHIP);
    }
}

//=============================================================================
// Render game items
//=============================================================================
void Spacewar::render()
{
    graphics->spriteBegin();                // begin drawing sprites

    planet.draw();                          // add the planet to the scene
    ship1.draw();                           // add the spaceship to the scene
    ship2.draw();                           // add the spaceship to the scene
    player.draw();

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Spacewar::releaseAll()
{
    gameTextures.onLostDevice();
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Spacewar::resetAll()
{
    gameTextures.onResetDevice();
    Game::resetAll();
    return;
}
