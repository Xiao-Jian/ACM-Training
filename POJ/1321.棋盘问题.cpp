/*
OJ: POJ
ID: 3013216109
TASK: 1321.∆Â≈ÃŒ Ã‚
LANG: C++
NOTE: DFS
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct prog {
    char map [10][10];
    int x;
};
int m;
int ans;
void DFS(prog tmp,int n)
{
    if(n==0)
    {
        ans++;
        return ;
    }
    int i , j ;
    for ( i = tmp.x + 1 ; i <= m -n; i ++ )
    {
        for ( j = 0 ; j < m ; j ++ )
        {
            if ( tmp.map[i][j]=='#')
            {
                prog tmp2;
                tmp2=tmp;
                tmp2.x=i;
                int k;
                for (k = i+1 ; k < m ; k ++)
                {
                    tmp2.map[k][j]='.';
                }
                DFS(tmp2,n-1);

            }
        }
    }
}
int main()
{

    int  n ;
    while ( cin >> m >> n , m != -1 || n != -1 )
    {
        ans=0;
        prog map;
        map.x=-1;
        int i;
        for ( i = 0 ; i < m ; i ++ )
        {
            cin >> map . map [ i ];
        }
        DFS(map,n);
        cout<<ans<<endl;
    }
    return 0;
}
