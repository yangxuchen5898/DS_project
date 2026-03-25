#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x): data(x),next(nullptr){}
};
class LinkQueue{
private:
    ListNode* frontNode;
    ListNode* rearNode;
public:
    LinkQueue(){
        frontNode=nullptr;
        rearNode=nullptr;
    }
    ~LinkQueue(){
        while(!empty()){
            pop();
        }
    }
    bool empty(){
        return frontNode == nullptr;
    }
    void push(int x){
        ListNode* newNode=new ListNode(x);
        if(empty()){
            frontNode=rearNode=newNode;
        }
        else{
            rearNode->next=newNode;
            rearNode=newNode;
        }
    }
    void pop(){
        if(empty())return;
        ListNode* temp=frontNode;
        frontNode=frontNode->next;
        delete temp;
        if(frontNode==nullptr){
            rearNode=nullptr;
        }
    }
    int getFront(){
        if(empty())return -1;
        return frontNode->data;
    }
};
void PrintYangHui(int n){
    if(n<=0)return;
    LinkQueue q;
    q.push(1);
    for(int i=1;i<=n;i++){
        int pre=0;
        for(int j=1;j<=i;j++){
            int x=q.getFront();
            q.pop();
            cout<<x<<" ";
            q.push(pre+x);
            pre=x;
        }
        q.push(1);
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    PrintYangHui(n);
    return 0;
}