#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ==================== 你的代码开始（原样未动） ====================
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry_out = 0;
        ListNode *p = l1,*q = l2;
        int sum;
        while(p->next != nullptr && q->next != nullptr)
        {
            sum = p->val + q->val + carry_out;
            p->val = sum%10;
            carry_out = sum/10;
            p = p->next;
            q = q->next;
        }   
        sum = p->val + q->val + carry_out;
        p->val = sum%10;
        carry_out = sum/10;   
        if (p->next == nullptr && q->next == nullptr) {
            if(carry_out != 0){
            p->next = new ListNode (carry_out,nullptr);
        }
        return l1;
        }
        if (p->next == nullptr && q->next != nullptr)
        {
            p->next = q->next;
        }
        p = p->next; 
        while(p != nullptr)
        {
            sum = p->val + carry_out;
            p->val = sum%10;
            carry_out = sum/10;
            if (p->next != nullptr)
            {
                p = p->next;               
            }
            else break;
        }
        if(carry_out != 0){
           p->next = new ListNode (carry_out,nullptr);
        }
        return l1;
    }
};
// ==================== 你的代码结束 ====================

// 辅助函数：从 vector 创建链表
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val;
        if (cur->next != nullptr) cout << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    // 构建测试用例
    vector<int> v1 = {5};
    vector<int> v2 = {5};
    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    cout << "l1: ";
    printList(l1);
    cout << "l2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "result: ";
    printList(result);
    system("pause");

    // 注意：你的代码会修改原链表，所以 l1 和 result 指向同一链表。
    // 这里不再重复打印 l1。

    return 0;
}