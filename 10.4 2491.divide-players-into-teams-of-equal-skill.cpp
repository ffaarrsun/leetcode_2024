/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int total=0;
        for(auto x : skill)
            total+=x;
        if ((total % (skill.size() / 2)) != 0) 
            return -1;
        int addsum=total / (skill.size() / 2);
        sort(skill.begin(), skill.end());

        vector <int> sorted(skill.begin(), skill.end());
        int n = sorted.size();
        long long chemistry=0;

        for(int i = 0; i < n / 2;++i )
        {
            if(sorted[i]+sorted[n-i-1] != addsum)
                return -1;
            chemistry+=sorted[i]*sorted[n-i-1];
        }
        return chemistry;
    }
};
// @lc code=end

