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
	point operator - ( const point& ne ) const {
		return point( x - ne.x, y - ne.y );
	}
	point operator + ( const point& ne ) const {
		return point( x + ne.x, y + ne.y );
	}
	point operator * ( const double t ) const {
		return point( x * t, y * t );
	}
	point operator / ( const double t ) const {
		if( sign(t) == 0) exit(1);
		return point( x / t, y / t );
	}
	//叉积
    double operator ^ ( const point& b ) const {
        return x*b.y - y*b.x;
    }
};
struct line {
	point a, b;
	line() {};
	line( point _a, point _b ) {
		a = _a;
		b = _b;
	}
    pair<int,point> operator & (const line& p)const
    {
        point res = a;
        double x = (a-b) ^ (p.a-p.b);
        if(sign(x) == 0)
        {
            x = (a-p.b)^(p.a-p.b);
            if(sign(x) == 0)
                return make_pair(0,res);//重合
            else return make_pair(1,res);//平行
        }
        double t = ((a-p.a)^(p.a-p.b))/((a-b)^(p.a-p.b));
        res.x += (b.x-a.x)*t;
        res.y += (b.y-a.y)*t;
        return make_pair(2,res);
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
bool hide(line u,line v,point in)
{
	point temp1,temp2;
	temp1=(u.a.y>=v.a.y?u.a:v.a);
	temp2=(u.a.y>=v.a.y?v.a:u.a);
	if(temp1.x<=temp2.x && temp2.x<in.x &&xmult(in,temp1,temp2)>eps)
		return true;
	if(temp1.x>=temp2.x && temp2.x>in.x &&xmult(in,temp1,temp2)<eps)
		return true;
	return false;

}

double triangleArea(point a,point b,point c)
{
	double k=a.x*b.y+b.x*c.y+c.x*a.y
			-b.x*a.y-c.x*b.y-a.x*c.y;
	return k>0?k/2:-k/2;
}


double solve( line l1, line l2 ) {
    pair<int, point> pr = l1 & l2;
    int x = pr.first;
    point p = pr.second;

    double ans;
    if( x == 0 || x == 1)
        return 0;
    if( !seg_inter( l1, l2 ) )
        return 0;

    point temp,temp2;
    line l3;
    temp = (l1.a.y<l2.a.y?l1.a:l2.a);
	l3.b = temp;
	temp.x -= 10000;
	l3.a = temp;
	temp = p;
    if(temp.y >= l1.a.y || temp.y >= l2.a.y)
		return 0.00;
	if(hide(l1,l2,temp))
		return 0.00;
	if(l1.a.y>=l2.a.y) {
		pr = l1 & l3;
		temp2 = pr.second;
	}
	else {
        pr = l2 & l3;
		temp2 = pr.second;
	}
	return triangleArea(l3.b,temp,temp2);
}

int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    int t;
    line l1,l2;
    scanf( "%d", &t );
    while( t -- ) {
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        l1 = line(point(x1,y1),point(x2,y2));
        l2 = line(point(x3,y3),point(x4,y4));

        printf( "%.2f\n", solve( l1, l2 ) );
    }
    return 0;
}
