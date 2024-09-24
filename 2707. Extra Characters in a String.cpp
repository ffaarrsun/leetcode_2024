class Solution {
public:
    vector<int> DP;
    int minExtraChar(string s, vector<string>& dictionary) {
      
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        //�qvector����set

        // dp[i] ��ܨ��m i ���ɭԳ̤֪��h�l�r����
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        // �M���r�Ŧꪺ�C�Ӧ�m
        for (int i = 1; i <= n; ++i) {
        // ���թҦ��i�઺�l�r�Ŧ� s[j:i]
        for (int j = 0; j < i; ++j) {
            if (dict.count(s.substr(j, i - j))) { //count�ݬA�������F�観�S���bdict�̡A��1�S0 //substr�qj��}�l�I��i-j�Ӧr
                dp[i] = min(dp[i], dp[j]); //�p�Gi-j�o�q�b�r��̡A�����S���o�q�Ѿl�r��s���O�@�˪�
            }
        }
        dp[i] = min(dp[i], dp[i-1] + 1);  // �p�G����b�r��̡A�ܤ֭n�h�d�@�Ӧr��
        }

        return dp[n];
    }
    
};