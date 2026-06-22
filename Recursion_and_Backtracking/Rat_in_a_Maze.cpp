// Rat in a Maze
// Difficulty: Hard | Topic: Recursion and Backtracking | Language: C++
// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
//
// Problem: Given an n×n binary maze, find all paths from (0,0) to
// (n-1,n-1). The rat can move Up, Down, Left, Right.
//
// Approach: Backtracking. Mark cell as visited before recursing.
// Unmark on backtrack. Collect path string at destination.
// Time: O(4^(n²)) | Space: O(n²)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int row, int col, vector<vector<int>>& maze, int n,
               vector<string>& result, string path,
               vector<vector<int>>& visited)
    {
        if (row == n-1 && col == n-1)
        {
            result.push_back(path);
            return;
        }
        string dirs = "DLRU";
        int dr[] = {1, 0, 0, -1};
        int dc[] = {0, -1, 1, 0};
        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                !visited[nr][nc] && maze[nr][nc] == 1)
            {
                visited[row][col] = 1;
                solve(nr, nc, maze, n, result, path + dirs[i], visited);
                visited[row][col] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> result;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if (m[0][0] == 0) return result;
        solve(0, 0, m, n, result, "", visited);
        return result;
    }
};