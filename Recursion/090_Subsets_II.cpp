// 90. Subsets II
// Difficulty: Medium | Topic: Recursion | Language: C++
// https://leetcode.com/problems/subsets-ii/
//
// Problem: Given an integer array that may contain duplicates, return
// all possible unique subsets.
//
// Approach: Sort the array first. Use backtracking, skipping duplicate
// elements at the same recursion level to avoid duplicate subsets.
// Time: O(2^n * n) | Space: O(2^n * n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& curr,
               vector<vector<int>>& result)
    {
        result.push_back(curr);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            solve(i + 1, nums, curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        solve(0, nums, curr, result);
        return result;
    }
};