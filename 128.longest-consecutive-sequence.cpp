/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
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
#include <unordered_set>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> set;
        
        for(int num : nums){
            set.insert(num);
        }

        for(int i : set)
        {
            if(set.find(i-1)==set.end()) //確保現在的數最小
            {
                int tmp = 1, tmpi = i + 1;
                //unordered_set<int>::iterator it=find(set.begin(),set.end(),tmpi);
                //用it好像會遍歷，TLC
                while(set.find(tmpi)!=set.end())
                {
                    tmpi++;
                    tmp++;
                }

                if(tmp > ans)
                    ans=tmp;
            }
        }
        return ans;
    }
};
// @lc code=end

