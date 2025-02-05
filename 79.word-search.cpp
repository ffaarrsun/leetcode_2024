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
class Solution {
public:
    bool dfs()
    {
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m =board.size(),n=board[0].size();
        int check[6][6]={false};

        for(int i=0;i<m;i++)
            for (int j = 0; j < n; j++)
            {
                if(board[i][j]==word[0])
                {
                    int len = word.length()-1;
                    int nowi=i,nowj=j;
                    while (len>0)
                    {
                        if(nowi+1<m)
                    }
                    
                }
            }
            
    }
};
// @lc code=end

