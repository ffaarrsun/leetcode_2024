/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char, int> m1,m2;
        if(s1.length() > s2.length())
            return false;
        
        for(int i = 0; i < s1.length(); ++i)
        {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
            
        if(m1 == m2)  
            return true;
            
        for(int i = s1.length(); i < s2.length(); ++i)
        {
            m2[s2[i]]++;
            m2[s2[i-s1.length()]]--;
            // �p�G�Y�Ӧr�Ū��W�v�ܬ� 0�A�h�q map ������
            if (m2[s2[i - s1.length()]] == 0) 
                m2.erase(s2[i - s1.length()]);
            if(m1 == m2)
                return true;
            
        }
        return false;

    }
};
// @lc code=end

