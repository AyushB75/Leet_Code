// 003. Longest Substring Without Repeating Characters
// Difficulty: Medium | Topic: Arrays Part-IV | Language: C++
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
// Problem: Given a string s, find the length of the longest substring
// without repeating characters.
//
// Approach: Sliding window with hash map storing last seen index of each
// character. Move left pointer to max(left, lastSeen[char] + 1) on repeat.
// Time: O(n) | Space: O(min(n, 26))
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int maxLen = 0, left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            if (lastSeen.count(s[right]))
            {
                left = max(left, lastSeen[s[right]] + 1);
            }
            lastSeen[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};