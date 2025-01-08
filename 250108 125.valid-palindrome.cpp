/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
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
    bool isPalindrome(string s)
    {
        string ns = "";
        for (char c : s)// ascii¤j·§­n­I
        {
            if ((c < 123 && c > 96) || (c < 58 && c > 47))
                ns += c;
            if (c < 91 && c > 64)
                ns += (c + 32);
        }

        // cout<<ns;
        if (ns == "")
            return true;

        for (int i = 0; i < ns.length() / 2 + 1; i++)
        {
            // cout<<ns[i] <<" "<< ns[ns.length()-i-1]<<endl;
            if (ns[i] != ns[ns.length() - i - 1])
                return false;
        }

        return true;
    }
};
// @lc code=end
