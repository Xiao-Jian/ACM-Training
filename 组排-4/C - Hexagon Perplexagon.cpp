#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int in[10][10];

void change(int *h,int tgt,int pos){
    for(int i=0;i<6;i++){
        if(h[i]==tgt){
            int tmp[10];
            for(int j=0;j<6;j++){
                tmp[(pos+j)%6]=h[(i+j)%6];
            }
            for(int j=0;j<6;j++){
                h[j]=tmp[j];
            }
            return;
        }
    }
}

bool dfs(int *perm,int pos){
    if( pos == 1 ) {
        change( in[perm[0]], 1, 0 );
    }
    else if(pos>1) {
        change( in[perm[pos-1]], in[perm[0]][pos-2], ( pos + 1 ) % 6 );
        if(pos>2&&in[perm[pos-1]][(pos+2)%6]!=in[perm[pos-2]][(pos+5)%6]){
            return false;
        }
    }
    if(pos==7){
        return in[perm[1]][4]==in[perm[6]][1];
    }
    for(int i=pos;i<7;i++){
        swap(perm[pos],perm[i]);
        if(dfs(perm,pos+1)){
            return true;
        }
    }
    for(int i=pos;i+1<7;i++){
        swap(perm[i],perm[i+1]);
    }
    return false;
}

int main(){
    int n;
    scanf( "%d", &n );
    for( int i = 1; i <= n; i ++ ) {
        for( int j = 0; j < 7; j ++ ) {
            for(int k = 0; k < 6; k ++ ) {
                scanf( "%d", in[j] + k );
            }
        }
        int perm[10];
        for( int j = 0; j < 7; j ++ ) {
            perm[j] = j;
        }
        printf( "Case %d:" ,i );

        if( dfs( perm, 0 ) ) {
            for( int j = 0; j < 7; j ++ ) {
                printf( " %d", perm[j] );
            }
            putchar('\n');
        }
        else {
            puts(" No solution");
        }
    }
    return 0;
}
