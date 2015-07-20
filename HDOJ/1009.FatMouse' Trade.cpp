#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX=1005;
int f[MAX],j[MAX],q[MAX];

typedef struct node {
    double rate;
    int num;
}st;

bool cmp(const st& a,const st& b) {
    return a.rate>b.rate;
}

int main()
{
    int m,n;
    st r[MAX];
    while(scanf("%d %d",&m,&n)) {
        if(m==-1&&n==-1) break;
        for(int i=0;i<n;i++) {
            scanf("%d %d",&f[i],&j[i]);
            r[i].rate=f[i]*1.0/j[i];
            r[i].num=i;
        }
        sort(r,r+n,cmp);
        /*for(int i=0;i<n;i++) {
            printf("%lf %d\n",r[i].rate,r[i].num);
        }*/
        double sum=0;
        for(int i=0;i<n;i++) {
            int m1=m-j[r[i].num];
            if(m1<0) {
                sum=r[i].rate*m+sum;
                break;
            }
            else {
                m=m-j[r[i].num];
                sum=sum+f[r[i].num];
            }
        }
        printf("%.3lf\n",sum);
    }
    return 0;
}
