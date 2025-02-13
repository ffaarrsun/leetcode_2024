/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
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
    int lengthOfLIS(vector<int>& nums) {

        vector<int> ansv;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it =lower_bound(ansv.begin(),ansv.end(),nums[i]);
            if (it == ansv.end())
                ansv.push_back(nums[i]);
            else
                *it = nums[i];
        }

        return ansv.size();
    }
};
// @lc code=end

