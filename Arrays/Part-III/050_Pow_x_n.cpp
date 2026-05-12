// 050. Pow(x, n)
// Difficulty: Medium | Topic: Arrays Part-III | Language: C++
// https://leetcode.com/problems/powx-n/
//
// Problem: Implement pow(x, n) which calculates x raised to the power n.
//
// Approach: Fast exponentiation (Binary Exponentiation). If n is even,
// square the base and halve n. If odd, multiply result by base.
// Handle negative n by taking reciprocal.
// Time: O(log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        long long power = n;
        if (power < 0)
        {
            x = 1 / x;
            power = -power;
        }
        while (power > 0)
        {
            if (power % 2 == 1)
            {
                result *= x;
            }
            x *= x;
            power /= 2;
        }
        return result;
    }
};