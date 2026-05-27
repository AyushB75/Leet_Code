// 485. Max Consecutive Ones
// Difficulty: Easy | Topic: Linked List & Arrays | Language: C++
// https://leetcode.com/problems/max-consecutive-ones/
//
// Problem: Given a binary array, return the maximum number of
// consecutive 1's in the array.
//
// Approach: Single pass. Track current count of 1's and update
// max whenever current count exceeds it. Reset on 0.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else count = 0;
        }
        return maxCount;
    }
};