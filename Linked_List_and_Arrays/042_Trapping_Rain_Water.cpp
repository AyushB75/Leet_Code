// 42. Trapping Rain Water
// Difficulty: Hard | Topic: Linked List & Arrays | Language: C++
// https://leetcode.com/problems/trapping-rain-water/
//
// Problem: Given n non-negative integers representing an elevation map
// of width 1, compute how much water it can trap after raining.
//
// Approach: Two pointer approach. Track maxLeft and maxRight.
// Water at any index = min(maxLeft, maxRight) - height[i].
// Move the pointer with smaller max value inward.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int water = 0;
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= maxLeft) maxLeft = height[left];
                else water += maxLeft - height[left];
                left++;
            }
            else
            {
                if (height[right] >= maxRight) maxRight = height[right];
                else water += maxRight - height[right];
                right--;
            }
        }
        return water;
    }
};