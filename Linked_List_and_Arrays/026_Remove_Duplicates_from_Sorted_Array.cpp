// 26. Remove Duplicates from Sorted Array
// Difficulty: Easy | Topic: Linked List & Arrays | Language: C++
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//
// Problem: Given a sorted array, remove duplicates in-place such that
// each element appears only once. Return the new length.
//
// Approach: Two pointer approach. Keep a slow pointer for unique
// elements. Fast pointer scans ahead and copies unique values.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 0;
        for (int fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};