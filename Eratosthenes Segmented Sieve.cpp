#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

void simpleSieve(int limit, vector<int> &prime){
//create a boolean array merk[]. A value in mark will finally be false if p is
//not a prime numebr, true otherwise
bool mark[limit+1];
memset(mark, true, sizeof(mark));
    for ( int p = 2; p*p < limit; ++p ){
        //if p is not changed then it is a prime
        if (mark[p] == true ){
            //update all multiples of p
            for ( int i = p*2; i < limit; i +=p )
                mark[i] == false;
        }
    }
    //print all numbers and store them in prime
    for ( int p = 2; p < limit; ++p ){
        if (mark[p] == true){
            prime.push_back(p);
            cout << p << " ";
        }
    }
}

void segmentedSieve(int n){
//compute all primes smaller or equsl to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    simpleSieve(limit, prime);
    //divide the range [0...n-1] in different segments
    //we've chosen segment size as square root of n
    int low = limit;
    int high = 2 * limit;
    //while all segments of range [0...n-1] are not processed,
    //pricess one segment at a time
    while ( low < n ){
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for ( int i = 0; i < prime.size(); ++i ){
            //find the minimum number in [low...high] that is a multiple of
            //prime[i]
            int loLim = floor(low/prime[i])*prime[i];
            if ( loLim < low ) loLim += prime[i];
            for ( int j = loLim; j < high; j+=prime[i] )
                mark[j-low] = false;
        }
        for ( int i = low; i < high; ++i )
            if ( mark[i-low] == true )
            cout << i << " ";
        //update low and high for the next segment
        low = low + limit;
        high = high + limit;
        if ( high >= n ) high = n;
    }
}

int main()
{
    int n;
  //  cin >> n;
  n = 10000;
    cout << "The primes smaller then the given number are: "<<"\n";
    segmentedSieve(n);
    return 0;
}
