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
    bool cycle(vector<vector<int>> &node, vector<int> &taken, int i)
    {
        if (taken[i] == 1)
            return false;

        taken[i] = 1;
        for (int j : node[i])
            cycle(node, taken, j);

        taken[i] = 2;
        return true;
    }
    bool validTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> node(n);
        vector<int> taken(n, 0);

        if (edges.size() != n - 1)
            return false;

        for (vector<int> v : edges)
        {
            node[v[0]].push_back(v[1]);
            node[v[1]].push_back(v[0]);
        }

        if (!cycle(node, taken, 0))
            return false;

        for (int i : taken)
            if (i != 2)
                return false;

        return true;
    }
};
