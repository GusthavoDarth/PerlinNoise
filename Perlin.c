#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "functions.h"

const int screenWidth = 800;
const int screenHeight = 400;

int main()
{ 
    DisplayMode currentMode = MODE_NORMAL;
    int squareSize = 40;
    int gridHeight = (screenHeight/squareSize) +1;
    int gridWidth = (screenWidth/squareSize) +1;
    int** screen = initMatrix(gridWidth, gridHeight);

    InitWindow(screenWidth, screenHeight, "Perlin");
    SetTargetFPS(60);
     while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(GRAY);
            
            drawPerlin(currentMode, screenWidth, screenHeight, gridWidth, gridHeight, squareSize, screen);

            DrawText(TextFormat("Size: %d",gridHeight),10,10,20, BLUE);
        EndDrawing();

        if(IsKeyPressed(KEY_SPACE)){
            freeMatrix(screen, gridWidth);
            screen = initMatrix(gridWidth, gridHeight);
        }
        if(IsKeyPressed(KEY_UP)){
            if(squareSize < 80)
            {
                int oldGridWidth = gridWidth;

                squareSize += 1;
                gridHeight = (screenHeight/squareSize) +1;
                gridWidth = (screenWidth/squareSize) +1;
                freeMatrix(screen, oldGridWidth);
                screen = initMatrix(gridWidth, gridHeight);
            }
        }
        if(IsKeyPressed(KEY_DOWN)){
            if(squareSize > 1)
            {
                int oldGridWidth = gridWidth;

                squareSize -= 1;
                gridHeight = (screenHeight/squareSize) +1;
                gridWidth = (screenWidth/squareSize) +1;
                freeMatrix(screen, oldGridWidth);
                screen = initMatrix(gridWidth, gridHeight);
            }    
        }

        if (IsKeyPressed(KEY_ONE)) currentMode = MODE_NORMAL;
        if (IsKeyPressed(KEY_TWO)) currentMode = MODE_COLOR;
    }
    freeMatrix(screen, gridWidth);
}