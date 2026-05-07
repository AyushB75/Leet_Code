// 088. Merge Sorted Array
// Difficulty: Easy | Topic: Arrays Part-II | Language: C++
// https://leetcode.com/problems/merge-sorted-array/
//
// Problem: Given two sorted arrays nums1 and nums2, merge nums2 into
// nums1 in-place. nums1 has enough space at the end to hold nums2.
//
// Approach: Start filling from the back of nums1 using three pointers —
// one at end of valid nums1, one at end of nums2, one at end of total space.
// This avoids overwriting elements we haven't processed yet.
// Time: O(m+n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};
