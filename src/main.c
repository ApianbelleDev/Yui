//Engine headers
#include "engine.h"
#include "player.h"


//Main Function
int main(){

	init();

	SetTargetFPS(60);
	while(!WindowShouldClose()){
		//Game Loop
		update();

		BeginTextureMode(target);
			ClearBackground(BLACK);
			DrawRectangle(px * TILE_SIZE, py * TILE_SIZE, TILE_SIZE, TILE_SIZE, WHITE);
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
