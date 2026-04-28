// 073. Set Matrix Zeroes
// Difficulty: Medium | Topic: Arrays | Language: C++
// https://leetcode.com/problems/set-matrix-zeroes/
//
// Problem: Given an m x n integer matrix, if an element is 0,
// set its entire row and column to 0. Do it in place.
//
// Approach: Use first row and first column as markers to track which
// rows/cols need to be zeroed. Use two flags to handle the first
// row and column separately to avoid overwriting markers early.
// Time: O(m*n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) firstRow = true;
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) firstCol = true;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if (firstRow)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if (firstCol)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};
