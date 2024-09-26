/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start


class MyCalendar {
private:
    map <int,int> cal;//map�|�ۤv�Hkey(start)�Ƨ�
public:
    
    MyCalendar() {
        
        
    }
    
    bool book(int start, int end) {
        
        auto next=cal.lower_bound(start);
        // lower_bound: ���Ĥ@�� key �j�󵥩� start ���ƥ�
        if (next!=cal.begin()&&prev(next)->second>start)
        {//�e�@�Ӫ�end��start�j�A�N���|
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

