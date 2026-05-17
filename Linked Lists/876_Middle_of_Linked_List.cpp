// 876. Middle of the Linked List
// Difficulty: Easy | Topic: Linked List | Language: C++
// https://leetcode.com/problems/middle-of-the-linked-list/
//
// Problem: Given the head of a singly linked list, return the middle node.
// If there are two middle nodes, return the second middle node.
//
// Approach: Floyd's slow and fast pointer. Fast moves 2 steps, slow moves
// 1 step. When fast reaches end, slow is at the middle.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};