#include <cstdio>

int main()
{
    int n,r,e,c;
    scanf("%d",&n);
    while(n--) {
        scanf("%d%d%d",&r,&e,&c);
        if(e>r+c)
            printf("advertise\n");
        else if(e==r+c)
            puts("does not matter");
        else
            puts("do not advertise");
    }
    return 0;
}
