// 4. Median of Two Sorted Arrays
// Difficulty: Hard | Topic: Binary Search | Language: C++
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//
// Problem: Given two sorted arrays, find the median of the
// combined array better than O(n).
//
// Approach: Binary search on the smaller array to partition both
// arrays so left half has (n+1)/2 elements total; validate via
// boundary comparisons.
// Time: O(log(min(n,m))) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size(), n2 = nums2.size();
        int low = 0, high = n1;
        int total = n1 + n2, half = (total + 1) / 2;
        while (low <= high)
        {
            int cut1 = low + (high - low) / 2;
            int cut2 = half - cut1;
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            if (l1 <= r2 && l2 <= r1)
            {
                if (total % 2 == 0) return (max(l1, l2) + min(r1, r2)) / 2.0;
                return max(l1, l2);
            }
            else if (l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        return 0.0;
    }
};