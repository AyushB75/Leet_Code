// K-th Element of Two Sorted Arrays
// Difficulty: Medium | Topic: Binary Search | Language: C++
// https://www.geeksforgeeks.org/k-th-element-of-two-sorted-arrays/
//
// Problem: Given two sorted arrays of size n and m, find the
// element at the kth position (1-indexed) of the merged array.
//
// Approach: Same partition-based binary search as Median of Two
// Sorted Arrays, but partition size is k instead of (n+m+1)/2.
// Time: O(log(min(n,m))) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        int n1 = arr1.size(), n2 = arr2.size();
        if (n1 > n2) return kthElement(arr2, arr1, k);
        int low = max(0, k - n2), high = min(k, n1);
        while (low <= high)
        {
            int cut1 = low + (high - low) / 2;
            int cut2 = k - cut1;
            int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : arr2[cut2];
            if (l1 <= r2 && l2 <= r1) return max(l1, l2);
            else if (l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        return -1;
    }
};