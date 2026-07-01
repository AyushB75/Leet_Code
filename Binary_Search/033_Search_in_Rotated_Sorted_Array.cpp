// 33. Search in Rotated Sorted Array
// Difficulty: Medium | Topic: Binary Search | Language: C++
// https://leetcode.com/problems/search-in-rotated-sorted-array/
//
// Problem: Given a rotated sorted array with distinct elements,
// search for a target and return its index, else -1.
//
// Approach: Binary search. At each mid, identify which half is
// sorted, then check if target lies within that sorted half.
// Time: O(log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};