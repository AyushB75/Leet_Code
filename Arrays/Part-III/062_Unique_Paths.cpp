// 062. Unique Paths
// Difficulty: Medium | Topic: Arrays Part-III | Language: C++
// https://leetcode.com/problems/unique-paths/
//
// Problem: A robot is located at the top-left corner of an m x n grid.
// It can only move right or down. How many unique paths are there
// to reach the bottom-right corner?
//
// Approach: Dynamic Programming. dp[i][j] = dp[i-1][j] + dp[i][j-1].
// Each cell is the sum of paths from top and left cells.
// Time: O(m*n) | Space: O(m*n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};