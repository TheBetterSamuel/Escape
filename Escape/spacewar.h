// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 spacewar.h v1.0

#ifndef _SPACEWAR_H             // Prevent multiple definitions if this 
#define _SPACEWAR_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <vector>
#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "player.h"
#include "ground.h"
#include "killbox.h"
#include "finishbox.h"

//=============================================================================
// This class is the core of the game
//=============================================================================
class Spacewar : public Game
{
private:
    // game items
    TextureManager playerTexture;
    TextureManager killboxTexture;
    TextureManager finishboxTexture;
    TextureManager groundTexture;
    Player player;                           // the player
    Finishbox finishbox;                     // the finishbox
    std::vector<Ground> groundList;        // the ground
    std::vector<Killbox> kBoxList;        // the killbox
    std::vector<Player> playerList;        // the killbox
    std::vector<Finishbox> fBoxList;        // the killbox

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
