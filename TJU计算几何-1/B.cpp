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

inline double xmult( point o, point a, point b ) {
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

inline double getarea( point pg[], int n) {
    double area = 0;
    pg[n] = pg[0];
    for( int i = 1; i < n; i ++ )
        area += xmult( pg[0], pg[i], pg[i+1] );
    return fabs(area)/2.0;
}

int main()
{
    int n;
    point p[101];
    while( scanf( "%d", &n ), n ) {
        for( int i = 0; i < n; i ++ )
            scanf( "%lf%lf", &p[i].x, &p[i].y );
        printf( "%.1lf\n", getarea( p, n ) );
    }
}
