//Window Properties
#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160
#define WINDOW_WIDTH  SCREEN_WIDTH  * 3
#define WINDOW_HEIGHT SCREEN_HEIGHT * 3
#define WINDOW_TITLE  "Yui"

//World Properties(I.E, Tile size, Tile Types, flags, etc.)
#define TILE_SIZE 16

int tilemapWidth = 10;
int tilemapHeight = 20;
int* tilemap;

//Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Library headers
#include "raylib.h"

int getTile(int x, int y){
	return tilemap[x + y * tilemapWidth];
}

void setTile(int x, int y, int type){
	tilemap[x + y * tilemapWidth] = type;
}

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

//random function
//probably not gonna be used until later, but might as well implement it :3
int randRange(int l, int h){
	return (rand() % (h - l + 1)) + l;
}

//prototype player struct for testing
struct Player {
	int x, y;
	int tX, tY;
	int moveCooldown;
};

enum nextTile {
	FLOOR = 0
};



//Main Function
int main(){
	//Initialization
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	// Render texture initialization, used to hold the rendering result so we can easily resize it
	RenderTexture2D target = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

	struct Player player;
	player.x = 0;
	player.y = 0;
	player.moveCooldown = 0;

	tilemap = calloc(1, sizeof(int) * tilemapWidth * tilemapHeight);

	SetTargetFPS(60);
	while(!WindowShouldClose()){
		//Game Loop
		//Compute required framebuffer scaling
		float scale = MIN((float)GetScreenWidth()/SCREEN_WIDTH, (float)GetScreenHeight()/SCREEN_HEIGHT); 

		if(player.moveCooldown <= 0){
			//up/down movement
			if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) || IsKeyDown(KEY_UP)){
				if(getTile(player.x, player.y - 1) == FLOOR){
					player.y--;
					player.moveCooldown = 10;
				}
			}
			else if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN) || IsKeyDown(KEY_DOWN)){
				if (getTile(player.x, player.y + 1) == FLOOR){
					player.y++;
					player.moveCooldown = 10;
				}
			}
			//left/right movement
			else if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT) || IsKeyDown(KEY_LEFT)){
				if (getTile(player.x - 1, player.y) == FLOOR){
					player.x--;
					player.moveCooldown = 10;
				}
			}
			else if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) || IsKeyDown(KEY_RIGHT)){
				if(getTile(player.x + 1, player.y) == FLOOR){
					player.moveCooldown = 10;
					player.x++;
				}
			} 
		}   else {
				player.moveCooldown--;
			}

		BeginTextureMode(target);
			ClearBackground(BLACK);
			DrawRectangle(player.x * TILE_SIZE, player.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, WHITE);
		EndTextureMode();
		
		BeginDrawing();
			ClearBackground(BLACK);
			DrawTexturePro(target.texture, (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
                           (Rectangle){ (GetScreenWidth() - ((float)SCREEN_WIDTH*scale))*0.5f, (GetScreenHeight() - ((float)SCREEN_HEIGHT*scale))*0.5f,
                           (float)SCREEN_WIDTH*scale, (float)SCREEN_HEIGHT*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
		EndDrawing();
	}
	//Deinitialization
	CloseWindow();
}