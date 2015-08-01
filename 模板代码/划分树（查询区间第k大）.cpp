/*
OJ: HDOJ
ID: forever
TASK: 2665.Kth number
LANG: C++
NOTE: ����������ѯ�����k��
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#define MAX 400020

using namespace std;

int Left[20][MAX];//Left[i][j]��ʾ��i���ǰj�������м������ֵ���������
int sorted[MAX];//��ʾ�ź����
int tree[20][MAX];//tree[i][j]��¼��i��ĵ�j��Ԫ��

void build_tree ( int l , int r , int v )
{
    int mid = ( l + r ) /2;
    if ( l == r ) return;
    int m = sorted[mid];
    int same = mid-l+1;//same��ʾ��m=sorted[mid]����ҷֵ���ߵ�
    for ( int i = l ; i <= r ; i++ )
        if ( tree[v][i] < m ) same--;
    int lpos = l;
    int rpos = mid+1;
    int ss = 0;
    for ( int i = l ; i <= r; i++ )
    {
        if ( i == l ) Left[v][i] = 0;
        else Left[v][i] = Left[v][i-1];
        if ( tree[v][i] < m )
        {
            tree[v+1][lpos++] = tree[v][i];
            Left[v][i]++;
        }
        else if ( tree[v][i] > m )
            tree[v+1][rpos++] = tree[v][i];
        else
        {
            if ( ss < same )
            {
                tree[v+1][lpos++] = tree[v][i];
                Left[v][i]++;
                ss++;
            }
            else tree[v+1][rpos++] = tree[v][i];
        }
    }
    build_tree ( l , mid , v+1 );
    build_tree ( mid+1 , r , v+1 );
}

int query ( int L , int R , int l  , int r , int k , int v )
{
    int mid = (L+R)/2;
    if ( l == r ) return tree[v][l];
    int off;//off��ʾ[L,l-1]�ж��ٸ��ֵ����
    int cnt;//cnt��ʾ[l,r]�ж��ٸ��ֵ��ұ�
    if ( l == L )
    {
        off = 0;
        cnt = Left[v][r];
    }
    else
    {
        off = Left[v][l-1];
        cnt = Left[v][r] - Left[v][l-1];
    }
    if ( cnt >= k ) //��k���ֵ���ߣ���Ȼȥ������ҵ�k��
    {
        int lnew = L + off;
        int rnew = lnew + cnt - 1;
        return query ( L , mid , lnew , rnew , k , v+1 );
    }
    else
    {
        off = l - L - off;//[L,l-1]�ж��ٸ��ֵ��ұ�
        k = k -cnt;
        cnt = r - l + 1 - cnt;// cnt ��ʾ[l,r]�ж��ٸ��ֵ��ұ�
        int lnew = mid+1+off;
        int rnew = lnew + cnt - 1;
        return query ( mid+1 , R , lnew , rnew , k , v+1 );
    }
}

int main ( )
{
    int t,n , m , l , r , k , i;
    scanf ( "%d" , &t );
    while ( t-- )
    {
        scanf ( "%d%d" , &n , &m );
        for ( int i = 1 ; i <= n ; i++ )
        {
            scanf ( "%d" , &tree[0][i] );
            sorted[i] = tree[0][i];
        }
        sort ( sorted + 1 , sorted + n + 1 );
        build_tree ( 1 , n , 0 );
        for ( int i = 0 ; i < m ; i++ )
        {
            scanf ( "%d%d%d", &l , &r , &k );
            printf ( "%d\n" , query ( 1 , n , l , r , k , 0 ));
        }
    }
    return 0;
}
