#include <iostream>
using namespace std;

#define N 9

// Function to print the Sudoku board
void printBoard(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number at board[row][col]
bool isSafe(int board[N][N], int row, int col, int num) {
    // Check if the number is not in the current row
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check if the number is not in the current column
    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Check if the number is not in the 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to find an empty location in the board
bool findEmptyLocation(int board[N][N], int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Main function that solves the Sudoku using backtracking
bool solveSudoku(int board[N][N]) {
    int row, col;

    // If there's no empty location, the puzzle is solved
    if (!findEmptyLocation(board, row, col)) {
        return true;
    }

    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++) {
        // If placing num in board[row][col] is valid
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recur to place the next number
            if (solveSudoku(board)) {
                return true;
            }

            // If placing num doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    return false; 
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}

