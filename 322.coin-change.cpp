/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
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
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;

        for(int i = 1; i < amount + 1; i++)
            for(int c : coins)
                if (i >= c)
                    dp[i] = min(dp[i-c]+1,dp[i]);
            
        

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
// @lc code=end

