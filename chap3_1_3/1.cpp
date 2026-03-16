// 单链表实现（因为一开始没看清楚题目）
#include<iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x):data(x),next(nullptr){}
};
void AppendNode(ListNode*& head,ListNode*& tail,int val){
    ListNode* newNode = new ListNode(val);
    if (head==nullptr) {
        head=newNode;
        tail=newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
void DelRepeatElements(ListNode*& L){
    ListNode *p=L;
    while(p!=nullptr){
        int val=p->data;
        ListNode *temp=p;
        while(temp->next!=nullptr){
            if(temp->next->data==val){
                ListNode *WillDelete=temp->next;
                temp->next=temp->next->next;
                delete WillDelete;
            }
            else temp=temp->next;
        }
        p=p->next;
    }
}
int main(){
    int n,val;
    cin>>n;
    ListNode* L = nullptr;
    ListNode* tail = nullptr;
    //读入L：尾插法
    for (int i = 0; i < n; ++i) {
        cin >> val;
        AppendNode(L, tail, val);
    }
    DelRepeatElements(L);
    ListNode* current = L;
    while (current) {
        cout << current->data;
        if (current->next) cout << " ";
        current = current->next;
    }
    return 0;
}