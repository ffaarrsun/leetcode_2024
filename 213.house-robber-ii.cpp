/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
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
    int rob(vector<int> &nums)
    {
        vector<int> mem(nums.size(), -1), mem2(nums.size(), -1);

        if (nums.size() == 1)
            return nums[0];
            
        return max(dp(nums, mem, nums.size() - 1, 1), dp(nums, mem2, nums.size() - 2, 0));
    }

    int dp(vector<int> &nums, vector<int> &mem, int cur, int range)
    {
        if (cur < range)
            return 0;
        if (mem[cur] > -1)
            return mem[cur];

        mem[cur] = max(nums[cur] + dp(nums, mem, cur - 2, range), dp(nums, mem, cur - 1, range));
        return mem[cur];
    }
};
// @lc code=end
