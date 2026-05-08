// 287. Find the Duplicate Number
// Difficulty: Medium | Topic: Arrays Part-II | Language: C++
// https://leetcode.com/problems/find-the-duplicate-number/
//
// Problem: Given an array nums of n+1 integers where each integer is in
// range [1, n], there is exactly one repeated number. Find it without
// modifying the array and using only O(1) extra space.
//
// Approach: Floyd's Cycle Detection (Tortoise and Hare). Treat array
// values as pointers. A cycle exists because of the duplicate. Find
// the entry point of the cycle which is the duplicate number.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } 
        while (slow != fast);
        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};