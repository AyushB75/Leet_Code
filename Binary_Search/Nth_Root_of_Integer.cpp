// N-th Root of an Integer
// Difficulty: Medium | Topic: Binary Search | Language: C++
// https://www.geeksforgeeks.org/nth-root-of-a-number/
//
// Problem: Given two numbers n and m, find the nth root of m.
// Return -1 if it is not a perfect nth root.
//
// Approach: Binary search on answer in range [1, m]. For each mid,
// compute mid^n and compare with m.
// Time: O(n * log m) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long power(long long mid, int n, int m)
    {
        long long result = 1;
        for (int i = 0; i < n; i++)
        {
            result *= mid;
            if (result > m) return m + 1;
        }
        return result;
    }
    int NthRoot(int n, int m) {
        int low = 1, high = m;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long val = power(mid, n, m);
            if (val == m) return mid;
            else if (val < m) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};