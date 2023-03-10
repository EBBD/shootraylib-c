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
			xy[i][1] = sY - 15.0f;
			return;
		}
	}
}

void bombDash (int dashTrack, int lrud, float* sX, float* sY, int bombOut, int bombPosX, int bombPosY, int bombTimer){
	if (dashTrack == 15){
	}
	if (lrud == 0 && dashTrack != 0){
		*sY -= 5.0f;
	}
	if (bombOut == 1){
		if (bombTimer == 36 || bombTimer == 30 || bombTimer == 24 || bombTimer == 18 || bombTimer == 12){
			DrawCircle(bombPosX, bombPosY, 15, RED);
		} 
		else if (bombTimer <= 6 && bombTimer > 1){
			DrawCircle(bombPosX, bombPosY, 50, RED);
			DrawCircle(bombPosX, bombPosY, 40, ORANGE);
		}
		else if (bombTimer >= 0 && bombTimer < 2){
			DrawCircle(bombPosX, bombPosY, 35, ORANGE);
		}
		else {
			DrawCircle(bombPosX, bombPosY, 15, GREEN);
		}
	}
	return;
}

int main(void){
  const int screenWidth = 450;
  const int screenHeight = 800;
  int DashWASD = 0;
  int i = 0;
  int bombExist = 0;
  int bombPosY = 0;
  int bombPosX = 0;
  int bombTimer = 0;
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
	if (lockout == 0){
		DashWASD = 0;
		if (bombExist == 0){
			bombExist = 1; 
			bombPosY = shipPosition.y;
			bombPosX = shipPosition.x;
		}
	}
	lockout = 1;
	if (dashCount == 0){
		dashCount = 15;
	}
	if (bombTimer == 0){
		bombTimer = 66;
	}
	
}
   bombDash(dashCount, DashWASD, &shipPosition.x, &shipPosition.y, bombExist, bombPosX, bombPosY, bombTimer);
	
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
	if (bombTimer > 0){
	bombTimer--;
	}
	else {
	  bombExist = 0;
	}
     }
     else{
       i = 0;
     }
   }  
     
     CloseWindow();
  
    return 0;
}
