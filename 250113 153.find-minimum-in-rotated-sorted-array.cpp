/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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
#include <stack>

using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)//看著例子比較好寫
    {
        int start = 0, end = nums.size() - 1;
        while (end > start)
        {
            int mid = (start + end) / 2;
            if (nums[mid] >= nums[end])
                start = mid + 1;//要加一
            else
                end = mid;
        }
        return nums[start];
    }
};
// @lc code=end
