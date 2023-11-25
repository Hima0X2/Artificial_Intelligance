#include <bits/stdc++.h>
using namespace std;
int totalSolutions=0;
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}
void printBoard(const vector<int>& board, int n) {
    totalSolutions++;
    cout << "Solution " << totalSolutions << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void solveNQueens(vector<int>& board, int row, int n) {
    if (row == n) {
        printBoard(board, n);
    } else {
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row] = col;
                solveNQueens(board, row + 1, n);
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;
    vector<int> board(n, -1);
    solveNQueens(board, 0, n);
    return 0;
}
