#include "raylib.h"

int main(void){
  const int screenWidth = 450;
  const int screenHeight = 800;
  int i = 0;
  int lockout = 0;

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
      }
   }
     if (i == 0){
     BeginDrawing();
            ClearBackground(BLACK);

            DrawText("move the ball with wasd", 10, 10, 20, WHITE);

            DrawCircleV(shipPosition, 25, MAROON);

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
