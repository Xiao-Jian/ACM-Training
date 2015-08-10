/*
OJ: POJ
ID: 3013216109
TASK: 2001.Shortest Prefixes
LANG: C++
NOTE: Trie
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 26
using namespace std;

typedef struct Trie {
    Trie *next[MAX];
    int v;
    Trie() {
        v = 0;
        memset( next, 0, sizeof(next) );
    }
};
Trie *root = NULL;
char str[1010][32];

void build( char * str ) {
    int len = strlen(str);
    Trie *p = root, *q;
    for( int i = 0; i < len; i ++ ) {
        int id = str[i] - 'a';
        if( p -> next[id] == NULL ) {
            q = new Trie;
            p -> next[id] = q;
        }
        p = p -> next[id];
        p -> v ++;
    }
}

void query( char *str ) {
    int len = strlen(str);
    Trie *p = root;
    for( int i = 0; i < len; i ++ ) {
        int id = str[i] - 'a';
        p = p -> next[id];
        printf( "%c", str[i] );
        if( p -> v == 1 )
            break;
    }
}

int dealTrie(Trie* T) {
    int i;
    if( T == NULL )
        return 0;
    for( i = 0; i < MAX; i ++ ) {
        if( T -> next[i] != NULL )
            dealTrie( T -> next[i] );
    }
    free(T);
    return 0;
}

int main()
{
    int n = 0;
    root = new Trie;

    while( cin >> str[n] ) {
        build( str[n++] );
    }
    for( int i = 0; i < n; i ++ ) {
        printf( "%s ", str[i] );
        query( str[i] );
        printf( "\n" );
    }
    return 0;
}