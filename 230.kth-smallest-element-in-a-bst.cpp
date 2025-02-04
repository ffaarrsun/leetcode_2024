/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    vector<int> inorder;
    void kth(TreeNode *root)
    {
        if (root->left)
            kth(root->left);
        inorder.push_back(root->val);
        if (root->right)
            kth(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        kth(root);
        return inorder[k - 1];
    }
};
// @lc code=end
