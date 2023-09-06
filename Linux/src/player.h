#ifndef PLAYER_H
#define PLAYER_H

#include "engine.h"

//function declarations
extern void updatePlayer();
extern void move(int x, int y);

//variable declarations
extern int   px, py;
extern int vx, vy;
extern int   pw, ph;
extern int tx, ty;
extern int moveCooldown;
#endif
