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
    int ans = 0;

    bool dfs(vector<vector<int>> &node, int i, vector<int> &taken)
    {
        if (taken[i] == 2)
            return false;

        if (taken[i] == 1)
            return false;

        taken[i] = 1;
        for (int v : node[i])
            bool tmp = dfs(node, v, taken);

        taken[i] = 2;
        return true;
    }

    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> node(n);
        vector<int> taken(n, 0);
        for (vector<int> v : edges)
        {
            node[v[0]].push_back(v[1]);
            node[v[1]].push_back(v[0]);
        }

        for (int i = 0; i < n; i++)
            if (dfs(node, i, taken))
                ans++;

        return ans;
    }
};
