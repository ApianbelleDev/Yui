#include "engine.h"
#include "player.h"

//variable definitions
int tilemapWidth =  10;
int tilemapHeight =  9;
int* tilemap;

RenderTexture2D target;
float scale;

//struct definitions
struct Entity {
	int   x, y;
	int vx, vy;
	int   w, h;
	int  speed; 
};
int getTile(int x, int y){
	return tilemap[x + y * tilemapWidth];	
}

void setTile(int x,int y,int type){
	tilemap[x + y * tilemapWidth] = type;
}

int randRange(int l, int h){
	return(rand() % (h - l + 1)) + l;
}

void init(){
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

	tilemap = calloc(1, sizeof(int) * tilemapWidth * tilemapHeight);

	SetTargetFPS(60);
}

void update(){
	scale = MIN((float)GetScreenWidth()/SCREEN_WIDTH, (float)GetScreenHeight()/SCREEN_HEIGHT);
	updatePlayer();
}

