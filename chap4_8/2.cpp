#include <cstdio>
using namespace std;
void test(int &sum){
    int x;
    scanf("%d", &x);
    if(x == 0) sum = 0;
    else{
        test(sum);
        sum += x;
    }
    printf("%d\n", sum);
}
int main(){
    int sum;
    test(sum);
    return 0;
}