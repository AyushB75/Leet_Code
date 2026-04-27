// 001. Two Sum
// Difficulty: Easy | Topic: Arrays | Language: C++
// https://leetcode.com/problems/two-sum/
//
// Problem: Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.
//
// Approach: Use a hash map to store seen values and their indices.
// For each number, check if (target - num) already exists in the map.
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) 
        {
            int complement = target - nums[i];
            if (seen.count(complement)) 
            {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};
