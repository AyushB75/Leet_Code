// 493. Reverse Pairs
// Difficulty: Hard | Topic: Arrays Part-III | Language: C++
// https://leetcode.com/problems/reverse-pairs/
//
// Problem: Given an array, return the number of reverse pairs where
// i < j and nums[i] > 2 * nums[j].
//
// Approach: Modified Merge Sort. During merge step, count pairs where
// nums[i] > 2 * nums[j] using two pointers before merging.
// Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int count = 0;
    void merge(vector<int>& nums, int left, int mid, int right)
    {
        int j = mid + 1;
        for (int i = left; i <= mid; i++)
        {
            while (j <= right && nums[i] > 2LL * nums[j]) j++;
            count += j - (mid + 1);
        }
        vector<int> temp;
        int l = left, r = mid + 1;
        while (l <= mid && r <= right)
        {
            if (nums[l] <= nums[r]) temp.push_back(nums[l++]);
            else temp.push_back(nums[r++]);
        }
        while (l <= mid) temp.push_back(nums[l++]);
        while (r <= right) temp.push_back(nums[r++]);
        for (int i = left; i <= right; i++) nums[i] = temp[i - left];
    }
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};