/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
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
class Solution
{
public:
    int countSubstrings(string s)
    {
        // 實作馬拉車
        // 前面加$ 後面加^ 每個字中間前後插# 就不用分奇偶迴文
        string symbol = "$#";
        for (char c : s)
        {
            symbol += c;
            symbol += "#";
        }
        symbol += "^";

        int n = symbol.size();
        vector<int> P(n); // 記每個位置的中心展開迴文長度，長度/2就有幾個子字串
        //

        int Pm = 0, PR = 0, ans = 0;
        //(PL)  Pm  PR
        for (int i = 1; i < n; i++)
        {
            // i有沒有超過Pr
            // 1.1沒超過且P[j]沒超過PL P[i] = P[2 * PL - i] = P[j]
            // 1.2沒超過且P[j]超過PL P[i] = PR - i + 1 之後可以再擴展
            // 2.超過了P[i] = 1 之後可以再擴展
            P[i] = (i <= PR) ? min(P[2 * Pm - i], PR - i + 1) : 1;

            // 擴展，如果1.1不會再擴展
            while (symbol[i + P[i]] == symbol[i - P[i]])
                ++P[i];

            // 如果i的擴展超出PR i就是新的P
            if (i + P[i] - 1 > PR)
            {
                PR = i + P[i] - 1;
                Pm = i;
            }
            ans += P[i] / 2;
        }
       
            return ans;
    }
};
// @lc code=end
