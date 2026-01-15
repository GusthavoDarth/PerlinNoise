#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>



const int screenWidth = 800;
const int screenHeight = 800;
const int margin = 100;
const int squareSize = 10;
const int maxCols = (screenHeight/squareSize)+1;
const int maxRows = (screenWidth/squareSize)+1;
const int matrixSize = (screenWidth/squareSize)+1;
static Vector2 offset = { 0 };
typedef enum {
    MODE_NORMAL,
    MODE_COLOR,
    MODE_INVERTED
} DisplayMode;


int** initMatrix()
{
    int** matrix = malloc(sizeof(int*)*maxRows);
    for(int i = 0; i < maxRows; ++i){
		matrix[i] = malloc(sizeof(int)*maxCols);
	}
    for(int i = 0; i < maxRows; ++i){
		for(int j = 0; j < maxCols; ++j){
			matrix[i][j] = rand()%255;
		}
	}
	return matrix;
}


float lerp(float a, float b, float t)
{
return a + t * (b - a);
}




int main()
{
    int** screen = initMatrix();
    InitWindow(screenWidth, screenHeight, "quadriculado");
    SetTargetFPS(60);
    DisplayMode currentMode = MODE_NORMAL;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            for(int col = 0; col < maxCols-1; ++col)
            {
                for(int row = 0; row < maxRows-1; ++row)
                {    
                     for(int px = 0; px < squareSize; px++){
                        for(int py = 0; py < squareSize; py++){

                            float x = (1/(float)squareSize)*px; // x in 0,1)
                            float y = (1/(float)squareSize)*py; // y in 0,1)

                            // Bilinear interpolation
                            float top = lerp(screen[row][col], screen[row+1][col], x);
                            float bottom = lerp(screen[row][col+1], screen[row+1][col+1], x);
                            float value = lerp(top, bottom, y);

                            int colorValue = (int)value;
                            if(colorValue < 0) colorValue = 0;
                            if(colorValue > 255) colorValue = 255;

                            
                            Color pixelColor; 
                            
                            switch(currentMode)
                            {
                                case MODE_NORMAL:
                                    pixelColor = (Color){(value),(value),(value),255};
                                    break;
                                case MODE_COLOR:
                                    float t = value / 255.0f;
                                    if (t < 0.2f) pixelColor = BLUE;        // Water/deep
                                    else if (t < 0.3f) pixelColor = SKYBLUE; // Shallow
                                    else if (t < 0.4f) pixelColor = YELLOW;  // Sand
                                    else if (t < 0.6f) pixelColor = GREEN;   // Grass
                                    else if (t < 0.8f) pixelColor = BROWN;   // Dirt/Mountains
                                    else pixelColor = WHITE; 
                                    break;
                                case MODE_INVERTED:
                                    pixelColor = (Color){(255-value),(255-value),(255-value),255};
                                    break;    
                            }

                                DrawRectangle(row*squareSize + px, col*squareSize + py,squareSize/squareSize, squareSize/squareSize, pixelColor);
                        

                        }       
                     }
                        
                     //DrawText(TextFormat("[%d,%d],%d",row,col, screen[row][col]),0*squareSize, 0*squareSize+(150*col+300*row), squareSize/6, BLUE);
                     
                }
            }
        EndDrawing();

        if(IsKeyPressed(KEY_SPACE)){
            screen = initMatrix();
        }
        if (IsKeyPressed(KEY_ONE)) currentMode = MODE_NORMAL;
        if (IsKeyPressed(KEY_TWO)) currentMode = MODE_COLOR;
        if (IsKeyPressed(KEY_THREE)) currentMode = MODE_INVERTED;
    }

    CloseWindow();

    return 0;
}
