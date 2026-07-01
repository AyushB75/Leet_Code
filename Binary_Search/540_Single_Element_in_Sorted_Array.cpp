// 540. Single Element in a Sorted Array
// Difficulty: Medium | Topic: Binary Search | Language: C++
// https://leetcode.com/problems/single-element-in-a-sorted-array/
//
// Problem: Given a sorted array where every element appears twice
// except one, find that single element.
//
// Approach: Binary search. Ensure low/high land on even indices.
// If nums[mid] == nums[mid^1], answer lies in right half, else left.
// Time: O(log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == nums[mid ^ 1]) low = mid + 1;
            else high = mid - 1;
        }
        return nums[low];
    }
};