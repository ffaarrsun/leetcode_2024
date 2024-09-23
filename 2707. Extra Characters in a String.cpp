class Solution {
public:
    vector<int> DP;
    int minExtraChar(string s, vector<string>& dictionary) {
        /*vector<string> tmp=dictionary;
        for(int i=0;<s.size(),i++)
        {
            for(int j=0;j<dictionary.size();j++)
            {
                if(s[i]==dictionary[j][0])
                    vector
            }

        }
        int fmin(int a)
        {
            if(a==s.size()-1)
                return 
            return fmin()
        }*/
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        // dp[i] 表示到位置 i 的時候最少的多餘字母數
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        // 遍歷字符串的每個位置
        for (int i = 1; i <= n; ++i) {
        // 嘗試所有可能的子字符串 s[j:i]
        for (int j = 0; j < i; ++j) {
            if (dict.count(s.substr(j, i - j))) { //count看括號內的東西有沒有在dict裡，有1沒0 //substr從j位開始截取i-j個字
                dp[i] = min(dp[i], dp[j]);
            }
        }
        dp[i] = min(dp[i], dp[i-1] + 1);  // 如果不能匹配，至少要多留一個字母
        }

        return dp[n];
    }
    
};
