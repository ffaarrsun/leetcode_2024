/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
class AllOne {
private:
    unordered_map<string,int> count;
    set<pair<int,string>> rank; //用set排序
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        int tmp=count[key];
        count[key]++;
        rank.erase(pair(tmp,key));
        rank.insert(pair(tmp+1,key));
    }
    
    void dec(string key) {
        int tmp= count[key];
        count[key]--;
        if (count[key]==0)
        {
            count.erase(key);
            rank.erase(pair(1,key));
            return;
        }
        rank.erase(pair(tmp,key));
        rank.insert(pair(tmp-1,key));

        
    }
    
    string getMaxKey() {
        
        if(count.empty())
            return "";
        /*原方法一個個迭代會tle
        auto x = std::max_element(count.begin(), count.end(),
        [](const pair<string, int>& p1, const pair<string, int>& p2) {
            return p1.second < p2.second; });
        return x->first;
        */
       return rank.rbegin()->second;
    }
    
    string getMinKey() {
        if(count.empty())
            return "";
        /*
        auto x = std::min_element(count.begin(), count.end(),
        [](const pair<string, int>& p1, const pair<string, int>& p2) {
            return p1.second < p2.second; });
        return x->first;
        */
       return rank.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

