#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h> // for usleep()

int main() {
    int asdf, asdfg = 35;
    asdf = 70;
    float A = 0.0f, B = 0.0f;
    const int width = 213, height = 72;             // Larger display dimensions
    const int bufferSize = width * height;
    float z[bufferSize];
    char buffer[bufferSize + 1];
    buffer[bufferSize] = '\0';
    const char* lut = ".,-~:;=!*#$@";

    printf("\x1b[2J"); // Clear screen

    while (1) {
        memset(buffer, ' ', bufferSize);
        memset(z, 0, sizeof(z));

        for (float j = 0; j < 6.28f; j += 0.07f) {
            for (float i = 0; i < 6.28f; i += 0.02f) {
                float sin_i = sinf(i), cos_i = cosf(i);
                float sin_j = sinf(j), cos_j = cosf(j);
                float sinA = sinf(A), cosA = cosf(A);
                float sinB = sinf(B), cosB = cosf(B);

                float h = cos_j + 2.0f;
                float D = 1.0f / (sin_i * h * sinA + sin_j * cosA + 5.0f);
                float t = sin_i * h * cosA - sin_j * sinA;
                float xp = cos_i * h * cosB - t * sinB;
                float yp = cos_i * h * sinB + t * cosB;

                // <-- HERE: scaling constants increased for larger size -->
                int x = (int)(width/2 + asdf * D * xp);   // was 30 before
                int y = (int)(height/2 + asdfg * D * yp);  // was 15 before
                int o = x + width * y;

                int luminance = (int)(8 * ((sin_j * sinA - sin_i * cos_j * cosA) * cosB
                                         - sin_i * cos_j * sinA
                                         - sin_j * cosA
                                         - cos_i * cos_j * sinB));

                if (x >= 0 && x < width && y >= 0 && y < height && D > z[o]) {
                    z[o] = D;
                    buffer[o] = lut[luminance > 0 ? luminance : 0];
                }
            }
        }

        printf("\x1b[H"); // Move cursor to home
        for (int yy = 0; yy < height; yy++) {
            fwrite(&buffer[yy * width], 1, width, stdout);
            putchar('\n');
        }

        A += 0.04f;
        B += 0.02f;
        usleep(30000);
    }

    return 0;
}
