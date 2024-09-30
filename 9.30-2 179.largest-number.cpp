/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    static bool compare(int a,int b)  //給sort用
    {
        string as = to_string(a);
        string bs = to_string(b);
        return as + bs > bs + as;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Solution::compare);//Solution::compare的用法記起來
        
        if(to_string(nums[0]) == "0")
            return "0";

        string ans="";
        for(int num:nums)
            ans+=to_string(num);

            return ans;
    }
};
// @lc code=end

