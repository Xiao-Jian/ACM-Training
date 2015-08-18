#include <stdio.h>
#include <cstring>
#define Max 1000010

int a[Max], b[Max], next[Max];
int cases, m, n;

void getNext() {
	next[0] = -1, next[1] = 0;
	int i = 1, j = 0;
	while( i < n ) {
        if( j == -1 || b[j] == b[i] ) {
			++i, ++j;
			next[i] = j;
		}
		else
            j = next[j];
	}
}

int kmp() {
	int i = 0, j = 0;

	while(j != n && i < m) {
		if(j == -1 || a[i] == b[j]) ++i, ++j;
		else j = next[j];
	}
	if(j == n) return i - n + 1;
	else return -1;
}

int main()
{
	int result;
	scanf( "%d", &cases );

	while( cases -- )
	{
		scanf( "%d%d", &m, &n );
		for( int i = 0; i < m; i++ )
            scanf( "%d", &a[i] );
		for( int i = 0; i < n; i++)
            scanf( "%d", &b[i] );

		getNext();
		result = kmp();
		printf( "%d\n", result );
	}
	return 0;
}
