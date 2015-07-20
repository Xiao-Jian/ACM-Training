//±©Á¦Çó½â
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 100001
#define MAX_M 5001
using namespace std;

struct node {
    int val;
    int num;
}a[MAX_N];

bool cmp(node i,node j) {
    return i.val<j.val;
}

int main()
{
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i].val);
        a[i].num=i+1;
    }
    sort(a,a+n,cmp);
    while(m--) {
        scanf("%d%d%d",&i,&j,&k);
        int cnt=0;
        for(int p=0;p<n;p++) {
            if(a[p].num>=i&&a[p].num<=j)
                cnt++;
            if(cnt==k) {
                printf("%d\n",a[p].val);
                break;
            }
        }
    }
}
