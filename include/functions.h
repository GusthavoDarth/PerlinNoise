typedef enum {
    MODE_NORMAL,
    MODE_COLOR
} DisplayMode;

float lerp(float a, float b, float t)
{
return a + t * (b - a);
}


Color lerpColor(Color a, Color b, float t) {
    Color result;
    result.r = (unsigned char)(a.r + t * (b.r - a.r));
    result.g = (unsigned char)(a.g + t * (b.g - a.g));
    result.b = (unsigned char)(a.b + t * (b.b - a.b));
    result.a = (unsigned char)(a.a + t * (b.a - a.a));
    return result;
}

float smoothstep(float edge0, float edge1, float x) {
    // Scale, bias and saturate x to 0..1 range
    x = (x - edge0) / (edge1 - edge0);
    if(x < 0.0f) x = 0.0f;
    if(x > 1.0f) x = 1.0f;
    return x * x * (3 - 2 * x);  // Smooth polynomial
}

Color viewType(DisplayMode currentMode, float total)
{
    Color pixelColor;
    switch(currentMode)
    {
        case MODE_NORMAL:
        pixelColor = (Color){(total),(total),(total),255};
        break;
        case MODE_COLOR: {
            float t = total / 255.0f;
            // color definition by threshold value
            if(t < 0.2f) {
                float localT = smoothstep(0.0f, 0.2f, t);
                pixelColor = lerpColor(BLUE, SKYBLUE, localT);
            }
            else if(t < 0.3f) {
                float localT = smoothstep(0.2f, 0.3f, t);
                pixelColor = lerpColor(SKYBLUE, YELLOW, localT);
            }
            else if(t < 0.4f) {
                float localT = smoothstep(0.3f, 0.4f, t);
                pixelColor = lerpColor(YELLOW, GREEN, localT);
            }
            else if(t < 0.6f) {
                float localT = smoothstep(0.4f, 0.6f, t);
                pixelColor = lerpColor(GREEN, BROWN, localT);
            }
            else if(t < 0.8f) {
                float localT = smoothstep(0.6f, 0.8f, t);
                pixelColor = lerpColor(BROWN, WHITE, localT);
            }
            else {
                pixelColor = WHITE;
            }
            break;
        }
    }
    return pixelColor;
}

floatMatrix perlinGrid(int rows, int cols)
{
    floatMatrix matrix = createFloatMatrix(rows, cols);
    if(matrix.data == NULL) return matrix;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            matrix.data[i][j] = ((float)rand()/(float)(RAND_MAX));
        }
    }
    return matrix;
}

void perlinNoise(floatMatrix grid, floatMatrix screen, int pointSize, DisplayMode currentMode)
{
    if (grid.data == NULL || screen.data == NULL) return;

    Color pixelColor;
    int x0;
    int y0;
    int x1;
    int y1;

    float fx;
    float fy;

    float fracX;
    float fracY;
    float top;
    float bottom;
    float total;

    for(int i = 0; i < screen.rows; i++)
    {
        fx = (float)i / (float)pointSize;
        x0 = (int)fx;
        x1 = x0 + 1;
        fracX = fx - x0;

        for(int j = 0; j < screen.cols; j++)
        {
            fy = (float)j / (float)pointSize;
            y0 = (int)fy;
            y1 = y0 + 1;
            fracY = fy - y0;

            float top = lerp(grid.data[x0][y0],grid.data[x1][y0],fracX);
            float bottom = lerp(grid.data[x0][y1],grid.data[x1][y1],fracX);
            float total = lerp(top,bottom,fracY);

            pixelColor = viewType(currentMode, total*255);
            DrawPixel(i, j, pixelColor);
        }
    }
}
