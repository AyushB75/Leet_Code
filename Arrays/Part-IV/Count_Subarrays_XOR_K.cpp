// Count Subarrays with Given XOR K
// Difficulty: Medium | Topic: Arrays Part-IV | Language: C++
// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/
//
// Problem: Given an array and integer k, count the number of subarrays
// whose XOR of elements equals k.
//
// Approach: Use prefix XOR with hash map. For each index, if (prefixXOR ^ k)
// exists in map, add its count to result. Similar to subarray sum = k.
// Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int currXOR = 0, count = 0;
        for (int num : nums)
        {
            currXOR ^= num;
            if (prefixCount.count(currXOR ^ k))
            {
                count += prefixCount[currXOR ^ k];
            }
            prefixCount[currXOR]++;
        }
        return count;
    }
};