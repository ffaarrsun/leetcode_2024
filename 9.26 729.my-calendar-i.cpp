/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start


class MyCalendar {
private:
    map <int,int> cal;//map會自己以key(start)排序
public:
    
    MyCalendar() {
        
        
    }
    
    bool book(int start, int end) {
        
        auto next=cal.lower_bound(start);
        // lower_bound: 找到第一個 key 大於等於 start 的事件
        if (next!=cal.begin()&&prev(next)->second>start)
        {//前一個的end比start大，代表重疊
            return false;
        }
        if (next != cal.end()&&next->first<end)
        {
            return false;
        }
        cal.insert(pair<int,int>(start,end));
        return true;
        
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

