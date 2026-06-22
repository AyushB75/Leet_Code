// Word Break (Print All Ways)
// Difficulty: Medium | Topic: Recursion and Backtracking | Language: C++
// https://www.geeksforgeeks.org/word-break-problem-using-backtracking/
//
// Problem: Given a string and a dictionary, print all possible ways
// to break the string into valid dictionary words.
//
// Approach: Backtracking. At each index, check every prefix. If it
// exists in the dictionary, recurse on the remaining string.
// Time: O(2^n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(string& s, int idx, unordered_set<string>& dict,
               string curr, vector<string>& result)
    {
        if (idx == s.size())
        {
            if (!curr.empty()) curr.pop_back();
            result.push_back(curr);
            return;
        }
        string word = "";
        for (int i = idx; i < s.size(); i++)
        {
            word += s[i];
            if (dict.count(word))
                solve(s, i + 1, dict, curr + word + " ", result);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> result;
        solve(s, 0, dict, "", result);
        return result;
    }
};