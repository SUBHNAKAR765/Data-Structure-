// WAP A PROGRAM TO IMPLEMENT CHAIN MATRIX MULTIPLICATION 

#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int d[], int n) {
    int m[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int d[n + 1];
    printf("Enter the dimensions array: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &d[i]);
    }

    printf("Minimum number of multiplications is %d\n", matrixChainMultiplication(d, n + 1));

    return 0;
}