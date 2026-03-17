//第二版
#include <iostream>
using namespace std;
struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};
void CreateNode(ListNode*& head,ListNode*& tail,int val){
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head=newNode;
        tail=newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
void AppendNode(ListNode*& head,ListNode*& tail,int val,int position){
    if(position<0)return;
    ListNode* newNode=new ListNode(val);
    if(position==0){
        newNode->next=head;
        head=newNode;
        if(tail==nullptr)tail=newNode;
        return;
    }
    ListNode* p=head;
    for(int i=0;i<position-1&&p!=nullptr;i++)p=p->next;
    if(p==nullptr){
        delete newNode;
        return;
    }
    newNode->next = p->next;
    p->next=newNode;
    if(newNode->next==nullptr)tail=newNode;
}
void DeleteNode(ListNode*& head,ListNode*& tail,int val){
    while(head!=nullptr&&head->data==val){
        ListNode* temp=head;
        head=head->next;
        delete temp;
    }
    if(head==nullptr){
        tail=nullptr;
        return;
    }
    ListNode* p=head;
    while(p->next!=nullptr){
        if(p->next->data==val){
            ListNode* temp=p->next;
            p->next=temp->next;
            if(temp==tail)tail=p;
            delete temp;
        }
        else{
            p=p->next;
        }
    }
}
int main(){
    int n,val;
    cin>>n;
    ListNode* L = nullptr;
    ListNode* tail = nullptr;
    //尾插法插入结点
    for (int i = 0; i < n; ++i){
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
