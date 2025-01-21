/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
class Solution
{
public:
    
    /* BFS
    int ans = 0;
    void depth(TreeNode *now, int count)
    {
        if (now->left)
            depth(now->left, count + 1);
        if (now->right)
            depth(now->right, count + 1);

        ans = (count > ans) ? count : ans;
    }
    */
    //DFS
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxleft = maxDepth(root->left);
        int maxright = maxDepth(root->right);
        return max(maxleft, maxright) + 1;         
    }
};
// @lc code=end
