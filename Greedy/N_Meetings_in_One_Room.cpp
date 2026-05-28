// N Meetings in One Room
// Difficulty: Medium | Topic: Greedy | Language: C++
// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
//
// Problem: Given n meetings with start and end times, find the maximum
// number of meetings that can be held in one room.
//
// Approach: Sort meetings by end time. Greedily pick meetings that
// start after the last selected meeting ends.
// Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int,int>> meetings;
        for (int i = 0; i < n; i++)
            meetings.push_back({end[i], start[i]});
        sort(meetings.begin(), meetings.end());
        int count = 1;
        int lastEnd = meetings[0].first;
        for (int i = 1; i < n; i++)
        {
            if (meetings[i].second > lastEnd)
            {
                count++;
                lastEnd = meetings[i].first;
            }
        }
        return count;
    }
};