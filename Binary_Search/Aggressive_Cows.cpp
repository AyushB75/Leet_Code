// Aggressive Cows
// Difficulty: Hard | Topic: Binary Search | Language: C++
// https://www.geeksforgeeks.org/aggressive-cows-detailed-solution/
//
// Problem: Given n stall positions and k cows, place cows to
// maximize the minimum distance between any two cows.
//
// Approach: Binary search on answer (min distance) in
// [1, max-min]. For each mid, greedily place cows and check if
// k cows fit with at least mid distance apart.
// Time: O(n log n + n * log(max-min)) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlace(vector<int>& stalls, int dist, int cows)
    {
        int count = 1, last = stalls[0];
        for (int i = 1; i < stalls.size(); i++)
            if (stalls[i] - last >= dist) { count++; last = stalls[i]; }
        return count >= cows;
    }
    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls.back() - stalls.front();
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canPlace(stalls, mid, k)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};