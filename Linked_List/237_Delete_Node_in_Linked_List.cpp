// 237. Delete Node in a Linked List
// Difficulty: Medium | Topic: Linked List | Language: C++
// https://leetcode.com/problems/delete-node-in-a-linked-list/
//
// Problem: Given only the node to be deleted (not the head), delete it
// from the linked list in O(1) time.
//
// Approach: Copy the value of the next node into the current node,
// then delete the next node. This effectively removes the current node.
// Time: O(1) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};