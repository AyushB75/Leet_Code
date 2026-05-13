// 018. 4Sum
// Difficulty: Medium | Topic: Arrays Part-IV | Language: C++
// https://leetcode.com/problems/4sum/
//
// Problem: Given an array and target, return all unique quadruplets
// that sum to target.
//
// Approach: Sort array. Fix two pointers i and j, then use two pointer
// technique for remaining two. Skip duplicates at every level.
// Time: O(n^3) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++; right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }
        return result;
    }
};