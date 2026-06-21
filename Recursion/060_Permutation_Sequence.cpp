// 60. Permutation Sequence
// Difficulty: Medium | Topic: Recursion | Language: C++
// https://leetcode.com/problems/permutation-sequence/
//
// Problem: Given n and k, return the kth permutation sequence of
// numbers 1 to n.
//
// Approach: Use factorial number system. At each step, determine
// which number goes in the current position by dividing k by
// (n-1)! and picking that index from the remaining numbers.
// Time: O(n²) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1);
        vector<int> nums;
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = fact[i-1] * i;
            nums.push_back(i);
        }
        k = k - 1;
        string result = "";
        for (int i = n; i >= 1; i--)
        {
            int idx = k / fact[i-1];
            result += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            k = k % fact[i-1];
        }
        return result;
    }
};