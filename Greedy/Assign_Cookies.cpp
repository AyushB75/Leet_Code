// Assign Cookies
// Difficulty: Easy | Topic: Greedy | Language: C++
// https://leetcode.com/problems/assign-cookies/
//
// Problem: Each child has a greed factor g[i], each cookie has size
// s[j]. A child is content if assigned cookie size >= greed factor.
// Maximize the number of content children.
//
// Approach: Sort both arrays. Use two pointers — greedily assign
// the smallest sufficient cookie to each child starting from the
// least greedy child.
// Time: O(n log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int count = 0;
        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};