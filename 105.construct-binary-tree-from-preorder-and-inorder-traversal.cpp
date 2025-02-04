/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    /*struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };*/

    TreeNode *buildTree(unordered_map<int, int> &mp, vector<int> &preorder, int &preindex, int left, int right)
    {
        if (left > right)
            return nullptr;
        // left == right ?leaf

        int rootval = preorder[preindex++];
        // preorder一個個找

        int index = mp[rootval];
        TreeNode *cur = new TreeNode(rootval);
        cur->left = buildTree(mp, preorder, preindex, left, index - 1);
        cur->right = buildTree(mp, preorder, preindex, index + 1, right);

        return cur;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        // 用mp裝inorder，找的時候才快
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int preindex = 0;
        TreeNode *root = buildTree(mp, preorder, preindex, 0, preorder.size() - 1);
        return root;
    }
};
// @lc code=end
