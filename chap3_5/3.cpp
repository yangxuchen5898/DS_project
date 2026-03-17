//linklist类
#include <iostream>
using namespace std;
struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x): data(x), next(nullptr){}
};
class LinkList{
private:
    ListNode* head;
    ListNode* tail;
public:
    LinkList(){
        head=nullptr;
        tail=nullptr;
    }
    ~LinkList(){
        ListNode* current=head;
        while(current!=nullptr){
            ListNode* nextNode=current->next;
            delete current;
            current=nextNode;
        }
    }
    void CreateNode(int val){
        ListNode* newNode=new ListNode(val);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        } else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void AppendNode(int val, int position){
        if(position<0)return;
        ListNode* newNode=new ListNode(val);
        if(position==0||head==nullptr){
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
        newNode->next=p->next;
        p->next=newNode;
        if(newNode->next==nullptr)tail=newNode;
    }
    void DeleteNode(int val){
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
    void Print()const{
        ListNode* p=head;
        while(p!=nullptr){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};
int main(){
    int n, val;
    cin>>n;
    LinkList L;
    for(int i=0;i<n;++i){
        cin>>val;
        L.CreateNode(val);
    }
    int appendval, appendposition;
    cin>>appendval>>appendposition;
    L.AppendNode(appendval, appendposition);
    int delval;
    cin>>delval;
    L.DeleteNode(delval);
    L.Print();
    return 0;
}