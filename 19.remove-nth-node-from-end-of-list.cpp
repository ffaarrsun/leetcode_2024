/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next)
            return nullptr;
        ListNode *curr = head, *prev = nullptr,*tmpNode=head;

        int tmp,count=0;
        while(tmpNode)
        {
            tmpNode=tmpNode->next;
            count++;
        }

        tmp =count-n;
        while (tmp > 0)
        {
            tmp--;
            prev = curr;
            curr = curr->next;
        }
        
        if(prev)
            prev->next=curr->next;
        else
            head =curr->next;
        return head;
    }
};
// @lc code=end
