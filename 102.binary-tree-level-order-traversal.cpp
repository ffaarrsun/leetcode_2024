/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
class Solution
{
public:
    vector<vector<int>> ans;
    void Build_order(TreeNode *now,int depth)
    {
        if(!now)
            return;
        if(ans.size()==depth)
            ans.push_back(vector<int>());

        ans[depth].push_back(now->val);
        Build_order(now->left,depth+1);
        Build_order(now->right,depth+1);
        
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    { 
        Build_order(root,0);
        return ans;
    }
};
// @lc code=end
