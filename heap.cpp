#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int a,int b) {
    return a>b;
}

int main()
{
    int a[10]={5,2,4,9,7,1,6,8};
    make_heap(a,a+8);
    for(int i=0;i<8;i++)
        printf("%d",a[i]);
    printf("\n");

    //make_heap(a,a+8,cmp);
    for(int i=0;i<8;i++)
        printf("%d",a[i]);
    printf("\n");

    a[8]=3;
    push_heap(a,a+9);
    for(int i=0;i<9;i++)
        printf("%d",a[i]);
    printf("\n");

    //pop_heap(a,a+9);
    for(int i=0;i<9;i++)
        printf("%d",a[i]);
    printf("\n");

    sort_heap(a,a+9);
    for(int i=0;i<9;i++)
        printf("%d",a[i]);
    printf("\n");

    return 0;
}
