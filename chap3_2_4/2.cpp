// 有序顺序表类
#include<iostream>
#include<algorithm>
using namespace std;
class List{
private:
    int arr[100000];
    int length;
public:
    List(){
        length=0;
    }
    void input(int n) {
        length=n;
        for(int i=0;i<length;i++) {
            cin>>arr[i];
        }
        sort(arr,arr+n);
    }
    void DelStoTElements(int s, int t) {
        if(s>=t||length<=0) {
            cout<<"invalid input";
            exit(0);
        }
        int tail=0;
        for(int i=0;i<length;i++) {
            if(arr[i]<=s||arr[i]>=t){
                arr[tail]=arr[i];
                tail++;
            }
        }
        length=tail;
    }
    void output(){
        for(int i=0;i<length;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    int n,S,T;
    cin>>n>>S>>T;
    List L;
    L.input(n);
    L.DelStoTElements(S,T);
    L.output();
    return 0;
}