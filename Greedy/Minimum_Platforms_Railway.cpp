// Minimum Number of Platforms Required for a Railway Station
// Difficulty: Medium | Topic: Greedy | Language: C++
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
//
// Problem: Given arrival and departure times of trains, find the minimum
// number of platforms required so no train waits.
//
// Approach: Sort both arrays. Use two pointers to track overlapping
// trains at any time. Track max platforms needed simultaneously.
// Time: O(n log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int platforms = 1, maxPlatforms = 1;
        int i = 1, j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                platforms++;
                i++;
            }
            else
            {
                platforms--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }
};