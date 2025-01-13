/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
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
    int search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        //先找旋轉點，同上題
        while (end > start)
        //不用等於，因?縮到start == end，
        //只有一個元素，一定是旋轉點
        {
            int mid = (start + end) / 2;
            if (nums[mid] >= nums[end])
                start = mid + 1;
            else
                end = mid;
        }
        int rotation = start;
        start = 0;
        end = nums.size() - 1;

        while (end >= start) //只有一個元素也要檢查
        {
            int mid = (start + end) / 2;
            int realMid = (mid + rotation) % nums.size();
            if (nums[realMid] == target)
                return (rotation + mid) % nums.size();
            //因?確定mid不可能是答案，可以+1-1
            if (nums[realMid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};
// @lc code=end
