/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //vector <string> arr1n(arr1.begin(),arr1.end()),arr2n(arr2.begin(),arr2.end())
        unordered_set<string> x,y;
        for(int i = 0; i < arr1.size(); ++i )
        {
            string tmp=to_string(arr1[i]);
            for (int j = 0; j <=tmp.size(); j++)
            {
                if(!x.count(tmp.substr(0,j)))
                    x.insert(tmp.substr(0,j));
            }  
        }

        for(int i = 0; i < arr2.size(); ++i )
        {
            string tmp=to_string(arr2[i]);
            for (int j = 0; j <= tmp.size(); j++)
            {
                if(!y.count(tmp.substr(0,j)))
                    y.insert(tmp.substr(0,j));
            }
        }
        int ans=-1;
        
        for (const auto &s:y)
        {
            int tmp=s.size();
            if(x.count(s)&&tmp>=ans)
            {
                ans=tmp;
                //cout<<s<<" "<<s.size()<<" ";
            }
           
        }
        
        return ans;
        //return 0;
    }
};
// @lc code=end

