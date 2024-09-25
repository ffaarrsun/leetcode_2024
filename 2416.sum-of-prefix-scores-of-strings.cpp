/*
 * @lc app=leetcode id=2416 lang=cpp
 *
 * [2416] Sum of Prefix Scores of Strings
 */

// @lc code=start

//要用trie來解

struct node //建node
{
    //char是這個node的字母，umc是children，其實也可以26個就好（因?限定26小寫）
    unordered_map<char,pair<int,node*>> umc; 
    bool end=false; //記是不是end（其實可以不用）
};
class Trie{
private:
    node *root;
public:
  
    Trie(){
        root = new node();
    }//建立root

    void insert(string s)
    {
        node *cur=root;
        for(int i=0;i<s.size();i++)
        {
            if(cur->umc.find(s[i]) == cur->umc.end())//沒找到
                cur->umc[s[i]].second=new node;//還沒有，建立一個

            cur->umc[s[i]].first++;//這個字被查過++
            cur=cur->umc[s[i]].second;
        }
        cur->end=true;
        return;
    }

    int checksum(string s)
    {
        node *cur=root;
        int tmp=0;
        for(int i=0;i<s.size();i++)
        {
            tmp+=cur->umc[s[i]].first;//遍歷的全部加起來
            cur=cur->umc[s[i]].second;
         
        }
        //cout<<tmp<<" ";
        return tmp;
    }

};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie t;
        for(int i = 0; i < words.size(); i++)
        {
            t.insert(words[i]);
        }
        for(int i = 0; i < words.size(); i++)
        {
            
            ans.push_back(t.checksum(words[i]));
        }

        return ans;
    }
};
// @lc code=end

