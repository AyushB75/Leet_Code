// 46. Permutations
// Difficulty: Medium | Topic: Recursion and Backtracking | Language: C++
// https://leetcode.com/problems/permutations/
//
// Problem: Given an array of distinct integers, return all possible
// permutations.
//
// Approach: Backtracking with a boolean "used" array. At each step
// pick an unused element, recurse, then backtrack.
// Time: O(n! * n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<int>& nums, vector<bool>& used,
               vector<int>& curr, vector<vector<int>>& result)
    {
        if (curr.size() == nums.size())
        {
            result.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            solve(nums, used, curr, result);
            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        solve(nums, used, curr, result);
        return result;
    }
};