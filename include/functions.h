#include <math.h>

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

void generateGradients(floatMatrix gradX, floatMatrix gradY)
{
    if (gradX.data == NULL || gradY.data == NULL) return;
    for (int i = 0; i < gradX.rows; i++)
    {
        for (int j = 0; j < gradX.cols; j++)
        {
            float angle = ((float)rand() / (float)RAND_MAX) * 2.0f * 3.14159265f;
            gradX.data[i][j] = cosf(angle);
            gradY.data[i][j] = sinf(angle);
        }
    }
}

void perlinNoise(floatMatrix gradX, floatMatrix gradY, floatMatrix screen, int pointSize, DisplayMode currentMode)
{
    if(gradX.data == NULL || gradY.data == NULL || screen.data == NULL) return;

    Color pixelColor;

    for(int i = 0; i < screen.rows; i++)
    {
        float fx = (float)i / (float)pointSize;
        int x0 = (int)fx;
        int x1 = x0 + 1;
        float fracX = fx - x0;
        float u = smoothstep(0.0f, 1.0f, fracX);

        for(int j = 0; j < screen.cols; j++)
        {
            float fy = (float)j / (float)pointSize;
            int y0 = (int)fy;
            int y1 = y0 + 1;
            float fracY = fy - y0;
            float v = smoothstep(0.0f, 1.0f, fracY);

            float n00 = gradX.data[x0][y0] * fracX       + gradY.data[x0][y0] * fracY;
            float n10 = gradX.data[x1][y0] * (fracX - 1) + gradY.data[x1][y0] * fracY;
            float n01 = gradX.data[x0][y1] * fracX       + gradY.data[x0][y1] * (fracY - 1);
            float n11 = gradX.data[x1][y1] * (fracX - 1) + gradY.data[x1][y1] * (fracY - 1);

            float top    = lerp(n00, n10, u);
            float bottom = lerp(n01, n11, u);
            float total  = lerp(top, bottom, v);

            float normalized = (total + 0.7071f) / (2.0f * 0.7071f);
            if(normalized < 0.0f) normalized = 0.0f;
            if(normalized > 1.0f) normalized = 1.0f;

            pixelColor = viewType(currentMode, normalized * 255.0f);
            DrawPixel(i, j, pixelColor);
        }
    }
}
