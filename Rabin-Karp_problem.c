// Write a program to implement Rabin-Karp string matching algorithm

#include <stdio.h>
#include <string.h>

#define D 256
#define Q 101

void search(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);
    int p = 0;
    int t = 0;
    int h = 1;
    int i, j;

    for (i = 0; i < m - 1; i++)
        h = (h * D) % Q;

    for (i = 0; i < m; i++) {
        p = (D * p + pattern[i]) % Q;
        t = (D * t + text[i]) % Q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;

            if (j == m)
                printf("Pattern found at index %d \n", i);
        }

        if (i < n - m) {
            t = (D * (t - text[i] * h) + text[i + m]) % Q;
            if (t < 0)
                t = (t + Q);
        }
    }
}

int main() {
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";
    search(text, pattern);
    return 0;
}
