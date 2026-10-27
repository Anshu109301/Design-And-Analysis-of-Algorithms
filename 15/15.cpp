#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<int> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

bool isSafe(vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        // Same column
        if (board[i] == col)
            return false;

        // Same diagonal
        if (abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solveNQueens(vector<int> &board, int row, int n)
{
    if (row == n)
    {
        printBoard(board, n);
        return true;
    }

    bool found = false;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;

            if (solveNQueens(board, row + 1, n))
                found = true;

            // Backtrack
            board[row] = -1;
        }
    }

    return found;
}

int main()
{
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Enter a positive integer.\n";
        return 0;
    }

    vector<int> board(n, -1);

    if (!solveNQueens(board, 0, n))
        cout << "No solution exists.\n";

    return 0;
}
