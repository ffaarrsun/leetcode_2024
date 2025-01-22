/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        /*
        舊方法，找出p q 的所有祖先，挑一個（q)從q開始往祖先一個一個對
        是不是p的祖先，是就找到了
        vector<TreeNode *> q_ancestor;
        unordered_set<TreeNode *> p_set;
        TreeNode *now = root;
        while (now->val != q->val)
        {
            q_ancestor.push_back(now);
            now=(now->val > q->val)? now->left:now->right;
        }
        now = root;
        while (now->val != p->val)
        {
            p_set.insert(now);
            now=(now->val > p->val)? now->left:now->right;
        }
        q_ancestor.push_back(q);
        p_set.insert(p);

        int i = q_ancestor.size() - 1;
        now=q_ancestor[i];
        while (p_set.find(now) == p_set.end())//沒找到
            now = q_ancestor[--i];

        return now;
        */

       //新方法，如果now比兩個數都大代表要往左子走，都小往右子走，一樣即答案
        int small = min(p->val, q->val), large = max(p->val, q->val);
        TreeNode *now = root;
        while (now->val > large || now->val < small)
        {
            if (now->val > large)
                now = now->left;
            else
                now = now->right;
        }

        return now;
    }
};
// @lc code=end
