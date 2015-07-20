/*
OJ: POJ
ID: 3013216109
TASK: 1840.Eqs
LANG: C++
NOTE: Hash
*/
#include <cstdio>
#include <cstring>

short s[25000001];

int main()
{
    int a1,a2,a3,a4,a5;
    scanf("%d %d %d %d %d",&a1,&a2,&a3,&a4,&a5);
    memset(s,0,sizeof(s));

    for(int x1=-50;x1<=50;x1++) {
        if(x1==0) continue;
        for(int x2=-50;x2<=50;x2++) {
            if(x2==0) continue;
            int sum=-(a1*x1*x1*x1+a2*x2*x2*x2);
            if(sum<0)
                sum+=25000000;
            s[sum]++;
        }
    }

    int ans=0;
    for(int x3=-50;x3<=50;x3++) {
        if(x3==0) continue;
        for(int x4=-50;x4<=50;x4++) {
            if(x4==0) continue;
            for(int x5=-50;x5<=50;x5++) {
                if(x5==0) continue;
                int sum=a3*x3*x3*x3+a4*x4*x4*x4+a5*x5*x5*x5;
                if(sum<0)
                    sum+=25000000;
                if(s[sum])
                    ans+=s[sum];
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
