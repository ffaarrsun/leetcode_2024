/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;
class Solution
{
public:
    int ans = 0;
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == '#' || grid[i][j] == '0')
            return;

        char tmp = grid[i][j];
        grid[i][j] = '#';

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);

        // grid[i][j] = tmp;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // cout<<ans;
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
