#include <iostream>
using namespace std;
void change_head_and_tail(int array[], int n){
    int low=0, high=n-1;
    while(low<high){
        int temp=array[low];
        array[low]=array[high];
        array[high]=temp;
        low++;
        high--;
    }
}
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    change_head_and_tail(array, n);
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
