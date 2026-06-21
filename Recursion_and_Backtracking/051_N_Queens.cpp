// 51. N-Queens
// Difficulty: Hard | Topic: Recursion and Backtracking | Language: C++
// https://leetcode.com/problems/n-queens/
//
// Problem: Place n queens on an n×n chessboard such that no two
// queens attack each other. Return all distinct solutions.
//
// Approach: Backtracking column by column. Track attacked rows,
// and both diagonals using hash sets for O(1) checks.
// Time: O(n!) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int col, int n, vector<string>& board,
               vector<int>& rows, vector<int>& lowerDiag,
               vector<int>& upperDiag, vector<vector<string>>& result)
    {
        if (col == n)
        {
            result.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (!rows[row] && !lowerDiag[row + col] &&
                !upperDiag[n - 1 + col - row])
            {
                rows[row] = lowerDiag[row + col] = upperDiag[n-1+col-row] = 1;
                board[row][col] = 'Q';
                solve(col + 1, n, board, rows, lowerDiag, upperDiag, result);
                board[row][col] = '.';
                rows[row] = lowerDiag[row + col] = upperDiag[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> rows(n, 0), lowerDiag(2*n-1, 0), upperDiag(2*n-1, 0);
        vector<vector<string>> result;
        solve(0, n, board, rows, lowerDiag, upperDiag, result);
        return result;
    }
};