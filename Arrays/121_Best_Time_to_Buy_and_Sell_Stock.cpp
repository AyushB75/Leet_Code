// 121. Best Time to Buy and Sell Stock
// Difficulty: Easy | Topic: Arrays | Language: C++
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//
// Problem: Given an array prices where prices[i] is the price of a stock
// on day i, return the maximum profit from a single buy and sell.
// If no profit is possible, return 0.
//
// Approach: Track the minimum price seen so far. At each step calculate
// profit if sold today and update maximum profit accordingly.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else if (prices[i] - minPrice > maxProfit)
            {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};
