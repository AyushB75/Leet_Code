// Job Sequencing Problem
// Difficulty: Medium | Topic: Greedy | Language: C++
// https://www.geeksforgeeks.org/job-sequencing-problem/
//
// Problem: Given a list of jobs with deadlines and profits, find the
// maximum profit sequence of jobs such that no two jobs overlap and
// each job is completed within its deadline.
//
// Approach: Sort jobs by profit in descending order. For each job,
// find the latest available slot before its deadline and assign it.
// Time: O(n²) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, [](Job a, Job b) {
            return a.profit > b.profit;
        });
        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
            maxDeadline = max(maxDeadline, arr[i].dead);
        vector<int> slots(maxDeadline + 1, -1);
        int count = 0, totalProfit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slots[j] == -1)
                {
                    slots[j] = i;
                    count++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {count, totalProfit};
    }
};