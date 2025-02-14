/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
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
    bool canJump(vector<int> &nums)
    {
        //方法1從終點推算
        /*
        int n = nums.size();
        vector<bool> dp(n, false);
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] + i < n - 1)
            {
                for (int j = 0; j <= nums[i]; j++)
                    if (dp[j + i])
                    {
                        dp[i] = dp[j + i];
                        break;
                    } 
            }
            else
                dp[i] = true;
        }

        return dp[0];
        */
       //方法2
       //代表能到哪格，目標n-1
       int maxdis = nums[0];
       int n = nums.size();
       for(int i = 0; i <= maxdis;i++)
       {
            if(maxdis >= n-1)
                return true;
            maxdis = max(maxdis,nums[i]+i);
       }

       return false;
    }
};
// @lc code=end
