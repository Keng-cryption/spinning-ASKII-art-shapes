#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 120
#define HEIGHT 60
#define CUBE_SIZE 50

// 8 cube vertices
float cube[8][3] = {
    {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
    {-1, -1,  1}, {1, -1,  1}, {1, 1,  1}, {-1, 1,  1}
};

// Each face is 4 vertex indices
int faces[6][4] = {
    {0, 1, 2, 3}, // back
    {4, 5, 6, 7}, // front
    {0, 1, 5, 4}, // bottom
    {2, 3, 7, 6}, // top
    {0, 3, 7, 4}, // left
    {1, 2, 6, 5}  // right
};

// Each face has a unique fill character
char face_chars[6] = { '#', '@', '%', '+', '=', '*' };

// Struct for painter's algorithm
typedef struct {
    float avg_z;
    int face_index;
} FaceDepth;

int compare_faces(const void *a, const void *b) {
    FaceDepth *fa = (FaceDepth *)a;
    FaceDepth *fb = (FaceDepth *)b;
    return (fb->avg_z > fa->avg_z) - (fb->avg_z < fa->avg_z);
}

// 3D rotation
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

// Fill a face using scanline approximation
void fill_face(char *buffer, float pts[4][2], char ch) {
    int minY = HEIGHT, maxY = 0;
    for (int i = 0; i < 4; i++) {
        if (pts[i][1] < minY) minY = (int)pts[i][1];
        if (pts[i][1] > maxY) maxY = (int)pts[i][1];
    }

    for (int y = minY; y <= maxY; y++) {
        float xints[4];
        int count = 0;
        for (int i = 0; i < 4; i++) {
            int j = (i + 1) % 4;
            float y0 = pts[i][1], y1 = pts[j][1];
            float x0 = pts[i][0], x1 = pts[j][0];

            if ((y >= y0 && y < y1) || (y >= y1 && y < y0)) {
                float xint = x0 + (y - y0) * (x1 - x0) / (y1 - y0);
                xints[count++] = xint;
            }
        }

        if (count == 2) {
            int xStart = (int)fminf(xints[0], xints[1]);
            int xEnd   = (int)fmaxf(xints[0], xints[1]);
            for (int x = xStart; x <= xEnd; x++) {
                if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
                    buffer[y * WIDTH + x] = ch;
            }
        }
    }
}

int main() {
    float angleX = 0, angleY = 0, angleZ = 0;
    char buffer[WIDTH * HEIGHT + 1];
    buffer[WIDTH * HEIGHT] = '\0';

    printf("\x1b[2J"); // Clear screen

    while (1) {
        memset(buffer, ' ', WIDTH * HEIGHT);

        float rotated[8][3], projected[8][2];
        for (int i = 0; i < 8; i++) {
            rotate(cube[i], angleX, angleY, angleZ, rotated[i]);

            float distance = 4;
            float z = rotated[i][2] + distance;
            float scale = CUBE_SIZE / z;

            projected[i][0] = WIDTH / 2 + scale * rotated[i][0] * 2;
            projected[i][1] = HEIGHT / 2 - scale * rotated[i][1];
        }

        FaceDepth face_order[6];
        for (int i = 0; i < 6; i++) {
            float z_sum = 0;
            for (int j = 0; j < 4; j++) {
                int idx = faces[i][j];
                z_sum += rotated[idx][2];
            }
            face_order[i].avg_z = z_sum / 4;
            face_order[i].face_index = i;
        }

        qsort(face_order, 6, sizeof(FaceDepth), compare_faces);

        for (int i = 0; i < 6; i++) {
            int f = face_order[i].face_index;
            float pts[4][2];
            for (int j = 0; j < 4; j++) {
                int idx = faces[f][j];
                pts[j][0] = projected[idx][0];
                pts[j][1] = projected[idx][1];
            }
            fill_face(buffer, pts, face_chars[f]);
        }

        // Print frame
        printf("\x1b[H"); // Reset cursor
        for (int y = 0; y < HEIGHT; y++) {
            fwrite(&buffer[y * WIDTH], 1, WIDTH, stdout);
            putchar('\n');
        }

        angleX += 0.03f;
        angleY += 0.02f;
        angleZ += 0.015f;
        usleep(30000);
    }

    return 0;
}
