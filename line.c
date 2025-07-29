#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 120
#define HEIGHT 80
#define LINE_LENGTH 3.0f
#define SCALE 40

// Rotate a 3D point
void rotate(float in[3], float ax, float ay, float az, float out[3]) {
    float x = in[0], y = in[1], z = in[2];

    float cx = cosf(ax), sx = sinf(ax);
    float cy = cosf(ay), sy = sinf(ay);
    float cz = cosf(az), sz = sinf(az);

    float y1 = y * cx - z * sx;
    float z1 = y * sx + z * cx;

    float x2 = x * cy + z1 * sy;
    float z2 = -x * sy + z1 * cy;

    out[0] = x2 * cz - y1 * sz;
    out[1] = x2 * sz + y1 * cz;
    out[2] = z2;
}

// Draw a line on the buffer using Bresenham
void draw_line(char *buffer, int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT)
            buffer[y1 * WIDTH + x1] = ch;
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

int main() {
    float angleX = 0, angleY = 0, angleZ = 0;
    char buffer[WIDTH * HEIGHT + 1];
    buffer[WIDTH * HEIGHT] = '\0';

    printf("\x1b[2J"); // Clear screen

    while (1) {
        memset(buffer, ' ', WIDTH * HEIGHT);

        // Define line endpoints (from -L to +L in X axis)
        float p1[3] = { -LINE_LENGTH, 0, 0 };
        float p2[3] = {  LINE_LENGTH, 0, 0 };

        float r1[3], r2[3];
        rotate(p1, angleX, angleY, angleZ, r1);
        rotate(p2, angleX, angleY, angleZ, r2);

        float d = 3.0f;
        float z1 = r1[2] + d;
        float z2 = r2[2] + d;

        int x1 = WIDTH / 2 + (int)(SCALE * r1[0] / z1);
        int y1 = HEIGHT / 2 - (int)(SCALE * r1[1] / z1);
        int x2 = WIDTH / 2 + (int)(SCALE * r2[0] / z2);
        int y2 = HEIGHT / 2 - (int)(SCALE * r2[1] / z2);

        draw_line(buffer, x1, y1, x2, y2, '*');

        // Print frame
        printf("\x1b[H");
        for (int y = 0; y < HEIGHT; y++) {
            fwrite(&buffer[y * WIDTH], 1, WIDTH, stdout);
            putchar('\n');
        }

        // Rotate the line
        angleX += 0.04f;
        angleY += 0.03f;
        angleZ += 0.02f;

        usleep(30000);
    }

    return 0;
}
