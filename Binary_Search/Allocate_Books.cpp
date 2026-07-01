// Allocate Books
// Difficulty: Hard | Topic: Binary Search | Language: C++
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/
//
// Problem: Given n books with pages and m students, allocate
// contiguous books minimizing the max pages any student gets.
//
// Approach: Binary search on answer in [max(arr), sum(arr)]. For
// each mid, greedily count students needed keeping totals <= mid.
// Time: O(n * log(sum-max)) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& arr, int pages)
    {
        int students = 1, pagesNow = 0;
        for (int p : arr)
        {
            if (pagesNow + p > pages) { students++; pagesNow = p; }
            else pagesNow += p;
        }
        return students;
    }
    int findPages(vector<int>& arr, int n, int m) {
        if (m > n) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (countStudents(arr, mid) > m) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};