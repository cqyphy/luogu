#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head1 = new ListNode(-200,list1);
        ListNode *head2 = new ListNode(-200,list2);
        ListNode *p = head1->next, *q = head2->next, *pre = head1;
        while (p != nullptr && q != nullptr)
        {
            if (p->val < q->val)
            {
                p = p->next;
                pre = pre->next;
            }
            else
            {
                ListNode *s = q;
                q = q->next;
                s->next = p;
                pre->next = s;
                pre = pre->next;
            }
        }
        if (p == nullptr)
        {
            pre->next = q;
        }
        return head1->next;
    }
};

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
    vector<int> v1 = {1};
    vector<int> v2 = {2};
    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    cout << "l1: ";
    printList(l1);
    cout << "l2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.mergeTwoLists(l1, l2);

    cout << "result: ";
    printList(result);
    system("pause");

    // 注意：你的代码会修改原链表，所以 l1 和 result 指向同一链表。
    // 这里不再重复打印 l1。

    return 0;
}