/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
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
#include <unordered_set>

using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());//先sort

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            
            int target = -nums[i];
            int left = i + 1, right = n - 1;//固定最左邊，找右邊兩個
            while (left < right)
            {
                   
                if (nums[left] + nums[right] == target)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;//跳過重複
                    while (right > left && nums[right] == nums[right + 1]) right--;
                }
                else if (nums[left] + nums[right] > target)
                    right--;
                else
                    left++;
            }
            while(i + 1 < n && nums[i] == nums[i + 1])//第一次先做，然後跳過重複 eg. -1 -1
                i++;
        }
        return ans;
    }
};
// @lc code=end
