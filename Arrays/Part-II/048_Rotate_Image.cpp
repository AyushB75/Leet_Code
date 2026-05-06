// 048. Rotate Image
// Difficulty: Medium | Topic: Arrays Part-II | Language: C++
// https://leetcode.com/problems/rotate-image/
//
// Problem: Given an n x n 2D matrix representing an image,
// rotate it 90 degrees clockwise in place.
//
// Approach: First transpose the matrix (swap matrix[i][j] with matrix[j][i]).
// Then reverse each row. These two steps together achieve a 90 degree
// clockwise rotation without using extra space.
// Time: O(n^2) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
