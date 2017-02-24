#include <bits/stdc++.h>
#define pi 3.14159265358979323846264338327950288
using namespace std;

const inline double minim(double a, double b){ return (a < b ? a:b);}

int main(){
    long min;
    long max;
    double final_min_difference = 1.0;
    double min_difference = 1.0;
    cin >> min >> max;
    long final_numitor, final_numarator;
    long numitor = min;
    while ( numitor <= max ){
        min_difference = 1.0;
        long numarator = 3 * numitor;
        double left = (double)numarator/numitor;
        double right = (double)(numarator+1)/numitor;

        min_difference = minim(abs(left-pi), abs(right-pi));
        if ( min_difference < final_min_difference ){
            final_min_difference = min_difference;
            final_numitor = numitor;
            final_numarator = numarator+1;
        }
        ++numitor;
    }
    cout << final_numarator << "/" << final_numitor;
    return 0;
}
