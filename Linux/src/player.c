#include "engine.h"
#include "player.h"

	int px    = 0;
	int py    = 0;
	int vx   = 1;
	int vy   = 1;
	int pw    = TILE_SIZE;
	int ph    = TILE_SIZE;
	int moveCooldown = 0;

void updatePlayer(){
	if(moveCooldown <= 0){
			 	//up/down movement
			 	if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) || IsKeyDown(KEY_UP)){
			 		if(getTile(px, py - 1) == FLOOR){
			 			py--;
			 			moveCooldown = 10;
			 		}
			 	}
			 	else if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN) || IsKeyDown(KEY_DOWN)){
			 		if (getTile(px, py + 1) == FLOOR){
			 			py++;
			 			moveCooldown = 10;
			 		}
			 	}
			 	//left/right movement
			 	else if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT) || IsKeyDown(KEY_LEFT)){
			 		if (getTile(px - 1, py) == FLOOR){
			 			px--;
			 			moveCooldown = 10;
			 		}
			 	}
			 	else if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) || IsKeyDown(KEY_RIGHT)){
			 		if(getTile(px + 1, py) == FLOOR){
			 			moveCooldown = 10;
						px++;
			 		}
			 	} 
			 }   else {
			 		moveCooldown--;
				}
				
			 
}
