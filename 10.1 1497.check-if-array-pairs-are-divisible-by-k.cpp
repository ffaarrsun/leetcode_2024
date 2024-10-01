/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */

// @lc code=start
class Solution {
private:
    unordered_map<int,int> count;
public:
    bool canArrange(vector<int>& arr, int k) {
        for(const auto x:arr)
            count[(x+10000*k)%k]++;  //偷吃步，應該要是x % k; x?負則x+k; 
        
        if(count[0]%2!=0)
            return false;
        for(int i=1;i<k/2+1;i++)
        {
            if(count[i]!=count[k-i])
                return false;
        }
        return true;

    }
};
// @lc code=end

