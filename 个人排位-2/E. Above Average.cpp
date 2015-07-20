#include <cstdio>
#include <iostream>
#define MAX 1001
using namespace std;

int main()
{
    int c,n;
    int grade[MAX];
    scanf("%d",&c);
    while(c--) {
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&grade[i]);
            sum+=grade[i];
        }
        int ave=sum/n;
        int num=0;
        for(int i=0;i<n;i++) {
            if(grade[i]>ave)
                num++;
        }
        double ans=num*100.0/n;
        printf("%.3lf",ans);
        cout <<"%"<<endl;
    }
    return 0;
}
