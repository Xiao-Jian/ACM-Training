#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    stack<char> q;
    int n;
    char a[1000],b[1000];
    while(scanf("%d %s %s",&n,a,b)!=EOF) {
        int flag[1000];
        flag[0]=1;
        q.push(a[0]);

        int i=1,j=0,k=1;
        while(i<=n&&j<n) {
            if(!q.empty()&&q.top()==b[j]) {
                j++;
                q.pop();
                flag[k++]=0;
            }
            else {
                q.push(a[i++]);
                flag[k++]=1;
            }
        }
        if(i==n+1) {
            printf("No.\n");
        }
        else {
            printf("Yes.\n");
            for(j=0;j<k;j++) {
                if(flag[j])
                    printf("in\n");
                else
                    printf("out\n");
            }
        }
        printf("FINISH\n");
    }
    return 0;
}
