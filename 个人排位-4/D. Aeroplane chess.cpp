//¸ÅÂÊDP+ÆÚÍû
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=100010;

double res[N];
int father[N];

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0)
            break;
        memset(res,0,sizeof(res));
        memset(father,-1,sizeof(father));
        int a,b;
        while(m--){
            scanf("%d%d",&a,&b);
            father[a]=b;
        }
        for(int i=n-1;i>=0;i--){
            if(father[i]!=-1)
                res[i]=res[father[i]];
            else{
                for(int j=1;j<=6;j++){
                    if(i+j<=n)
                        res[i]+=1.0/6*res[i+j];
                    else
                        break;
                }
                res[i]+=1;
            }
        }
        printf("%.4lf\n",res[0]);
    }
    return 0;
}
