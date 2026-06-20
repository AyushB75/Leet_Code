// 40. Combination Sum II
// Difficulty: Medium | Topic: Recursion | Language: C++
// https://leetcode.com/problems/combination-sum-ii/
//
// Problem: Given a collection of candidate numbers (may contain
// duplicates) and a target, find all unique combinations where
// numbers sum to target. Each number used at most once.
//
// Approach: Sort array first. Backtrack and skip duplicates at the
// same recursion level to avoid duplicate combinations.
// Time: O(2^n) | Space: O(k*x)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,
               vector<int>& curr, vector<vector<int>>& result)
    {
        if (target == 0)
        {
            result.push_back(curr);
            return;
        }
        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;
            curr.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        solve(0, candidates, target, curr, result);
        return result;
    }
};