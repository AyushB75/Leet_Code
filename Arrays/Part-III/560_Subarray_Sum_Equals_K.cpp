// 560. Subarray Sum Equals K
// Difficulty: Medium | Topic: Arrays Part-III | Language: C++
// https://leetcode.com/problems/subarray-sum-equals-k/
//
// Problem: Given an array of integers and an integer k, return the total
// number of subarrays whose sum equals k.
//
// Approach: Use prefix sum with a hash map. For each index, check if
// (currentSum - k) exists in the map. If yes, those many subarrays
// ending here have sum k.
// Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int currSum = 0, count = 0;
        for (int num : nums)
        {
            currSum += num;
            if (prefixCount.count(currSum - k))
            {
                count += prefixCount[currSum - k];
            }
            prefixCount[currSum]++;
        }
        return count;
    }
};