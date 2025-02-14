/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
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
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0], cursum = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            cursum = max(nums[i],cursum + nums[i]);
            maxsum = max(maxsum,cursum);
        }
        return maxsum;
    }
};
// @lc code=end

