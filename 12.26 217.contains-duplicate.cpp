/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> arr;
        
        for(int c:nums)
        {
            arr[c]++;
            if(arr[c]>1)
            {
                return true;
            }
                
        }
        return false;
    }
};
// @lc code=end

