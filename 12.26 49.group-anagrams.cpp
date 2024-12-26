/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;//要輸出這個形式
        unordered_map<string,vector<string>> count;

        for(string s : strs)//sort好後依照sort後的樣子分組
        {
            string tmp = s;
            sort(tmp.begin(),tmp.end());
            count[tmp].push_back(s);
        }
        for(auto ch:count)
        {
            ans.push_back(ch.second);
        }
        return ans;
    }
};
// @lc code=end

