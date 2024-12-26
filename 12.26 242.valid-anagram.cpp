/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char , int> arrs,arrt;
        for(char c:s) //遍歷string
        {
            arrs[c]++;
        }
        for(char c:t)
        {
            arrt[c]++;
        }
 
        for(const auto &s : arrs)//const因?key是const，避免修改key值，&代表called by reference，不會做副本，不浪費記憶體
        //但其實不加這兩個也行
        {
            if(s.second!=arrt[s.first])
                return false;
        }
        for(const auto &s : arrt)
        {
            if(s.second!=arrs[s.first])
                return false;
        }
        return true;
        //其實可以只建一個map，第一個加第二個減，是零就對了
    }
};
// @lc code=end

