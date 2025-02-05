/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;
class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxheap.push(num);

        minheap.push(maxheap.top());
        maxheap.pop();

        if (maxheap.size() < minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        if (maxheap.size() > minheap.size())
            return maxheap.top();
        else
            return (maxheap.top() + minheap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
