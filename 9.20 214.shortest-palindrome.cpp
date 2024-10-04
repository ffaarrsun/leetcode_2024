/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution {
private:
public:
    string shortestPalindrome(string s) {
        vector<int> kmp;
        string rev=string(s.rbegin(),s.rend());
        string newS=s+"#"+rev;
         /*  */
    }
};
// @lc code=end

