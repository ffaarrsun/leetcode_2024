/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
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
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        
        for(int i = 0; i < s.length();i++)
        {
            if(s[i] =='('||s[i] == '{'||s[i] == '[')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                if(st.top()=='('&&s[i]!=')')
                    return false;
                if(st.top()=='{'&&s[i]!='}')
                    return false;
                if(st.top()=='['&&s[i]!=']')
                    return false;
                st.pop();
            }
        }
        return st.empty();

    }
};
// @lc code=end

