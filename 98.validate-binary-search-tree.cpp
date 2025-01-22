/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool Valid(TreeNode *now, TreeNode *left, TreeNode *right)
    {
        if (!now)
            return true;
        if((left&&now->val<=left->val)||(right&&now->val>=right->val))
            return false;

        return Valid(now->left, left, now)&&Valid(now->right, now, right);
    
    }
    bool isValidBST(TreeNode *root)
    { 
        return Valid(root,nullptr,nullptr);
    }
};
// @lc code=end
