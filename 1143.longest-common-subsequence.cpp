/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
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
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[i][j]代表text1前i個字母和text2前j個字母的LCS

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                // 如果一樣，扣掉一樣的再繼續做
                // eg LCS("ace", "abcde") = 1 + LCS("ac", "abcd")
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                // 不一樣，看text1去掉一個還是text2去掉一個比哪個比較長
                // eg LCS("ac", "abcd") = Max(LCS("a", "abcd"), LCS("ac", "abc"))
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
