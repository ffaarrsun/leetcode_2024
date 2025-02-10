/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
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
class TrieNode
{
public:
    TrieNode *character[26];
    string word; //記一個字的結尾

    TrieNode() //初始化
    {
        for (int i = 0; i < 26; ++i)
            character[i] = nullptr;
        word = "";
    }
};

class Solution
{
public:
    TrieNode *root;

    Solution()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (!node->character[index])
                node->character[index] = new TrieNode();
            node = node->character[index];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node, vector<string>& result)
    {
        int m = board.size(), n = board[0].size();
        if (i >= m || i < 0 || j >= n || j < 0 || board[i][j] == '#')
            return;

        char tmp = board[i][j];
        int index = tmp-'a';

        if(!node->character[index])
            return;

        node = node->character[index];

        if(!node->word.empty())
        {
            result.push_back(node->word);
            node->word="";
        }

        
        board[i][j] = '#';

        dfs(board, i + 1, j, node, result);
        dfs(board, i - 1, j, node, result);
        dfs(board, i, j + 1, node, result);
        dfs(board, i, j - 1, node, result);

        board[i][j] = tmp;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> result;
        for (string s : words)
            insert(s);

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, root, result);

        return result;
    }
};
// @lc code=end
