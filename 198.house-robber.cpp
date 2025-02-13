/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
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
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size(),-1);
        return dp(nums.size()-1,mem,nums);
    }

    int dp(int cur,vector<int> &mem,vector<int>& nums)
    {
        if(cur < 0)
            return 0;
        if(mem[cur] >= 0)
            return mem[cur];

        mem[cur] =  max(nums[cur]+dp(cur - 2,mem,nums),dp(cur - 1,mem,nums));
        return mem[cur];
    }
};
// @lc code=end

