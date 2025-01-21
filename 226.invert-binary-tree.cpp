/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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

using namespace std;
class Solution
{
public:
    void invert(TreeNode *now)
    {
        TreeNode *tmp = now->left;

        now->left = now->right;
        now->right = tmp;

        if (now->left)
            invert(now->left);
        if (now->right)
            invert(now->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        invert(root);
        return root;
    }
};
// @lc code=end
