#include "raylib.h"

int main(void)
{
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "shootGame");
  Vector2 shipPosition = { (float)screenWidth/2, (float)screenHeight/2 };

  SetTargetFPS(60);
  
   while (!WindowShouldClose())
   {
     if (IsKeyDown(KEY_A)) ballPosition.x += 4.0f;
     if (IsKeyDown(KEY_D)) ballPosition.x -= 4.0f;
     if (IsKeyDown(KEY_S)) ballPosition.y += 4.0f;
     if (IsKeyDown(KEY_W)) ballPosition.y -= 4.0f;
     
     BeginDrawing();
            ClearBackground(RAYBLACK);

            DrawText("move the ball with arrow keys", 10, 10, 20, WHITE);

            DrawCircleV(ballPosition, 25, MAROON);

     EndDrawing();
   }
     
     CloseWindow();
  
    return 0;
}
