/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
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
    vector<vector<int>> ans;

    void dfs(vector<vector<int>> &heights, int i, int j, int num, vector<vector<bool>> &sea)
    {
        int m = heights.size(), n = heights[0].size();
        if (i >= m || i < 0 || j >= n || j < 0 || sea[i][j])
            return;
        if (num > heights[i][j])
            return;
        sea[i][j] = true;

        dfs(heights, i - 1, j, heights[i][j], sea);
        dfs(heights, i, j - 1, heights[i][j], sea);
        dfs(heights, i + 1, j, heights[i][j], sea);
        dfs(heights, i, j + 1, heights[i][j], sea);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        // vectorªì©l¤Æ
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), alantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            dfs(heights, i, 0, heights[i][0], pacific);
        for (int j = 0; j < n; j++)
            dfs(heights, 0, j, heights[0][j], pacific);

        for (int i = 0; i < m; i++)
            dfs(heights, i, n - 1, heights[i][n - 1], alantic);
        for (int j = 0; j < n; j++)
            dfs(heights, m - 1, j, heights[m - 1][j], alantic);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && alantic[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};
// @lc code=end
