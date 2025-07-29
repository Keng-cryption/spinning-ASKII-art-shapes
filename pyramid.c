#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 140
#define HEIGHT 70

// Pyramid vertices (square base + apex)
float vertices[5][3] = {
    {-1, -1, -1},  // base 0
    { 1, -1, -1},  // base 1
    { 1, -1,  1},  // base 2
    {-1, -1,  1},  // base 3
    { 0,  1,  0}   // apex 4
};

// Faces as vertex indices (base + 4 triangular sides)
int faces[5][4] = {
    {0, 1, 2, 3},  // base (square)
    {0, 1, 4, -1}, // side 1 (triangle)
    {1, 2, 4, -1}, // side 2
    {2, 3, 4, -1}, // side 3
    {3, 0, 4, -1}  // side 4
};

// Each face a unique fill character
char face_chars[5] = { '#', '@', '%', '+', '=' };

// Struct for sorting faces by depth
typedef struct {
    float avg_z;
    int face_index;
} FaceDepth;

int compare_faces(const void *a, const void *b) {
    FaceDepth *fa = (FaceDepth *)a;
    FaceDepth *fb = (FaceDepth *)b;
    if (fb->avg_z > fa->avg_z) return 1;
    if (fb->avg_z < fa->avg_z) return -1;
    return 0;
}

// 3D rotation (yaw-pitch-roll) around X, Y, Z axes
void rotate(float in[3], float ax, float ay, float az, float out[3]) {
    float x = in[0], y = in[1], z = in[2];
    // Rotate around X
    float cx = cosf(ax), sx = sinf(ax);
    float y1 = y * cx - z * sx;
    float z1 = y * sx + z * cx;
    // Rotate around Y
    float cy = cosf(ay), sy = sinf(ay);
    float x2 = x * cy + z1 * sy;
    float z2 = -x * sy + z1 * cy;
    // Rotate around Z
    float cz = cosf(az), sz = sinf(az);
    float x3 = x2 * cz - y1 * sz;
    float y3 = x2 * sz + y1 * cz;
    out[0] = x3; out[1] = y3; out[2] = z2;
}

// Project 3D point to 2D screen coords
void project(float in[3], int *x, int *y) {
    float distance = 7.0f;
    float scale = 200.0f;
    float z = in[2] + distance;
    if (z == 0) z = 0.001f;
    *x = (int)(WIDTH / 2 + scale * in[0] / z);
    *y = (int)(HEIGHT / 2 - scale * 0.5f * in[1] / z); // half scale Y for aspect ratio
}

// Scanline fill polygon (convex, up to 4 points)
void fill_face(char *buffer, int pts[][2], int npts, char ch) {
    int minY = HEIGHT, maxY = 0;
    for (int i = 0; i < npts; i++) {
        if (pts[i][1] < minY) minY = pts[i][1];
        if (pts[i][1] > maxY) maxY = pts[i][1];
    }
    if (minY < 0) minY = 0;
    if (maxY >= HEIGHT) maxY = HEIGHT -1;

    for (int y = minY; y <= maxY; y++) {
        int nodes = 0;
        int nodeX[10];
        for (int i = 0, j = npts - 1; i < npts; j = i++) {
            int yi = pts[i][1], yj = pts[j][1];
            if ((yi < y && yj >= y) || (yj < y && yi >= y)) {
                int xi = pts[i][0], xj = pts[j][0];
                int x = xi + (y - yi) * (xj - xi) / (yj - yi);
                nodeX[nodes++] = x;
            }
        }
        // sort nodes
        for (int i = 0; i < nodes-1; i++) {
            for (int k = i+1; k < nodes; k++) {
                if (nodeX[k] < nodeX[i]) {
                    int tmp = nodeX[i]; nodeX[i] = nodeX[k]; nodeX[k] = tmp;
                }
            }
        }
        // fill between node pairs
        for (int i = 0; i < nodes; i += 2) {
            if (i+1 >= nodes) break;
            int xStart = nodeX[i];
            int xEnd = nodeX[i+1];
            if (xStart < 0) xStart = 0;
            if (xEnd >= WIDTH) xEnd = WIDTH -1;
            for (int x = xStart; x <= xEnd; x++) {
                buffer[y * WIDTH + x] = ch;
            }
        }
    }
}

int main() {
    char buffer[WIDTH * HEIGHT +1];
    buffer[WIDTH * HEIGHT] = '\0';
    float angleX = 0, angleY = 0, angleZ = 0;

    printf("\x1b[2J"); // Clear screen once

    while(1) {
        memset(buffer, ' ', WIDTH * HEIGHT);

        float rotated[5][3];
        for(int i=0; i<5; i++) {
            rotate(vertices[i], angleX, angleY, angleZ, rotated[i]);
        }

        // Compute face depths
        FaceDepth face_order[5];
        for(int f=0; f<5; f++) {
            float zsum = 0;
            int count = 0;
            for(int v=0; v<4; v++) {
                int vi = faces[f][v];
                if(vi < 0) break;
                zsum += rotated[vi][2];
                count++;
            }
            face_order[f].avg_z = zsum / count;
            face_order[f].face_index = f;
        }
        qsort(face_order, 5, sizeof(FaceDepth), compare_faces);

        // Draw faces back to front
        for(int i=0; i<5; i++) {
            int f = face_order[i].face_index;
            int pts[4][2];
            int npts = 0;
            for(int v=0; v<4; v++) {
                int vi = faces[f][v];
                if(vi < 0) break;
                project(rotated[vi], &pts[npts][0], &pts[npts][1]);
                npts++;
            }
            fill_face(buffer, pts, npts, face_chars[f]);
        }

        printf("\x1b[H"); // Move cursor home
        for(int y=0; y<HEIGHT; y++) {
            fwrite(&buffer[y*WIDTH], 1, WIDTH, stdout);
            putchar('\n');
        }

        angleX += 0.02f;
        angleY += 0.03f;
        angleZ += 0.015f;

        usleep(30000);
    }

    return 0;
}
