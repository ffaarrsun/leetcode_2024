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
        tmp.erase( unique( tmp.begin(), tmp.end() ), tmp.end() );//清掉重複的
        //unique會把重複的丟在後面，回傳重複的個數，再用erase清除

       
        for(int i = 0; i < tmp.size(); i++)
        {
            count[tmp[i]]=i+1;//一個個給rank而已
        }
        for(int i = 0; i < arr.size(); i++)
        {
            arr[i]=count[arr[i]];//arr對應回去
        }


        return arr;

    }
};
// @lc code=end

