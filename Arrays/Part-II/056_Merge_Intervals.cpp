// 056. Merge Intervals
// Difficulty: Medium | Topic: Arrays Part-II | Language: C++
// https://leetcode.com/problems/merge-intervals/
//
// Problem: Given an array of intervals, merge all overlapping intervals
// and return an array of the non-overlapping intervals.
//
// Approach: Sort intervals by start time. Iterate and merge if current
// interval overlaps with the last merged one by extending its end.
// Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (auto& interval : intervals)
        {
            if (result.empty() || result.back()[1] < interval[0])
            {
                result.push_back(interval);
            }
            else
            {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};
