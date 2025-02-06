/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
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
class TrieNode
{
public:
    bool isEnd;
    TrieNode *character[26];
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            character[i] = nullptr;
        isEnd=false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (!node->character[index])
                node->character[index] = new TrieNode();
            node = node->character[index];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (!node->character[index])
                return false;
            node = node->character[index];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            int index = c - 'a';
            if (!node->character[index])
                return false;
            node = node->character[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
