/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
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
    string minWindow(string s, string t)
    {
        unordered_map<char, int> count;
        int left = 0, right = 0, t_count = t.size();
        int ansleft = 0, ansright = s.length() + 1;
        //狦⊿Τ氮穦琌s.len+1

        for (int i = 0; i < t.length(); i++)
            count[t[i]]++;
        //计t
        while (right < s.size())
        {
            if (count[s[right++]]-- > 0)
                t_count--;
            /*
            单
            if (count[s[right]] > 0)
                tcount--;
            count[s[right]]++
            right++;
        
            狦count[s[right]] > 0 s[right]琌tダ
            */

            while (t_count == 0)//tダ常砆т
            {
                //left┕オ埃緇ダ璶Τt┮Τダ碞磅︽
                if (right - left < ansright - ansleft)
                {
                    ansleft = left;
                    ansright = right;
                }
                //金tダ
                if (count[s[left++]]++ == 0)
                    t_count++;
                
            }
        }
        if (ansright - ansleft == s.length() + 1)
            return "";
        else
            return s.substr(ansleft, ansright - ansleft);
    }
};
// @lc code=end
