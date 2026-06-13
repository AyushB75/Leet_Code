// Fractional Knapsack
// Difficulty: Medium | Topic: Greedy | Language: C++
// https://www.geeksforgeeks.org/fractional-knapsack-problem/
//
// Problem: Given weights and values of items, find the maximum value
// that can be put in a knapsack of capacity W. Items can be broken.
//
// Approach: Calculate value/weight ratio for each item. Sort by ratio
// in descending order. Greedily pick items with highest ratio first.
// Take fraction of last item if it doesn't fit completely.
// Time: O(n log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, [](Item a, Item b) {
            return (double)a.value / a.weight >
                   (double)b.value / b.weight;
        });
        double totalValue = 0.0;
        int remaining = W;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= remaining)
            {
                totalValue += arr[i].value;
                remaining -= arr[i].weight;
            }
            else
            {
                totalValue += (double)arr[i].value *
                              remaining / arr[i].weight;
                break;
            }
        }
        return totalValue;
    }
};