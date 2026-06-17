#include "raylib.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matrix.h"
#include "functions.h"

const int screenWidth = 800;
const int screenHeight = 800;

int main()
{
    srand(time(NULL));
    DisplayMode currentMode = MODE_NORMAL;
    int pointSize = 80;
    int gridHeight = (screenHeight/pointSize) +1;
    int gridWidth = (screenWidth/pointSize) +1;

    floatMatrix gradX = {0};
    floatMatrix gradY = {0};
    gradX = createFloatMatrix(gridHeight, gridWidth);
    gradY = createFloatMatrix(gridHeight, gridWidth);
    generateGradients(gradX, gradY);


    floatMatrix screen = {0};
    freeMatrix(screen);
    screen = createFloatMatrix((gradX.rows*pointSize)-pointSize, (gradX.cols*pointSize)-pointSize);

    InitWindow(screenWidth, screenHeight, "Perlin");
    SetTargetFPS(60);
     while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(GRAY);

            perlinNoise(gradX, gradY, screen, pointSize, currentMode);

        EndDrawing();

        if(IsKeyPressed(KEY_SPACE))
        {

            gridHeight = (screenHeight/pointSize) +1;
            gridWidth = (screenWidth/pointSize) +1;
            freeMatrix(gradX);
            freeMatrix(gradY);
            freeMatrix(screen);
            gradX = createFloatMatrix(gridHeight, gridWidth);
            gradY = createFloatMatrix(gridHeight, gridWidth);
            generateGradients(gradX, gradY);
            screen = createFloatMatrix((gradX.rows*pointSize)-pointSize, (gradX.cols*pointSize)-pointSize);
        }
        if(IsKeyPressed(KEY_DOWN)){
            if(pointSize > 1){
                pointSize -=1;
                gridHeight = (screenHeight/pointSize) +1;
                gridWidth = (screenWidth/pointSize) +1;
                freeMatrix(gradX);
                freeMatrix(gradY);
                freeMatrix(screen);
                gradX = createFloatMatrix(gridHeight, gridWidth);
                gradY = createFloatMatrix(gridHeight, gridWidth);
                generateGradients(gradX, gradY);
                screen = createFloatMatrix((gradX.rows*pointSize)-pointSize, (gradX.cols*pointSize)-pointSize);
            }
        }
        if(IsKeyPressed(KEY_UP)){
            if(pointSize < 100){
                pointSize +=1;
                gridHeight = (screenHeight/pointSize) +1;
                gridWidth = (screenWidth/pointSize) +1;
                freeMatrix(gradX);
                freeMatrix(gradY);
                freeMatrix(screen);
                gradX = createFloatMatrix(gridHeight, gridWidth);
                gradY = createFloatMatrix(gridHeight, gridWidth);
                generateGradients(gradX, gradY);
                screen = createFloatMatrix((gradX.rows*pointSize)-pointSize, (gradX.cols*pointSize)-pointSize);
            }
        }

        if(IsKeyPressed(KEY_ONE)) currentMode = MODE_NORMAL;
        if(IsKeyPressed(KEY_TWO)) currentMode = MODE_COLOR;
    }
     freeMatrix(gradX);
     freeMatrix(gradY);
     freeMatrix(screen);
     CloseWindow();
}
