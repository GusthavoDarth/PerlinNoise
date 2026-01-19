typedef enum {
    MODE_NORMAL,
    MODE_COLOR
} DisplayMode;

float lerp(float a, float b, float t)
{
return a + t * (b - a);
}

Color viewType(DisplayMode currentMode, float total)
{
    Color pixelColor;
    switch(currentMode)
    {
        case MODE_NORMAL:
        pixelColor = (Color){(total),(total),(total),255};
        break;
        
        case MODE_COLOR:                                    
        float t = total / 255.0f;
        if (t < 0.2f) pixelColor = BLUE;        // Water/deep
        else if (t < 0.3f) pixelColor = SKYBLUE; // Shallow
        else if (t < 0.4f) pixelColor = YELLOW;  // Sand
        else if (t < 0.6f) pixelColor = GREEN;   // Grass
        else if (t < 0.8f) pixelColor = BROWN;   // Dirt/Mountains
        else pixelColor = WHITE; 
        break;  
    }
    return pixelColor;
}

void drawPerlin(DisplayMode currentMode, int screenWidth, int screenHeight, int gridWidth, int gridHeight, int squareSize, int** matrix)
{
    Color pixelColor;
    
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

            float top = lerp(matrix[x][y],matrix[x+1][y],fx);
            float bottom = lerp(matrix[x][y+1],matrix[x+1][y+1],fx);
            float total = lerp(top,bottom,fy);

            pixelColor = viewType(currentMode, total);

            DrawPixel(px, py, pixelColor);
        }
    }
}