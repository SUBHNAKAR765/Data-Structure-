// Write a program to implement N-Queens’ problem 

#include <stdio.h>

#define N 8

int board[N][N];

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solve(int col) {
    if (col >= N) {
        printBoard();
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solve(col + 1))
                return 1;

            board[i][col] = 0;
        }
    }
    return 0;
}

int main() {
    if (!solve(0))
        printf("No solution\n");
    return 0;
}

