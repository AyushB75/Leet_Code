// 019. Remove Nth Node From End of List
// Difficulty: Medium | Topic: Linked List | Language: C++
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
// Problem: Given the head of a linked list, remove the nth node from
// the end of the list and return its head.
//
// Approach: Two pointer technique. Move fast pointer n steps ahead.
// Then move both slow and fast together until fast reaches end.
// Slow will be at the node just before the target node.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};