// Largest Subarray with K Sum
// Difficulty: Medium | Topic: Arrays Part-IV | Language: C++
// https://leetcode.com/problems/subarray-sum-equals-k/ (variant)
//
// Problem: Given an array and integer k, find the length of the
// longest subarray whose sum equals k.
//
// Approach: Use prefix sum with hash map. Store first occurrence of
// each prefix sum. If (currSum - k) exists in map, update max length.
// Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lenOfLongestSubarr(vector<int>& nums, int k) {
        unordered_map<int, int> prefixIndex;
        int currSum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            if (currSum == k)
            {
                maxLen = i + 1;
            }
            if (prefixIndex.count(currSum - k))
            {
                maxLen = max(maxLen, i - prefixIndex[currSum - k]);
            }
            if (!prefixIndex.count(currSum))
            {
                prefixIndex[currSum] = i;
            }
        }
        return maxLen;
    }
};