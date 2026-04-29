// 118. Pascal's Triangle
// Difficulty: Easy | Topic: Arrays | Language: C++
// https://leetcode.com/problems/pascals-triangle/
//
// Problem: Given an integer numRows, return the first numRows of Pascal's
// triangle. Each number is the sum of the two numbers directly above it.
//
// Approach: Build row by row. Each element (except edges) is the sum of
// the two elements above it from the previous row. First and last of
// every row are always 1.
// Time: O(n^2) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
