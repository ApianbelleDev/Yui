#ifndef ENGINE_H
#define ENGINE_H
//standard headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//include raylib.h for the start and update functions
#include <raylib.h>

//Window Properties
#define SCREEN_WIDTH  160
#define SCREEN_HEIGHT 144
#define WINDOW_WIDTH  SCREEN_WIDTH  * 4
#define WINDOW_HEIGHT SCREEN_HEIGHT * 4
#define WINDOW_TITLE  "Yui"

//render texture for screen scaling
extern RenderTexture2D target;
extern float scale;

//World Properties(I.E, Tile Size, Tile Types, Flags, etc.)
#define TILE_SIZE      16

extern int tilemapWidth;
extern int tilemapHeight;
extern int* tilemap;

typedef enum {
	FLOOR,
	WALL,
	STAIR,
	SWITCH,
	KEY,
	BLOCK
}nextTile;

//engine functions and defines
#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

extern float dt;

extern int getTile(int x, int y);
extern int randRange(int l, int h);
extern void setTile(int x, int y, int type);

extern void init();
extern void update();
//struct declarations/game specific functions
typedef struct {
	int     x, y;
	int   vx, vy;
	int     w, h;
	int    speed;
	int   tx, ty;
}Entity;

#endif
