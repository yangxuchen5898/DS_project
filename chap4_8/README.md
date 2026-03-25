# chap4_8

试将下列递归过程改写为非递归过程。

```c++
void test(int &sum){
    int x;
    scanf("%d",&x);
    if(x==0)sum=0;
    else{
        test(sum);
        sum+=x;
    }
    printf("%d",sum);
}
```