// 61. Rotate List
// Difficulty: Hard | Topic: Linked List & Arrays | Language: C++
// https://leetcode.com/problems/rotate-list/
//
// Problem: Given the head of a linked list, rotate the list to the
// right by k places.
//
// Approach: Find length and connect tail to head making it circular.
// Then move to (len - k % len - 1)th node and break the circle there.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* tail = head;
        int len = 1;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k % len;
        int steps = len - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < steps; i++)
            newTail = newTail->next;
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};