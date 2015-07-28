#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 500001
using namespace std;

char s[MAX][50];

int main()
{
    int r=0;
    char str[50];
    while(scanf("%s",str)!=EOF)
        strcpy(s[r++],str);
    printf("%d\n",r);
    for(int i=0;i<r;i++) {
        int mid,l=0;
        while(l<r) {
            mid=(l+r)/2;
            char tmp[50];
            for(int i=0;i<strlen(s[l])+strlen(s[r]);i++) {
                if(i<strlen(s[l]))
                    tmp[i]=s[l][i];
                else
                    tmp[i]=s[r][i-strlen(s[l])];
            }
            if(tmp==s[mid]) break;
            else if(tmp<s[mid]) l=mid-1;
            else r=mid+1;
        }
        if(l<r)
            puts(s[mid]);
        else puts("1!");
    }
    return 0;
}
