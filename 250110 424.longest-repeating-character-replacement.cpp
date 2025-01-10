/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
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
    int characterReplacement(string s, int k)
    {
        unordered_map<int, int> count;
        int ans = 0, left = 0, right = 0;
        /*
        sliding window好難
        給s，改k個字母讓一格子字串有最長一樣的字母，像是把AABA的B改成A就長4。
        換個方法想，如果要讓整個s改成一樣字母，最少k是S.len-最常出現的字母。
        題目等於找的一個子字串，要改的字母?k。
        設left right從0開始，right往右，看現在哪個字母出現頻率最高，
        right-left+1(字串長）-最常出現的字母>k的話，left往右移，直到?k
        這樣移雖然最常出現的字母可能會換，但我們希望子字串越大越好。就不用改。
        */
        int max_freq = 0;
        for (int right = 0; right < s.length(); ++right)
        {
            count[s[right]]++;
            max_freq = max(max_freq, count[s[right]]);
            while ((right - left + 1) - max_freq > k)
            {
                count[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
