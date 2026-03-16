#include <iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};
class SortedLinkedList{
private:
    ListNode* head;
public:
    // 初始化带头节点的空链表
    SortedLinkedList() {
        head = new ListNode(0); // 头节点不存储数据
    }
    // 插入函数
    void Insert(int e){
        ListNode *s = new ListNode(e);
        ListNode *p = head;
        while(p->next != nullptr && p->next->data < e){
            p = p->next;
        }
        s->next=p->next;
        p->next=s;
    }
    // 删除函数
    void Delete(int e){
        ListNode *p = head;
        ListNode *q;
        while(p->next!=nullptr){
            if(p->next->data==e){
                q=p->next;
                p->next=q->next;
                delete q;
            }
            else if(p->next->data>e){
                break;
            }
            else{
                p=p->next;
            }
        }
    }
};
void AppendNode(ListNode*& head, ListNode*& tail, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
int main() {
    int n, val;
    cin >> n;
    ListNode* L = nullptr;
    ListNode* tail = nullptr;
    //读入：尾插法
    for (int i = 0; i < n; ++i) {
        cin >> val;
        AppendNode(L, tail, val);
    }
    SortedLinkedList sortedList;
    int ins;
    cin>>ins;
    sortedList.Insert(ins);
    int del;
    cin>>del;
    sortedList.Delete(del);
    ListNode* current = L;
    
    while (current) {
        cout << current->data;
        if (current->next) cout << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}