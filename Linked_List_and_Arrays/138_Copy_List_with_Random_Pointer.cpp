// 138. Copy List with Random Pointer
// Difficulty: Hard | Topic: Linked List & Arrays | Language: C++
// https://leetcode.com/problems/copy-list-with-random-pointer/
//
// Problem: Construct a deep copy of a linked list where each node has
// a next and a random pointer.
//
// Approach: Insert cloned nodes between original nodes. Set random
// pointers for cloned nodes. Then separate the two lists.
// Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr)
        {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }
        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node* dummy = new Node(0);
        Node* copy = dummy;
        while (curr)
        {
            copy->next = curr->next;
            curr->next = curr->next->next;
            copy = copy->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};