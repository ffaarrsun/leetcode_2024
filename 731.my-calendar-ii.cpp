/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
class MyCalendarTwo {
private:
    map<int, int> delta;  // 用來記錄每個時間點的事件增減情況，代表這個時段有活動
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        delta[start]++; 
        delta[end]--;
        
        int active = 0;
        for (auto& [time, count] : delta) {
            active += count;
            if (active >= 3) {  // 發生了三重重疊
                delta[start]--;
                delta[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

