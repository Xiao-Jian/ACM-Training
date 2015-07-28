//¶þ·Ö²éÕÒ
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 4000*4000+1
using namespace std;

int a[MAX],b[MAX],c[MAX],d[MAX];
int sum[MAX];

int Find(int l,int r,int x) {
    while(l<=r) {
        int mid=(l+r)/2;
        if(sum[mid]==x) return mid;
        if(sum[mid]<x) return Find(mid+1,r,x);
        if(sum[mid]>x) return Find(l,mid-1,x);
    }
    return -1;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    int k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            sum[k++]=-(a[i]+b[j]);
    sort(sum,sum+k);

    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(Find(0,k-1,c[i]+d[j])>=0) {
                ans++;
                int x=Find(0,k-1,c[i]+d[j]),dx=1;
                while(x+dx<k&&sum[x+dx]==c[i]+d[j]) {
                    ans++;
                    dx++;
                }
                x=Find(0,k-1,c[i]+d[j]),dx=1;
                while(x-dx>=0&&sum[x-dx]==c[i]+d[j]) {
                    ans++;
                    dx++;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
