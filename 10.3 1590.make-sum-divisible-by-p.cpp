/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
class Solution {
private:
    unordered_map<int,int> lastR;

public:
    int minSubarray(vector<int>& nums, int p) {
        int sum=0;
        int sumR;
        for(const auto x : nums)
        {
            sum+=x;
            sum%=p;
        }
        sumR =sum % p;
        if (sumR == 0)
            return 0;
        int tmpsum,minilen=nums.size();
        lastR[0]=-1;

        for (int i = 0; i < nums.size(); i++)
        {
            tmpsum = (tmpsum + nums[i]) % p;
            int rmod = (tmpsum - sumR + p) % p;

            if(lastR.find(rmod)!=lastR.end())
            {
                int prei= lastR[rmod];
                minilen=min(minilen,i-prei);
            }

            lastR[tmpsum] = i;
        }

        return minilen == nums.size() ? -1 : minilen;

        

    }
};
// @lc code=end

