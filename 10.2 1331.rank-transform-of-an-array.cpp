/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
class Solution {
public:

   
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> tmp(arr.begin(), arr.end());
        //vector <int> ans;
        unordered_map <int, int> count;


        sort(tmp.begin(), tmp.end());
        tmp.erase( unique( tmp.begin(), tmp.end() ), tmp.end() );//�M�����ƪ�
        //unique�|�⭫�ƪ���b�᭱�A�^�ǭ��ƪ��ӼơA�A��erase�M��

       
        for(int i = 0; i < tmp.size(); i++)
        {
            count[tmp[i]]=i+1;//�@�ӭӵ�rank�Ӥw
        }
        for(int i = 0; i < arr.size(); i++)
        {
            arr[i]=count[arr[i]];//arr�����^�h
        }


        return arr;

    }
};
// @lc code=end

