// 206. Reverse Linked List
// Difficulty: Easy | Topic: Linked List | Language: C++
// https://leetcode.com/problems/reverse-linked-list/
//
// Problem: Given the head of a singly linked list, reverse the list
// and return the reversed list.
//
// Approach: Iterative approach with three pointers - prev, curr, next.
// At each step, reverse the link and move all three pointers forward.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};