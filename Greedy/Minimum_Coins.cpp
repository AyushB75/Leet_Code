// Minimum Coins
// Difficulty: Hard | Topic: Greedy | Language: C++
// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-given-value/
//
// Problem: Given a value V and an infinite supply of coins of given
// denominations, find the minimum number of coins required to make
// the value V.
//
// Approach: Greedy approach — pick the largest denomination coin
// that is <= remaining value, repeat until value becomes 0.
// Note: This greedy approach works for canonical coin systems
// (like Indian currency) but not for all denominations.
// Time: O(V) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minimumCoins(int V) {
        vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
        vector<int> result;
        int n = coins.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (V >= coins[i])
            {
                V -= coins[i];
                result.push_back(coins[i]);
            }
        }
        return result;
    }
};