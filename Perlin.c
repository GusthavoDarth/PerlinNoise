#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "functions.h"

const int screenWidth = 800;
const int screenHeight = 800;

    

int main()
{
    int squareSize = 40;
    int gridHeight = (screenHeight/squareSize) +1;
    int gridWidth = (screenWidth/squareSize) +1;

    int** screen = initMatrix(gridHeight,gridWidth);
    InitWindow(screenWidth, screenHeight, "Perlin");
    SetTargetFPS(60);
     while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(GRAY);
            
            for(int px = 0; px < screenWidth; px++)
            {
                int x = px/squareSize;
                if (x >= gridWidth-1){x = gridWidth-2;}
                float fx = (px % squareSize) / (float)squareSize;

                for(int py = 0; py < screenHeight; py++)
                {
                    int y = py/squareSize;
                    if (y >= gridWidth-1){y = gridWidth-2;}
                    float fy = (py % squareSize) / (float)squareSize;

                    float top = lerp(screen[y][x],screen[y][x+1],fx);
                    float bottom = lerp(screen[y+1][x],screen[y+1][x+1],fx);
                    float total = lerp(top,bottom,fy);

                    DrawPixel(px, py, (Color){total,total,total,255});
                }
            }

            DrawText(TextFormat("Size: %d",squareSize),10,10,20, BLUE);
        EndDrawing();

        if(IsKeyPressed(KEY_SPACE)){
            freeMatrix(screen, gridHeight);
            screen = initMatrix(gridHeight,gridWidth);
        }
        if(IsKeyPressed(KEY_UP)){
            if(squareSize < 40)
            {
                int oldGridHeight = gridHeight;

                squareSize += 1;
                gridHeight = (screenHeight/squareSize) +1;
                gridWidth = (screenWidth/squareSize) +1;
                freeMatrix(screen, oldGridHeight);
                screen = initMatrix(gridHeight, gridWidth);
            }
        }
        if(IsKeyPressed(KEY_DOWN)){
            if(squareSize > 1)
            {
                int oldGridHeight = gridHeight;

                squareSize -= 1;
                freeMatrix(screen, gridHeight);
                gridHeight = (screenHeight/squareSize) +1;
                gridWidth = (screenWidth/squareSize) +1;
                screen = initMatrix(gridHeight, oldGridHeight);
            }    
        }
    }
}