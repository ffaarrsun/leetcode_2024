#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution
{
public:
    string encode(vector<string> &strs) //把vector<string>變string再還原，在最前面記下每個詞多長，用#分隔，用A做結尾，不能用$符號
    {
        string ans = "";
        vector<int> str_size;
        for (string s : strs)
            str_size.push_back(s.size());

        for (auto si : str_size)
            ans = ans + to_string(si) + "#";//to_string
        
        ans += "A";
        for (string s : strs)
            ans += s;
        
        // cout<<ans;
        return ans;
    }

    vector<string> decode(string s)
    {
        string tmp = "";
        vector<int> str_size;
        vector<string> ans;
        int now = 0;

        while (s[now] != 'A')
        {
            if (s[now] != '#')
                tmp += s[now];
            else
            {
                str_size.push_back(stoi(tmp));//stoi
                tmp = "";
            }
            now++;
        }
        now++;
        for (int i : str_size)
        {
            string tmp_ans = "";
            for (int j = 0; j < i; j++)
            {
                tmp_ans += s[now];
                now++;
            }
            ans.push_back(tmp_ans);
        }

        return ans;
    }
};
