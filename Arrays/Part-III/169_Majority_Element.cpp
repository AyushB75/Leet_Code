// 169. Majority Element
// Difficulty: Easy | Topic: Arrays Part-III | Language: C++
// https://leetcode.com/problems/majority-element/
//
// Problem: Given an array nums of size n, return the element that appears
// more than n/2 times. The majority element always exists in the array.
//
// Approach: Boyer-Moore Voting Algorithm. Maintain a candidate and a count.
// If count is 0, update candidate. If current element matches candidate
// increment count, else decrement. The final candidate is the majority element.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, c = 0;
        for (int num : nums)
        {
            if (c == 0)
            {
                candidate = num;
            }
            if (num == candidate)
            {
                c++;
            }
            else
            {
                c--;
            }
        }
        return candidate;
    }
};
