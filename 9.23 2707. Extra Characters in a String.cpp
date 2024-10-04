class Solution {
public:
    vector<int> DP;
    int minExtraChar(string s, vector<string>& dictionary) {
      
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        //從vector換到set

        // dp[i] 表示到位置 i 的時候最少的多餘字母數
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        // 遍歷字符串的每個位置
        for (int i = 1; i <= n; ++i) {
        // 嘗試所有可能的子字符串 s[j:i]
        for (int j = 0; j < i; ++j) {
            if (dict.count(s.substr(j, i - j))) { //count看括號內的東西有沒有在dict裡，有1沒0 //substr從j位開始截取i-j個字
                dp[i] = min(dp[i], dp[j]); //如果i-j這段在字典裡，那有沒有這段剩餘字母s都是一樣的
            }
        }
        dp[i] = min(dp[i], dp[i-1] + 1);  // 如果不能在字典裡，至少要多留一個字母
        }

        return dp[n];
    }
    
};