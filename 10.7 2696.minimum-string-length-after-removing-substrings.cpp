/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
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
    bool isABorCD(char a, char b)
    {
        if (a == 'A' && b == 'B')
            return true;
        if (a == 'C' && b == 'D')
            return true;
        return false;
    }

    int minLength(string s)
    {
        stack<char> count;
        count.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            // cout<<s[i];
            count.push(s[i]);

            while (count.size() > 1)
            {
                // cout<<count.size()<<" "<<count.top()-1<<" "<<count.top()<<endl;
                char a = count.top(), b;
                count.pop();
                b = count.top();
                count.push(a);

                if (isABorCD(b, a))
                {
                    count.pop();
                    count.pop();
                }
                else
                    break;
            }
        }
        return count.size();
    }
};
// @lc code=end
