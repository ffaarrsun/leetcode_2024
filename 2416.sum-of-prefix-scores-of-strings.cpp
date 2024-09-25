/*
 * @lc app=leetcode id=2416 lang=cpp
 *
 * [2416] Sum of Prefix Scores of Strings
 */

// @lc code=start

//�n��trie�Ӹ�

struct node //��node
{
    //char�O�o��node���r���Aumc�Ochildren�A���]�i�H26�ӴN�n�]�]?���w26�p�g�^
    unordered_map<char,pair<int,node*>> umc; 
    bool end=false; //�O�O���Oend�]���i�H���Ρ^
};
class Trie{
private:
    node *root;
public:
  
    Trie(){
        root = new node();
    }//�إ�root

    void insert(string s)
    {
        node *cur=root;
        for(int i=0;i<s.size();i++)
        {
            if(cur->umc.find(s[i]) == cur->umc.end())//�S���
                cur->umc[s[i]].second=new node;//�٨S���A�إߤ@��

            cur->umc[s[i]].first++;//�o�Ӧr�Q�d�L++
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
            tmp+=cur->umc[s[i]].first;//�M���������[�_��
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

