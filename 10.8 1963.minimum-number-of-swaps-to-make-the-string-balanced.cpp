/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSwaps(string s)
    {
        
        int maxbalance=0,balance=0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
                balance--;
            else
                balance++;
            maxbalance = max(balance, maxbalance);
            
        }
        return (maxbalance + 1) / 2;
    }
};
// @lc code=end
