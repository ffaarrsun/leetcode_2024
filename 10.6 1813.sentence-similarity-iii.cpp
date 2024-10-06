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
        // �N sentence1 �M sentence2 ���ά����
        vector<string> s1, s2;
        stringstream ss1(sentence1), ss2(sentence2);
        string word;
        
        while (ss1 >> word) s1.push_back(word);
        while (ss2 >> word) s2.push_back(word);
        
        // �p�G s1 �� s2 ���A�ڭ̤����A�o�˥i�H�T�O s1 �O����u���y�l
        if (s1.size() > s2.size()) swap(s1, s2);
        
        int i = 0, j = 0; //i�N��s2�e�����X�өMs1�@�ˡAj�N��s2�᭱���X�өMs1�@��
        int n1 = s1.size(), n2 = s2.size();
        
        // �q�e�������ۦP����
        while (i < n1 && s1[i] == s2[i]) i++;
        
        // �q�᩹�e����ۦP����
        while (j < n1 && s1[n1 - j - 1] == s2[n2 - j - 1]) j++;
        
        // �e��+�᭱�n��s1��
        return i + j >= n1;
    }
};

// @lc code=end

