// 142. Linked List Cycle II
// Difficulty: Medium | Topic: Linked List | Language: C++
// https://leetcode.com/problems/linked-list-cycle-ii/
//
// Problem: Given a linked list, return the node where the cycle begins.
// Return null if there is no cycle.
//
// Approach: Floyd's cycle detection algorithm. Use slow and fast pointers
// to detect collision. Then reset slow to head and move both one step
// at a time until they meet — that's the cycle start.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};