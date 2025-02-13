/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
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
/*
いみ┹甶猭
class Solution
{
public:
    string expandAroundCenter(const string& s, int left, int right)
    {
        while(left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s)
    {
        int ans = 1;
        string longest;

        for (int i = 0; i < s.length(); i++)
        {
            string oddPalindrome = expandAroundCenter(s, i, i);
            if (oddPalindrome.size() > longest.size()) {
                longest = oddPalindrome;
            }

            // 案计ゅ
            string evenPalindrome = expandAroundCenter(s, i, i + 1);
            if (evenPalindrome.size() > longest.size()) {
                longest = evenPalindrome;
            }
        }

        return longest;
    }
};
*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        // 龟皑┰ó
        // 玡$ ^ –い丁玡础# 碞ぃノだ案癹ゅ
        string symbol = "$#";
        for (char c : s)
        {
            symbol += c;
            symbol += "#";
        }
        symbol += "^";

        int n = symbol.size();
        vector<int> P(n); // 癘–竚いみ甶秨癹ゅ/2碞Τ碭﹃
        int Pm = 0, PR = 0, anslen = 0, ansstart = 0;
        string ans = "";

        for (int i = 1; i < n; i++)
        {
            // iΤ⊿Τ禬筁Pr
            // 1.1⊿禬筁P[j]⊿禬筁PL P[i] = P[2 * PL - i] = P[j]
            // 1.2⊿禬筁P[j]禬筁PL P[i] = PR - i + 1 ぇ耎甶
            // 2.禬筁P[i] = 1 ぇ耎甶
            P[i] = (i <= PR) ? min(P[2 * Pm - i], PR - i + 1) : 1;

            while (symbol[i + P[i]] == symbol[i - P[i]])
                ++P[i];

            if (P[i] + i - 1 > PR)
            {
                PR = P[i] + i - 1;
                Pm = i;
            }
            //穝程﹃
            if (anslen < P[i] - 1)
            {
                anslen = P[i] -1;
                ans = s.substr((i - P[i]) / 2, anslen);
            }
        }
        return ans;
    }
};
// @lc code=end
