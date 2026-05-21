// 234. Palindrome Linked List
// Difficulty: Medium | Topic: Linked List | Language: C++
// https://leetcode.com/problems/palindrome-linked-list/
//
// Problem: Given the head of a linked list, return true if it is a
// palindrome or false otherwise.
//
// Approach: Find middle using slow/fast pointers. Reverse the second
// half. Compare both halves node by node.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        while (head)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = reverse(slow->next);
        ListNode* first = head;
        ListNode* temp = second;
        bool result = true;
        while (temp)
        {
            if (first->val != temp->val) { result = false; break; }
            first = first->next;
            temp = temp->next;
        }
        slow->next = reverse(second);
        return result;
    }
};