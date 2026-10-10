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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = head, *end = head, *p = head;
        for (int i = 0;i < n;i++)
        {
            end = end->next;
        }
        if (end != nullptr)
        {
            p = p->next;
            end = end->next;
        }
        while(end != nullptr)
        {
            pre = pre->next;
            p = p->next;
            end = end->next;
        }
        if (p == head)
        {
            head = head->next;
        }
        else
        {
            pre->next = pre->next->next;
        }
        return head;
    }
};