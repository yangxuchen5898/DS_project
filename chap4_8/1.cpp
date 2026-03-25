#include<iostream>
using namespace std;
void test(){
    int st[100010];
    int top=-1;
    int x;
    int sum=0;
    while(cin>>x){
        if(x==0){
            cout<<sum<<endl;
            break;
        }
        top++;
        st[top]=x;
    }
    while(top!=-1){
        sum+=st[top];
        top--;
        cout<<sum<<" ";
    }
}
int main(){
    test();
    return 0;
}