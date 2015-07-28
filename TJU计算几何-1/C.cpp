#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define eps 1e-8
#define INF 1e50
#define MAXN 1001
#define Pi acos(-1.0)
#define sign(x) (x>eps?1:(x<-eps?-1:0))
using namespace std;

struct point {
	double x, y;
	point() {};
	point( double _x, double _y ) {
		x = _x;
		y = _y;
	}
	point operator - ( const point& ne ) {
		return point( x - ne.x, y - ne.y );
	}
	point operator + ( const point& ne ) {
		return point( x + ne.x, y + ne.y );
	}
	point operator * ( const double t ) {
		return point( x * t, y * t );
	}
	point operator / ( const double t ) {
		if( sign(t) == 0) exit(1);
		return point( x / t, y / t );
	}
};

struct circle {
	point o;
	double r;
	circle() {}
	circle( point _o, double _r ) {
		o = _o;
		r = _r;
	}
};
circle cir[21];
int n;

inline double dmult( point a, point b ) {
	return a.x * b.x + a.y * b.y;
}
inline double length( point a ) {
	return sqrt( dmult( a , a ) );
}
inline double dist( point a, point b ) {
	return length( b - a );
}
double insection_of_circles(circle a, circle b) {
    double d = dist( a.o, b.o );
    if( d >= a.r + b.r )
        return 0;
    if( d <= fabs( a.r - b.r ) ) {
        double r = a.r < b.r ? a.r : b.r;
        return Pi * r * r;
    }
    double ang1 = acos((a.r * a.r + d * d - b.r * b.r) / 2. / a.r / d);
    double ang2 = acos((b.r * b.r + d * d - a.r * a.r) / 2. / b.r / d);
    double ret = ang1 * a.r * a.r + ang2 * b.r * b.r - d * a.r * sin(ang1);
    return ret;
}

bool check(circle c) {
    for( int i = 0; i < n; i ++ ) {
        if (insection_of_circles(c, cir[i]) * 2 < Pi * cir[i].r * cir[i].r)
            return false;
    }
    return true;
};

int main()
{
    int t;
    scanf( "%d", &t );
    while( t -- ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; i ++ )
            scanf( "%lf%lf%lf", &cir[i].o.x, &cir[i].o.y, &cir[i].r );

        double ans[21], mi = 0x7fffffff;
        for( int i = 0; i < n; i ++ ) {
            double ma = 0;
            circle c;
            c.o.x = cir[i].o.x;
            c.o.y = cir[i].o.y;
            int v;
            for( int j = 0; j < n; j ++ ) {
                point a = cir[i].o;
                point b = cir[j].o;
                if( ma < dist( a, b ) + cir[j].r ) {
                    v = j;
                    ma = dist( a, b ) + cir[j].r;
                }
            }
            double l = 0, r = ma;
            double mid;
            while( fabs( l - r ) >= eps ) {
                mid = ( l + r ) / 2;
                c.r = mid;
                if( check(c) )
                    r = mid;
                else
                    l = mid + eps;
            }
            mi = min( r, mi );
        }

        printf( "%.4f\n", mi );
    }

    return 0;
}
