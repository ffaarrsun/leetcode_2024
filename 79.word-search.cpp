/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
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

using namespace std;
class Solution
{
public:
    
    bool dfs(vector<vector<char>> &board, int i, int j, string word, int now)
    {
        int m = board.size(), n = board[0].size();
        if (now==word.size())
            return true;

        if (i >= m || i < 0 || j >= n || j < 0|| board[i][j] != word[now])
            return false;

        char tmp=board[i][j];
        board[i][j]='#';
        bool yes = (dfs(board, i + 1, j, word, now + 1) || 
                    dfs(board, i, j - 1, word, now + 1) || 
                    dfs(board, i, j + 1, word, now + 1) ||
                    dfs(board, i - 1, j, word, now + 1));
        board[i][j]=tmp;
        return yes;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, i, j, word, 0))
                    return true;
            
        return false;
    }
};
// @lc code=end
