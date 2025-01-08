/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
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
#include <unordered_set>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min_price = INT_MAX; // ﹍程基
        int max_profit = 0;      // ﹍程柬
        
        for (int price : prices) {
            // 穝程基
            min_price = min(min_price, price);
            
            // 璸衡讽玡柬穝程柬
            max_profit = max(max_profit, price - min_price);
        }
        
        return max_profit;
    
    }
};
// @lc code=end

