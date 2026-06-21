// 37. Sudoku Solver
// Difficulty: Hard | Topic: Recursion and Backtracking | Language: C++
// https://leetcode.com/problems/sudoku-solver/
//
// Problem: Write a program to solve a 9x9 Sudoku puzzle by filling
// the empty cells.
//
// Approach: Backtracking. For each empty cell, try digits 1-9. Check
// validity in row, column, and 3x3 box before placing. Backtrack if
// no digit works.
// Time: O(9^(n*n)) | Space: O(n*n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, row, col, c))
                        {
                            board[row][col] = c;
                            if (solve(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};