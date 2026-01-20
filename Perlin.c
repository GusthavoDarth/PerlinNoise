#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "functions.h"

const int screenWidth = 800;
const int screenHeight = 800;

int main()
{ 
    DisplayMode currentMode = MODE_NORMAL;
    int pointSize = 80;
    int gridHeight = (screenHeight/pointSize) +1;
    int gridWidth = (screenWidth/pointSize) +1;
    floatMatrix grid = perlinGrid(gridHeight,gridWidth);
    floatMatrix screen = createFloatMatrix((grid.rows*pointSize)-pointSize,(grid.cols*pointSize)-pointSize);

    InitWindow(screenWidth, screenHeight, "Perlin");
    SetTargetFPS(60);
     while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(GRAY);

            perlinNoise(grid, screen, pointSize, currentMode);

        EndDrawing();

        if(IsKeyPressed(KEY_SPACE))
        {
            
            gridHeight = (screenHeight/pointSize) +1;
            gridWidth = (screenWidth/pointSize) +1;
            grid = perlinGrid(gridHeight, gridWidth);
            screen = createFloatMatrix((grid.rows*pointSize)-pointSize,(grid.cols*pointSize)-pointSize);
        }
        if(IsKeyPressed(KEY_DOWN)){
            if(pointSize > 1){
                pointSize -=1;
                gridHeight = (screenHeight/pointSize) +1;
                gridWidth = (screenWidth/pointSize) +1;
                grid = perlinGrid(gridHeight,gridWidth);
                screen = createFloatMatrix((grid.rows*pointSize)-pointSize,(grid.cols*pointSize)-pointSize);
            }
        }
        if(IsKeyPressed(KEY_UP)){
            if(pointSize < 100){
                pointSize +=1;
                gridHeight = (screenHeight/pointSize) +1;
                gridWidth = (screenWidth/pointSize) +1;
                grid = perlinGrid(gridHeight,gridWidth);
                screen = createFloatMatrix((grid.rows*pointSize)-pointSize,(grid.cols*pointSize)-pointSize);
            }
        }

        if (IsKeyPressed(KEY_ONE)) currentMode = MODE_NORMAL;
        if (IsKeyPressed(KEY_TWO)) currentMode = MODE_COLOR;
    }
}