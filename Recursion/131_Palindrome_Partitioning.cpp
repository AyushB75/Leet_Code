// 131. Palindrome Partitioning
// Difficulty: Hard | Topic: Recursion | Language: C++
// https://leetcode.com/problems/palindrome-partitioning/
//
// Problem: Given a string s, partition it such that every substring
// of the partition is a palindrome. Return all possible partitions.
//
// Approach: Backtracking. At each index, try every possible substring
// starting there. If it's a palindrome, recurse on the remaining string.
// Time: O(2^n * n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string& s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
    void solve(int idx, string& s, vector<string>& curr,
               vector<vector<string>>& result)
    {
        if (idx == s.size())
        {
            result.push_back(curr);
            return;
        }
        for (int i = idx; i < s.size(); i++)
        {
            if (isPalindrome(s, idx, i))
            {
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, curr, result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        solve(0, s, curr, result);
        return result;
    }
};