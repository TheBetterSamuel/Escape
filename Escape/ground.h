
#ifndef _GROUND_H               // Prevent multiple definitions if this 
#define _GROUND_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace groundNS
{
    const int   WIDTH = 128;                // image width
    const int   HEIGHT = 128;               // image height
    const int COLLISION_DIST = (BOX_SIZE / 2) + 2; // Distance from center of player to edge of player, with 2 pixels of leeway
    const int   X = GAME_WIDTH / 2 - WIDTH / 2; // location on screen
    const int   Y = GAME_HEIGHT / 2 - HEIGHT / 2;
    const float MASS = 1.0e14f;         // mass
    const int   TEXTURE_COLS = 2;       // texture has 2 columns
    const int   START_FRAME = 1;        // starts at frame 1
    const int   END_FRAME = 1;          // no animation
}

class Ground : public Entity            // inherits from Entity class
{
public:
    // constructor
    Ground();
};
#endif

