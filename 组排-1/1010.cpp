#include <iostream>
#include <cstring>

using namespace std;

int arr[ 10 ] ;

int main()
{
    int t ;
    cin >> t ;
    while ( t -- ){
        int n ;
        while ( cin >> n ){
            if ( n < 0 )
            {
                cout << 0 <<endl;
                continue;
            }
            n++;
            int flag = 1 ;
            memset( arr, 0 ,sizeof( arr));
            while ( flag){
                int temp = n ;
                for ( int i = 1 ; i <= 8 ; i ++  )
                {
                    arr[i] = temp % 10 ;
                    temp = temp /10 ;
                }
                if ( arr[8] !=0 && (arr[8] == arr[7]) )
                {
                    n = n / 1000000 ;
                    n ++ ;
                    n = n * 1000000 ;
                    break ;
                }
                if ( arr[7] !=0 && (arr[7] == arr[6]) )
                {
                    n = n / 100000 ;
                    n ++ ;
                    n = n * 100000 ;
                    continue ;
                }
                if ( arr[6] !=0 && (arr[6] == arr[5]) )
                {
                    n = n / 10000 ;
                    n ++ ;
                    n = n * 10000 ;
                    continue ;
                }
                if ( arr[5] !=0 && (arr[5] == arr[4]) )
                {
                    n = n / 1000 ;
                    n ++ ;
                    n = n * 1000 ;
                    continue ;
                }
                if ( arr[4] !=0 && (arr[4] == arr[3]) )
                {
                    n = n / 100 ;
                    n ++ ;
                    n = n * 100 ;
                    continue ;
                }
                if ( arr[3] !=0 && (arr[3] == arr[2]) )
                {
                    n = n / 10 ;
                    n ++ ;
                    n = n * 10 ;
                    continue ;
                }
                if ( arr[2] !=0 && (arr[2] == arr[1]) )
                {
                    n = n / 1 ;
                    n ++ ;
                    n = n * 1 ;
                    continue ;
                }

                flag = 0 ;


            }

            cout << n <<endl ;

        }
    }
    return 0;
}
