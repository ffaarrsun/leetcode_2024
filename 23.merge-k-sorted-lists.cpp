/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;
class Solution
{
public:
/*
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };*/
    
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }   
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        // 將每個鏈表的頭節點加入優先佇列
        for (ListNode *list : lists)
        {
            if (list)
            {
                pq.push(list);
            }
        }
        ListNode *ans = new ListNode(-1);
        ListNode *head=ans;

        while(!pq.empty())
        {
            ListNode *tmp=pq.top();
            pq.pop();
            head->next=tmp;
            head=head->next;
            if(tmp->next)
                pq.push(tmp->next);

        }
    
        ListNode *result = ans->next;
        delete ans;
        return result;
    }
};
// @lc code=end
