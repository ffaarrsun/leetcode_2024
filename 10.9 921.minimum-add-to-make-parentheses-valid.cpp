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
                left++; // �W�[���ǰt�����A��
            } else {
                if(left > 0) {
                    left--; // ���ǰt�����A��
                } else {
                    right++; // �S���ǰt�����A���A�k�A���ݭn���J
                }
            }
        }
        
        return left + right; // ���ǰt�����A���M�k�A�����M
    }
};

// @lc code=end

