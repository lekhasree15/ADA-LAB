#include <stdio.h>
#define N 4


void printSolution(int board[N][N]) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
    printf("\n");
}


int isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return 0;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return 0;
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return 0;
    return 1;
}


void solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        printSolution(board);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solveNQueens(board, col + 1);
            board[i][col] = 0;
        }
    }
}


int main() {
    int board[N][N] = {0};
    printf("N-Queens Problem (N=%d)\n", N);
    solveNQueens(board, 0);
    return 0;
}
