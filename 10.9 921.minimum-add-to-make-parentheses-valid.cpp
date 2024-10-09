/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;
// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0, right = 0;
        
        for(char c : s) {
            if(c == '(') {
                left++; // 增加未匹配的左括號
            } else {
                if(left > 0) {
                    left--; // 找到匹配的左括號
                } else {
                    right++; // 沒有匹配的左括號，右括號需要插入
                }
            }
        }
        
        return left + right; // 未匹配的左括號和右括號之和
    }
};

// @lc code=end

