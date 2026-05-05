// 075. Sort Colors (Dutch National Flag Algorithm)
// Difficulty: Medium | Topic: Arrays | Language: C++
// https://leetcode.com/problems/sort-colors/
//
// Problem: Given an array with only 0s, 1s, and 2s, sort them in place
// so all 0s come first, then 1s, then 2s.
//
// Approach: Dutch National Flag algorithm with three pointers - low, mid, high.
// 0s go to the left, 2s go to the right, 1s stay in the middle.
// Single pass through the array.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
