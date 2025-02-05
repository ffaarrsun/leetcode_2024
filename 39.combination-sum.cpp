/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
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
    vector<vector<int>> ans;

    //start是避免重複，如2 2 3,3 2 2這種
    void backtrack(vector<int> &candidates,int target,vector<int> combination,int start)
    {
        if(target == 0)
        {
            ans.push_back(combination);
            return;
        }
        for(int i = start;i<candidates.size();i++)
        {
            if(candidates[i]>target)
                break;
            combination.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],combination,i);
            combination.pop_back();//先拿candidate[i]試試看，試完就拿出來
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());//先sort由小到大，後面太大就不用做了
        vector<int> combination;
        backtrack(candidates,target,combination,0);
        return ans;
    }
};
// @lc code=end

