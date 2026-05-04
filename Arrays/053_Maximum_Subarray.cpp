// 053. Maximum Subarray (Kadane's Algorithm)
// Difficulty: Medium | Topic: Arrays | Language: C++
// https://leetcode.com/problems/maximum-subarray/
//
// Problem: Given an integer array nums, find the subarray with the
// largest sum and return its sum.
//
// Approach: Track current running sum. If it drops below 0, reset it.
// Keep updating the maximum sum seen so far at each step.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            if (currSum > maxSum)
            {
                maxSum = currSum;
            }
            if (currSum < 0)
            {
                currSum = 0;
            }
        }
        return maxSum;
    }
};
