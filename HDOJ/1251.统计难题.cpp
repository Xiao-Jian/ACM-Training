/*
OJ: HDOJ
ID: forever
TASK: 1251.统计难题
LANG: C++
NOTE: Trie树模板，C++AC，G++MLE
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 26
using namespace std;

typedef struct node {
    node *next[MAX];
    int v;
    node() {
        v = 1;
        for( int j = 0; j < 26; j ++ )
            next[j] = NULL;
    }
} Trie;
Trie *root = new node;

void build( char * str ) {
    int len = strlen(str);
    Trie *p = root, *q;
    for( int i = 0; i < len; i ++ ) {
        int id = str[i] - 'a';
        if( p -> next[id] == NULL ) {
            q = new node;
            p -> next[id] = q;
            p = p -> next[id];
        }
        else {
            p = p -> next[id];
            p -> v ++;
        }
    }
}

int query( char *str ) {
    int len = strlen(str);
    Trie *p = root;
    for( int i = 0; i < len; i ++ ) {
        int id = str[i] - 'a';
        p = p -> next[id];
        if( p == NULL )
            return 0;
    }
    return p -> v;
}

int main()
{
    char str[15];
    int ans;

    while( gets( str ) && str[0]!='\0' )
        build(str);

    memset( str, 0, sizeof(str) );
    while( scanf("%s", &str) != EOF ){
        ans = query( str );
        printf( "%d\n", ans );
    }
    return 0;
}
