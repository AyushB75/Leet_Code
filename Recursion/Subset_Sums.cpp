// Subset Sums
// Difficulty: Hard | Topic: Recursion | Language: C++
// https://www.geeksforgeeks.org/subset-sums/
//
// Problem: Given an array, return the sums of all possible subsets
// in any order.
//
// Approach: Recursion with pick/not-pick choice at each index.
// At the end of the array, store the current sum.
// Time: O(2^n) | Space: O(2^n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int idx, int sum, vector<int>& arr, vector<int>& result)
    {
        if (idx == arr.size())
        {
            result.push_back(sum);
            return;
        }
        solve(idx + 1, sum + arr[idx], arr, result);
        solve(idx + 1, sum, arr, result);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> result;
        solve(0, 0, arr, result);
        sort(result.begin(), result.end());
        return result;
    }
};