/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
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
/*找不重複字母最長的substring，原本想固定左邊，往右找遇到重複的就斷，
左邊再移一格，這樣也過但時間花很多，用sliding window，改成如果遇到重複的，
就把左邊移到沒有重複。*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int right = 0, left = 0;

        unordered_set<char> window;  //用set
        while (right < s.length())
        {
            if (window.find(s[right]) == window.end())
            {
                window.insert(s[right]);
                ans = max(ans, right - left + 1);
                right++;
            }
            // 如果右指標指向的字元不在集合中，加入集合並擴大視窗
            else//如果重複，左邊的剔除直到剔除重複的
            {
                window.erase(s[left]);
                left++;
            }
                
        }

        return ans;
    }
};
// @lc code=end
