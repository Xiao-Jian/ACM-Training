#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a[100005];

int main()
{
    int n,m,i,j,sum,x;
    while(~scanf("%d%d",&n,&m))
    {
        int flag = 0;
        for(i = 1; i<=n; i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        n = unique(a+1,a+n+1)-a-1;

        for(i = 1; i<n; i++)
        {
            for(j = i+1; j<=n; j++)
            {
                sum = a[i]^a[j];
                if( sum >m)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
