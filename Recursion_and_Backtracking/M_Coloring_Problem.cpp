// M Coloring Problem
// Difficulty: Hard | Topic: Recursion and Backtracking | Language: C++
// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
//
// Problem: Given an undirected graph and m colors, determine if the
// graph can be colored using at most m colors such that no two
// adjacent vertices share the same color.
//
// Approach: Backtracking. Try assigning each color to current node.
// If no adjacent node has the same color, recurse on next node.
// Time: O(m^v) | Space: O(v)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int node, vector<vector<int>>& graph,
                vector<int>& color, int col, int n)
    {
        for (int i = 0; i < n; i++)
            if (graph[node][i] && color[i] == col) return false;
        return true;
    }
    bool solve(int node, vector<vector<int>>& graph, int m,
               int n, vector<int>& color)
    {
        if (node == n) return true;
        for (int col = 1; col <= m; col++)
        {
            if (isSafe(node, graph, color, col, n))
            {
                color[node] = col;
                if (solve(node + 1, graph, m, n, color)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(vector<vector<int>>& graph, int m, int n) {
        vector<int> color(n, 0);
        return solve(0, graph, m, n, color);
    }
};