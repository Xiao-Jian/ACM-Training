//next_permutation
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

set<int> ans;

bool is_prime(int x) {
    if(x==0||x==1) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i<=sqrt(x);i+=2)
        if(x%i==0) return false;
    return true;
}

int main()
{
    int n;
    char str[10],s[10];
    scanf("%d",&n);
    getchar();
    while(n--) {
        gets(str);
        int len=strlen(str);
        sort(str,str+len);

        ans.clear();
        for(int i=1;i<(1<<len);i++) {
            int cnt=0;
            for(int j=0;j<len;j++) {
                if((1<<j)&i)
                    s[cnt++]=str[j];
            }
            do {
                int num=0;
                for(int i=0;i<cnt;i++) {
                    num*=10;
                    num+=(s[i]-48);
                }
                if(is_prime(num))
                    ans.insert(num);
            } while(next_permutation(s,s+cnt));
        }
        printf("%d\n",ans.size());
    }
    return 0;
}
