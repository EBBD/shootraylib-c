#include "raylib.h"

int main(void){
  const int screenWidth = 450;
  const int screenHeight = 800;
  int i = 0;
  int j = 0;
  int lockout = 0;
  int playerShots[5];
  float shotPos[5][2];
  int shotHolder = 0;

  InitWindow(screenWidth, screenHeight, "shootGame");
  Vector2 shipPosition = { (float)screenWidth/2, (float)screenHeight/2 };

  SetTargetFPS(60);
  
   while (!WindowShouldClose()){
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
     }
     else{
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
	  playerShots[shotHolder] = 1;
	  shotPos[shotHolder][0] = shipPosition.x;
	  shotPos[shotHolder][1] = shipPosition.y - 10.0f;
	  if (playerShots[0] == 0){
	shotHolder = 0;
	  }
else if (playerShots[1] == 0){
	shotHolder = 1;
	  }
else if (playerShots[2] == 0){
	shotHolder = 2;
	  }
else if (playerShots[3] == 0){
	shotHolder = 3;
	  }
else if (playerShots[4] == 0){
	shotHolder = 4;
	  }

	}
      }
   }
     if (i == 0){
     BeginDrawing();
            ClearBackground(BLACK);

            DrawText("move the ball with wasd", 10, 10, 20, WHITE);

            DrawCircleV(shipPosition, 25, MAROON);
	    
	    while (playerShots[j] != 0){
		    DrawRectangle((int)shotPos[j][0], (int)shotPos[j][1], 10, 10, YELLOW);
		    shotPos[j][1] -= 5.0f;
		    if(shotPos[j][1] <= 0.0f){
			    playerShots[j] = 0;
			    shotHolder = j;
			    
		    }
		    j++;
	    }
            j = 0;        
     EndDrawing();
       i++;
     }
     else{
       i = 0;
     }
   }  
     
     CloseWindow();
  
    return 0;
}
