/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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

using namespace std;
class Codec
{
public:
    vector<int> order;
    // Encodes a tree to a single string.
    void preorder(TreeNode *root)
    {
        if (!root)
            return;
        order.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    string serialize(TreeNode *root)
    {
        preorder(root);
        string ans;
        for (int i : order)
        {
            ans += to_string(i);
            ans += ",";
        }
        if (!ans.empty())
            ans.pop_back();
        //cout<<ans;
        return ans;
    }

    vector<int> split(string data)
    {
        vector<int> value;
        stringstream ss(data);
        string token;
        while(getline(ss,token,','))
            value.push_back(stoi(token));
        return value;
    }
    TreeNode *buildBST(vector<int> &values, int &index, int minVal, int maxVal)
    {
        if (index >= values.size())
            return nullptr;

        int val = values[index];

        if (val < minVal || val > maxVal)
            return nullptr;
        TreeNode *node = new TreeNode(val);
        index++;

        node->left = buildBST(values, index, minVal, val - 1);
        node->right = buildBST(values, index, val + 1, maxVal);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;
        vector<int> values = split(data);
        int index = 0;
        return buildBST(values, index, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
