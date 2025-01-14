/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    };
*/
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return; // 如果鏈表長度不足 3，則不需要重排
        }
        ListNode *slow = head, *fast = head;
        ListNode *dummy = new ListNode(-1);
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 反轉後段(真的很難)
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; // 將前後兩部分鏈表斷開
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        // 組合head 和prev
        ListNode *first = head, *second = prev;
        while (second)
        {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
// @lc code=end
