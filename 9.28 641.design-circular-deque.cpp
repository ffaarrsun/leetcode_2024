/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
class MyCircularDeque {
    vector<int> cir=vector <int>(1001,0);
    int front=0,rear=0,n=1001;
public:
    MyCircularDeque(int k) {
        n=k+1;
    }
    
    bool insertFront(int value) {
        if (!isFull())
        {
            front=(front-1+n)%n;
            cir[front]=value;
            return true;
        }
        else
            return false;
    }
    
    bool insertLast(int value) {
        if (!isFull())
        {
            cir[rear]=value;
            rear=(rear+1)%n;
            //cout<<"a ";
            return true;
        }
        else
            return false;
    }
    
    
    bool deleteFront() {
        if (!isEmpty())
        {
            front=(front+1)%n;
            return true;
        }
        else
            return false;
    }
    
    bool deleteLast() {
        if (!isEmpty())
        {
            rear=(rear-1+n)%n;
            return true;
        }
        else
            return false;
    }
    
    int getFront() {
        if (isEmpty())
        {
            return -1;
        }
        
        return cir[front];
    }
    
    int getRear() {
        if (isEmpty())
        {
            return -1;
        }
        return cir[(rear-1+n)%n];
    }
    
    bool isEmpty() {
        
        if(front==rear)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if((rear + 1) % n == front)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

