/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
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
    unordered_map <Node*,Node*> mp;

    Node* cloneGraph(Node* node) { //看node有沒有複製過，沒有就複製
        if(!node) //空圖
            return nullptr;
        if(mp.find(node)!=mp.end()) //複製過了
            return mp[node];
        //複製程序
        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for(Node* n :node->neighbors)
            newNode->neighbors.push_back(cloneGraph(n));

        return newNode;
    }
};
// @lc code=end

