#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<long long,long long> > b;

int main()
{
    long long n;
    while(cin >>n) {
        //b.clear();
        long long i=1,j=1,sum=0;
        for(;;) {
            while(sum<n) {
                sum+=j*j;
                j++;
            }
            if((j-1)*(j-1)>n) break;
            if(sum==n) {
                b.push_back(make_pair(i,j));
            }
            sum-=i*i;
            i++;
        }
        cout<<b.size()<<endl;
        for(vector<pair<long long,long long> >::const_iterator p = b.begin(); p != b.end(); ++p) {
            cout <<p->second-p->first<<" ";
            for(long long q=p->first;q<p->second;q++)
                cout <<q<<" ";
            cout <<endl;
        }
    }
    return 0;
}
