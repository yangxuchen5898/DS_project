// 顺序表实现（O(n)复杂度）
#include<iostream>
#include<unordered_set>
using namespace std;
int arr[100000];
int n;
void DelRepeatElements(int arr[],int& length){
    unordered_set<int> hasAppeared;
    int tail=0;
    for(int i=0;i<length;i++) {
        if(hasAppeared.find(arr[i])==hasAppeared.end()){
            hasAppeared.insert(arr[i]);
            arr[tail]=arr[i];
            tail++;
        }
    }
    length=tail;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    DelRepeatElements(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}