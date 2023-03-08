#include "raylib.h"

void updateShots(int ps[5], float xy[5][2]){
	for(int i=0; i < 5; i++){
		if(xy[i][1] < 0){
			ps[i] = 0;
		}else{
			xy[i][1] -= 5.0f;
		}
	}
}

void drawShots(int ps[5], float xy[5][2]){
	for(int i=0; i < 5; i++){
		if(ps[i] != 0){
			DrawRectangle((int)xy[i][0], (int)xy[i][1], 10, 10, YELLOW);
		}
	}
}

void fire(int ps[5], float xy[5][2], float sX, float sY){
	for(int i=0; i < 5; i++){
		if(ps[i] == 0){
			ps[i] = 1;
			xy[i][0] = sX;
			xy[i][1] = sY - 10.0f;
			return;
		}
	}
}

void bombDash (int dashTrack, int lrud, float sX, float sY){
	if (dashTrack == 30){
	}
	if (lrud == 0){
		sY -= 10.0f;
		return;
	}
	
}

int main(void){
  const int screenWidth = 450;
  const int screenHeight = 800;
  int DashWASD = 0;
  int i = 0;
  int dashCount = 0;

  int lockout = 0;
  int playerShots[5] = {0,0,0,0,0};
  float shotPos[5][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
  int shotHolder = 0;

  InitWindow(screenWidth, screenHeight, "shootGame");
  Vector2 shipPosition = { (float)screenWidth/2, (float)screenHeight/2 };

  SetTargetFPS(60);
  
   while (!WindowShouldClose()){
	updateShots(playerShots, shotPos);
     if (shipPosition.x < 25){
       shipPosition.x = 25;
     }
     else if (shipPosition.x > 425){
       shipPosition.x = 425;
     }
     else if (shipPosition.y < 25){
       shipPosition.y = 25;
     }
     else if (shipPosition.y > 775){
       shipPosition.y = 775;
     }else{
      if (lockout == 0){
        if (IsKeyDown(KEY_D)){
          shipPosition.x += 2.0f;
        }
        if (IsKeyDown(KEY_A)) {
          shipPosition.x -= 2.0f;
        }
        if (IsKeyDown(KEY_S)) {
          shipPosition.y += 2.0f;
        }
        if (IsKeyDown(KEY_W)) {
          shipPosition.y -= 2.0f;
        }
	if (IsKeyPressed(KEY_SPACE) && shotHolder < 5) {
		fire(playerShots, shotPos, shipPosition.x, shipPosition.y);
	}
}

    if (IsKeyPressed(KEY_ENTER)){
	if (lockout = 0){
		if (IsKeyPressed(KEY_UP)){
			DashWASD = 0;
		} 
		else if (IsKeyPressed(KEY_S)){
			DashWASD = 1;
		}
		else if (IsKeyPressed(KEY_A)){
			DashWASD = 2;
		}
		else if (IsKeyPressed(KEY_D)){
			DashWASD = 3;
		}
		else{
			DashWASD = 0;
		}
	}
	lockout = 1;
	if (dashCount == 0){
		dashCount = 30;
	}
	else{
		bombDash(dashCount, DashWASD, shipPosition.x, shipPosition.y);
	}
	
}
   }
     if (i == 0){
     BeginDrawing();
            ClearBackground(BLACK);

            DrawText("move the ball with wasd", 10, 10, 20, WHITE);

            DrawCircleV(shipPosition, 25, MAROON);

		drawShots(playerShots, shotPos);
                 
     EndDrawing();
       i++;
       if (dashCount > 0){
	dashCount--;
	}
       else {
	lockout = 0;
	}
     }
     else{
       i = 0;
     }
   }  
     
     CloseWindow();
  
    return 0;
}
