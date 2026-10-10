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

// ==================== 你的修正代码 ====================
class Solution {
public:
    static ListNode* mini(vector<ListNode*>& lists,ListNode *&test){
        ListNode *tmp = lists[1];
        test = tmp;
        int index = 1;
        for (int i = 1; i < lists.size(); i++)
        {
            if (lists[i] == nullptr) continue;
            if(tmp == nullptr || tmp->val > lists[i]->val)
            {
                tmp = lists[i];
                test = lists[i];
                index = i;
            }
        }
        if (test != nullptr)
            lists[index] = lists[index]->next;
        return tmp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size()<2) return lists[0];
        ListNode *tmp = new ListNode(-200,lists[0]), *test = nullptr, *p = tmp->next, *pre = tmp;
        while (true)
        {
            ListNode *s = mini(lists,test);
            if (test == nullptr) break;
            while (s != nullptr)
            {
                if (p == nullptr || s->val < p->val)
                {
                    s->next = p;
                    pre->next = s;
                    p = s;
                    s = nullptr;
                }
                else
                {
                    p = p->next;
                    pre = pre->next;
                }
            }                        
        }
        return tmp->next;
    }
};
// ====================================================

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
        if (cur->next) cout << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    // 创建测试用例：三个有序链表
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    cout << "原始链表：" << endl;
    for (int i = 0; i < lists.size(); i++) {
        cout << "list " << i << ": ";
        printList(lists[i]);
    }

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    cout << "合并后： ";
    printList(result);
    system("pause");
    return 0;
}