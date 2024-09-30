/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack {
private:
    vector<int> stack=vector <int>(1005,0);
    int n,top=0;
    
public:
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(top < n)
        {
            stack[top]=x;
            top+=1;
        }
    }
    
    int pop() {
        if(top == 0)
            return -1;
        top-=1;
        return stack[top];
        
    }
    
    void increment(int k, int val) {
        if(k>=top)
        {
            for(int i = 0; i < top;i++)
                stack[i] += val;       
        }
        else
        {
            for(int i = 0; i < k;i++)
                stack[i] += val;   
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

