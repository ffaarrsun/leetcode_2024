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

class Solution
{
public:
    string foreignDictionary(vector<string> &words)
    {
        unordered_map<char, int> inDegree;
        unordered_map<char, set<char>> node;

        for (const string &word : words)
        {
            for (char c : word)
            {
                node[c] = set<char>(); // 確保每個字母都被加入圖中
                inDegree[c] = 0;       // 初始化所有字母入度為 0
            }
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            string word1 = words[i], word2 = words[i + 1];

            //檢查word1比word2長且word2是word1的前綴
            //如果是，代表排反了，如app apple排成apple app
            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2)
                return "";

            for (int j = 0; j < min(word1.size(), word2.size()); j++)
            {
                if (word1[j] != word2[j])
                {
                    if (!node[word1[j]].count(word2[j]))
                    {
                        node[word1[j]].insert(word2[j]);
                        inDegree[word2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        string ans = "";

        //先把沒有被指的node放進queue
        for (auto entry : inDegree)
            if (entry.second == 0)
                q.push(entry.first);

        while (!q.empty())
        {
            //把做過的點拿走後，變沒有被指的node也放進queue
            char now = q.front();
            q.pop();
            ans += now;
            for (char c : node[now])
            {
                inDegree[c]--;
                if (inDegree[c] == 0)
                    q.push(c);
            }
        }

        //代表有迴圈 放不進去
        if (ans.size() != node.size())
            return "";

        return ans;
    }
};
