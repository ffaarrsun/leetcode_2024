/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();//用dp
        //假設題目8 7 9 6
        //分別記左右兩邊的乘積，可以用上一個乘nums得到下一個乘積
        //8 7 9 6
        //  ------
        //--  ----
        //----  --
        //------ 
        vector <int> ans(n);
        vector <int> left(n);
        vector <int> right(n);
        left[0]=1; right[n-1]=1;

        for(int i = 1 ;i < n; i++)
            left[i]=left[i-1]*nums[i-1];
        
        for(int i = n-2 ;i > -1; i--)
            right[i]=right[i+1]*nums[i+1];

        for(int i = 0 ;i < n; i++)    
            ans[i]=left[i]*right[i];
        
        return ans;
    }
};
// @lc code=end

