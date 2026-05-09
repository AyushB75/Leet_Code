// 074. Search a 2D Matrix
// Difficulty: Medium | Topic: Arrays Part-III | Language: C++
// https://leetcode.com/problems/search-a-2d-matrix/
//
// Problem: Given an m x n matrix where each row is sorted and the first
// integer of each row is greater than the last integer of the previous row,
// return true if target exists in the matrix.
//
// Approach: Start from top-right corner. If current element equals target
// return true. If greater than target move left, if smaller move down.
// This eliminates one row or column at each step.
// Time: O(m+n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
        return false;
    }
};
