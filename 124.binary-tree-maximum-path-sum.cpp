/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
  /*  struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
    };*/
    int count(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;
        int left = max(count(root->left, ans), 0);
        int right = max(count(root->right, ans), 0);
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        count(root, ans);
        return ans;
    }
};
// @lc code=end
