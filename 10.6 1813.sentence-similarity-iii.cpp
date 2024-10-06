/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
// @lc code=start
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // 將 sentence1 和 sentence2 分割為單詞
        vector<string> s1, s2;
        stringstream ss1(sentence1), ss2(sentence2);
        string word;
        
        while (ss1 >> word) s1.push_back(word);
        while (ss2 >> word) s2.push_back(word);
        
        // 如果 s1 比 s2 長，我們互換，這樣可以確保 s1 是比較短的句子
        if (s1.size() > s2.size()) swap(s1, s2);
        
        int i = 0, j = 0; //i代表s2前面有幾個和s1一樣，j代表s2後面有幾個和s1一樣
        int n1 = s1.size(), n2 = s2.size();
        
        // 從前往後比較相同部分
        while (i < n1 && s1[i] == s2[i]) i++;
        
        // 從後往前比較相同部分
        while (j < n1 && s1[n1 - j - 1] == s2[n2 - j - 1]) j++;
        
        // 前面+後面要比s1長
        return i + j >= n1;
    }
};

// @lc code=end

