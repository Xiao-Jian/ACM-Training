#include <cstdio>
#include <iostream>
#include <cmath>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define eps 1e-8
#define INF 1e50
#define MAXN 1001
#define Pi acos(-1.0)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)>(b))?(b):(a))
#define sign(x) (x>eps?1:(x<-eps?-1:0))
using namespace std;

struct point {
	double x, y;
	point() {}
	point( double _x, double _y ) {
		x = _x;
		y = _y;
	}
};

struct line {
	point a, b;
	line() {}
	line( point _a, point _b ) {
		a = _a;
		b = _b;
	}
};

inline double xmult( point o, point a, point b ) {
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

inline int seg_inter(line s,line p) {
	double minx1=min(s.a.x,s.b.x),maxx1=max(s.a.x,s.b.x);
	double minx2=min(p.a.x,p.b.x),maxx2=max(p.a.x,p.b.x);
	double miny1=min(s.a.y,s.b.y),maxy1=max(s.a.y,s.b.y);
	double miny2=min(p.a.y,p.b.y),maxy2=max(p.a.y,p.b.y);
	if((minx1>maxx2+eps)||(minx2>maxx1+eps)||
		(miny1>maxy2+eps)||(miny2>maxy1+eps))
		return 0;
	else
		return sign(xmult(s.a,s.b,p.a)*xmult(s.a,s.b,p.b))<=0 &&
                sign(xmult(p.a,p.b,s.a)*xmult(p.a,p.b,s.b))<=0 ;
}

int main()
{
	int n;
	double x1, y1, x2, y2;
	point a[101],b[101];
	while( scanf( "%d", &n ), n ) {
		for( int i = 0; i < n; i ++ ) {
			scanf( "%lf%lf%lf%lf", &x1,&y1,&x2,&y2 );
			a[i] = point( x1, y1 );
			b[i] = point( x2, y2 );
		}

		line s, p;
		int ans = 0;
		for( int i = 0; i < n; i ++ ) {
			for( int j = i+1; j < n; j ++ ) {
				s = line( a[i], b[i] );
				p = line( a[j], b[j] );
				if( seg_inter( s, p ) )
					ans ++;
			}
		}
		printf( "%d\n", ans );
	}
	return 0;
}
