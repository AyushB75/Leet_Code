// Find the Intersection Point of Y LL
// Difficulty: Medium | Topic: Linked List | Language: C++
// https://leetcode.com/problems/intersection-of-two-linked-lists/
//
// Problem: Find the node where two linked lists intersect.
// Return null if no intersection.
//
// Approach: Two pointer technique. When pointer a reaches end, redirect
// to head of b. When pointer b reaches end, redirect to head of a.
// They meet at intersection point (or null if none).
// Time: O(m+n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};