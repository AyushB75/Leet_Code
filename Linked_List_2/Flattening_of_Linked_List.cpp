// Flattening a Linked List
// Difficulty: Hard | Topic: Linked List | Language: C++
// https://www.geeksforgeeks.org/flattening-a-linked-list/
//
// Problem: Given a linked list where each node has a next and a child
// pointer. Child pointers point to a separate linked list (sorted).
// Flatten the list so all nodes appear in a single sorted linked list.
//
// Approach: Recursively flatten from the last column backwards.
// Merge two sorted linked lists at each step using the child pointer.
// Time: O(n*m) | Space: O(n) recursion stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Node* merge(Node* a, Node* b)
    {
        if (!a) return b;
        if (!b) return a;
        Node* result;
        if (a->data <= b->data)
        {
            result = a;
            result->child = merge(a->child, b);
        }
        else
        {
            result = b;
            result->child = merge(a, b->child);
        }
        result->next = nullptr;
        return result;
    }
    Node* flatten(Node* root) {
        if (!root || !root->next) return root;
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};