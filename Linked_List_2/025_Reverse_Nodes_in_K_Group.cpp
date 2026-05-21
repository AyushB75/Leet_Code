// 25. Reverse Nodes in k-Group
// Difficulty: Hard | Topic: Linked List | Language: C++
// https://leetcode.com/problems/reverse-nodes-in-k-group/
//
// Problem: Given a linked list, reverse the nodes of the list k at a
// time and return the modified list. If nodes are not a multiple of k
// then leave the remaining nodes as is.
//
// Approach: Check if k nodes exist ahead. If yes, reverse k nodes
// recursively and connect with the rest of the list.
// Time: O(n) | Space: O(n/k) recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k)
        {
            curr = curr->next;
            count++;
        }
        if (count < k) return head;
        ListNode* prev = nullptr;
        ListNode* node = head;
        for (int i = 0; i < k; i++)
        {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};