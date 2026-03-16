#include <iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};
ListNode* MergeToDescending(ListNode* L1, ListNode* L2) {
    ListNode* resHead = nullptr; // 结果链表不带头结点
    ListNode *p1 = L1, *p2 = L2, *temp;
    while (p1 && p2) {
        if (p1->data <= p2->data) {
            temp = p1->next;
            p1->next = resHead; // 头插到新链表
            resHead = p1;
            p1 = temp;
        } else {
            temp = p2->next;
            p2->next = resHead;
            resHead = p2;
            p2 = temp;
        }
    }
    // 处理剩余结点
    ListNode* remaining = (p1) ? p1 : p2;
    while (remaining) {
        temp = remaining->next;
        remaining->next = resHead;
        resHead = remaining;
        remaining = temp;
    }
    return resHead;
}
void AppendNode(ListNode*& head, ListNode*& tail, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head=newNode;
        tail=newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
int main() {
    int n1, n2, val;
    cin >> n1 >> n2;
    ListNode* L1 = nullptr;
    ListNode* L2 = nullptr;
    ListNode* tail1 = nullptr;
    ListNode* tail2 = nullptr;
    //读入L1：尾插法
    for (int i = 0; i < n1; ++i) {
        cin >> val;
        AppendNode(L1, tail1, val);
    }
    //读入L2：尾插法
    for (int i = 0; i < n2; ++i) {
        cin >> val;
        AppendNode(L2, tail2, val);
    }
    ListNode* mergedHead = MergeToDescending(L1, L2);
    ListNode* current = mergedHead;
    while (current) {
        cout << current->data;
        if (current->next) cout << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}