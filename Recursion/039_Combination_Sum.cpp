// 39. Combination Sum
// Difficulty: Medium | Topic: Recursion | Language: C++
// https://leetcode.com/problems/combination-sum/
//
// Problem: Given an array of distinct integers and a target, return
// all unique combinations where chosen numbers sum to target.
// The same number may be chosen unlimited times.
//
// Approach: Backtracking with pick/not-pick. If picking, stay at same
// index (allow reuse). If not picking, move to next index.
// Time: O(2^t) | Space: O(k*x)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,
               vector<int>& curr, vector<vector<int>>& result)
    {
        if (idx == candidates.size())
        {
            if (target == 0) result.push_back(curr);
            return;
        }
        if (candidates[idx] <= target)
        {
            curr.push_back(candidates[idx]);
            solve(idx, candidates, target - candidates[idx], curr, result);
            curr.pop_back();
        }
        solve(idx + 1, candidates, target, curr, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(0, candidates, target, curr, result);
        return result;
    }
};