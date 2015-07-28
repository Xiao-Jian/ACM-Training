#include <iostream>

using namespace std ;

int main ()
{
    int n ;
    while ( cin >> n ){
        int sum = 1 ;
        int ans = 1 ;
        int i =1;
        while  ( i < n   )
        {
            sum *= 2 ;
            i += sum;
            ans ++;
        }
        cout << ans <<endl ;
    }
    return 0;
}
