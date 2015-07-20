#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char str[256];
    while(gets(str)) {
        if(str[0]=='#'&&strlen(str)==1)
            break;
        int sum=0;
        for(int i=0;i<strlen(str);i++) {
            int x=str[i]-'A'+1;
            if(str[i]==' ')
                x=0;
            sum+=x*(i+1);
        }
        printf("%d\n",sum);
    }
    return 0;
}
