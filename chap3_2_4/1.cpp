// 顺序表实现
#include<iostream>
#include<algorithm>
using namespace std;
int arr[100000];
int n,S,T;
void DelStoTElements(int arr[],int& length,int s,int t){
    int tail=0;
    for(int i=0;i<length;i++) {
        if(arr[i]>=t||arr[i]<=s){
            arr[tail]=arr[i];
            tail++;
        }
    }
    length=tail;
}
int main(){
    cin>>n>>S>>T;
    if(S>=T||n<=0){
        cout<<"invalid input";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    DelStoTElements(arr,n,S,T);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}