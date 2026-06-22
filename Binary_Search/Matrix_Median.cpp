// Matrix Median
// Difficulty: Hard | Topic: Binary Search | Language: C++
// https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
//
// Problem: Given a row-wise sorted matrix of odd size, find the median.
//
// Approach: Binary search on value range [min, max]. For each mid,
// count elements <= mid across all rows using upper_bound.
// Median is the smallest value where count > (n*m)/2.
// Time: O(32 * n * log m) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int median(vector<vector<int>>& matrix, int R, int C) {
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C-1]);
        }
        int target = (R * C + 1) / 2;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < R; i++)
                count += upper_bound(matrix[i].begin(),
                         matrix[i].end(), mid) - matrix[i].begin();
            if (count < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};