// 021. Merge Two Sorted Lists
// Difficulty: Easy | Topic: Linked List | Language: C++
// https://leetcode.com/problems/merge-two-sorted-lists/
//
// Problem: Given heads of two sorted linked lists, merge them into one
// sorted linked list and return the head.
//
// Approach: Use a dummy node. Compare nodes from both lists and attach
// the smaller one to result. Attach remaining nodes at the end.
// Time: O(m+n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};