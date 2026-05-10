// 128. Longest Consecutive Sequence
// Difficulty: Medium | Topic: Arrays Part-III | Language: C++
// https://leetcode.com/problems/longest-consecutive-sequence/
//
// Problem: Given an unsorted array of integers, return the length of the
// longest consecutive elements sequence. Must run in O(n) time.
//
// Approach: Add all numbers to an unordered_set. For each number check
// if it's the start of a sequence (num-1 not in set). If yes, count
// consecutive numbers from there and update max length.
// Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        for (int num : numSet)
        {
            if (numSet.find(num - 1) == numSet.end())
            {
                int currNum = num, currLen = 1;
                while (numSet.find(currNum + 1) != numSet.end())
                {
                    currNum++;
                    currLen++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};