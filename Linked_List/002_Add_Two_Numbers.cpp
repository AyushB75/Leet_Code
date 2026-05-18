// 002. Add Two Numbers
// Difficulty: Medium | Topic: Linked List | Language: C++
// https://leetcode.com/problems/add-two-numbers/
//
// Problem: Given two non-empty linked lists representing two non-negative
// integers in reverse order, return the sum as a linked list.
//
// Approach: Traverse both lists simultaneously adding digits with carry.
// Create new node for each digit. Continue until both lists exhausted
// and no carry remains.
// Time: O(max(m,n)) | Space: O(max(m,n))
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummy.next;
    }
};