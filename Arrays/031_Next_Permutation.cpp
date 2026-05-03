// 031. Next Permutation
// Difficulty: Medium | Topic: Arrays | Language: C++
// https://leetcode.com/problems/next-permutation/
//
// Problem: Given an array of integers, rearrange it into the next
// lexicographically greater permutation. If no such permutation exists,
// rearrange to the lowest possible order (sorted ascending).
//
// Approach: Find the first decreasing element from the right (pivot).
// Swap it with the smallest element greater than it from the right.
// Then reverse everything after the pivot position.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), pivot = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }
        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > pivot; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
