/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
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
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long long ans = 1;             // 避免溢位
        int small = min(m - 1, n - 1); // 只需計算 C(m+n-2, min(m-1, n-1))

        for (int i = 1; i <= small; i++)
        {
            ans = ans * (m + n - 2 - (i - 1)) / i;
        }

        return (int)ans;
    }
};

// @lc code=end
