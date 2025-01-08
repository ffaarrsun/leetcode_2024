/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
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
    int area(int a, int ah, int b, int bh)
    {
        int h = min(ah, bh);
        return h * (b - a);
    }
    int maxArea(vector<int> &height)
    {
        int ans = -1;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            // cout<<area(i, height[i], j, height[j])<<endl;
            /*
            if (area(i, height[i], j, height[i]) < ans)
                break;
            */
            if (area(i, height[i], j, height[j]) > ans)
                ans = area(i, height[i], j, height[j]);
            if (height[i] > height[j])
                j--;
            else
                i++;
        }

        return ans;
    }
};
// @lc code=end
