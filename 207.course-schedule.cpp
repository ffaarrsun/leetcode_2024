/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
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
#include <set>

using namespace std;

class Solution {
public:
    bool finish( vector<vector<int>> &node,vector<int> &taken,int i)
    {
        if(taken[i] == 1)
            return false;
        if(taken[i] == 2)
            return true;
        
        bool ans = true;
        taken[i] = 1;

        for(int j :node[i])
            if(!finish(node,taken,j))
                ans=false;

        taken[i] = 2;

        return ans;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> taken(numCourses,0);//0代表沒看過，1代表在走，2代表走過
        vector<vector<int>> nodes(numCourses);

        for(vector<int> v :prerequisites)
            nodes[v[0]].push_back(v[1]);
        
        for(int i = 0 ; i < numCourses; i++)
            if(!finish(nodes,taken,i))
                return false;
        
        
        return true;
    }
};
// @lc code=end

