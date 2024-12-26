/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<pair<int,int>> ans;

        for(int i:nums)
            count[i]++;
        
        for(auto c :count)
            ans.push_back(make_pair(c.first,c.second));
        
        struct cmp //過載的code，大概只能用背的
        {
            bool operator()(pair<int,int> a,pair<int,int> b)
            {
                return a.second<b.second;
            }
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq(ans.begin(),ans.end());
        //要寫一個cmp過載來比較
        vector<int> rans;
        for(int i = 0; i < k; i++)
        {
            rans.push_back(pq.top().first);
            pq.pop();
        }
        
        return rans;
    }
};
// @lc code=end

