//第一版，还具有许多问题
//插入时没处理表头插入、空表、越界、tail更新
//删除时没处理删首结点、删当前结点方式错误、释放后继续访问、tail更新
#include <iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};
void CreateNode(ListNode*& head, ListNode*& tail, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head=newNode;
        tail=newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
void AppendNode(ListNode*& head, ListNode*& tail, int val, int position){
    ListNode* p=head;
    position--;
    while(position--)p=p->next;
    ListNode* newNode = new ListNode(val);
    ListNode* temp=p->next;
    p->next=newNode;
    newNode->next=temp;
}
void DeleteNode(ListNode*& head, ListNode*& tail, int val){
    ListNode* p=head;
    while(p->next!=nullptr){
        if(p->data==val){
            ListNode* temp=p;
            p->next=p->next->next;
            delete temp;
        }
        p=p->next;
    }
}
int main() {
    int n,val;
    cin>>n;
    ListNode* L = nullptr;
    ListNode* tail = nullptr;
    //尾插法插入结点
    for (int i = 0; i < n; ++i) {
        cin >> val;
        CreateNode(L, tail, val);
    }
    //在指定位置插入指定元素
    int appendval,appendposition;
    cin>>appendval>>appendposition;
    AppendNode(L,tail,appendval,appendposition);
    //删除链表中的所有指定元素
    int delval;
    cin>>delval;
    DeleteNode(L,tail,delval);
    //打印
    ListNode* p = L;
    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}