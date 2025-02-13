/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
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
    int numDecodings(string s)
    {

        if (s.empty() || s[0] == '0')
            return 0;
        // 前i個字的解法
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < s.length() + 1; i++)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];

            int twodigit = stoi(s.substr(i - 2, 2));
            if (twodigit >= 10 && twodigit <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[s.length()];
    }
};
// @lc code=end
