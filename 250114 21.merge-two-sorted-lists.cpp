/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    */
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* merge_list = dummy;
        //dummy和merge都指向-1節點
        bool fl = true;

        while(list1 && list2)
        {
            if((list1->val < list2->val)||list2==NULL)
            {
                //-1節點會指向開頭，所以最後結果只要-1節點下一個就是開頭
                merge_list->next = list1;
                list1 = list1->next;  
            }
            else if((list1->val >= list2->val)||list1==NULL)
            {
                merge_list->next = list2;
                list2 = list2->next;
            }     
            merge_list=merge_list->next;
            fl=false;
        }

        if(list1)
            merge_list->next = list1;
        else
            merge_list->next = list2;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
// @lc code=end
