#include <iostream>
#define eps 0.0000001
#include <cmath>
using namespace std;

double radical ( double x, double ordin ) {
float a1, a2;
a1 = ( 1 + x ) / ordin;
a2 = ( a1 + x / a1 ) / ordin;
while ( a1 - a2 > eps ){
    a1 = a2;
    a2 = ( a1 + x / a1 ) / ordin;
}
return a1;
}

int invers ( int x ){
if ( x ==0 )
    return 0;
else{
        int cif = log10(x);
      return x%10 * pow(10, cif) + invers(x/10);

}
}

int cifra_de_Control ( unsigned long x ){
int sum = 0;
while ( x != 0 ){
    sum += x%10;
    x/=10;
}
while ( sum > 9 ){
    int nr = sum;
    sum = 0;
    while ( nr != 0 ){
        sum += nr%10;
        nr /=10;
    }
}
return sum;
}

unsigned long dublare ( unsigned long x ){
if ( x == 0 )
    return 0;
else {
    if ( x % 2 == 0 ){
        return 100 * dublare(x/10) + 10*(x % 10) + x%10;
    } else
    return 10*dublare(x/10 ) +x % 10;
}
}

unsigned long mutazerouri ( unsigned long x ){
    int d = 0;
    int zece = 1;
    while ( x > 0 ){
        if ( x % 10 != 0 ){

        }
    }

}

int euclid ( int a, int b ){
int c;
while ( b != 0  ){
         c = a % b;
    a = b;
    b = c;
}
return a;
}

int euclidRec ( int a , int b ){
if ( b == 0 )
    return a;
else {
    if ( a > b )
        return euclidRec( b, a%b);
    else
        return euclidRec( a, b%a);
}
}

void descompunere_recursiva ( unsigned int n, unsigned int div ){
if ( n == 1 )
    return ;
else {
    if ( n % div == 0 ){
        cout << div <<" ";
        int nr = 0;
        while ( n % div == 0 ){
            n/=div;
            nr ++;
        }
        cout << nr << " ";
    }
    descompunere_recursiva(n, div+1);
}
}

int fib ( int n ) {
if ( n == 0 || n == 1 ){

    return 1;
} else {

return fib(n-1)+fib(n-2);

}
}

#include <cmath>

int este_fibo ( int n ){
    int p = 5*n*n;
    if ( sqrt( p-4 ) == (int)sqrt( p-4 ) || sqrt( p+ 4) == (int)sqrt(p + 4 ) )
        return 1;
    return 0;
}


int main()
{
   double x;
   int ordin;
  /* cout << "Dati x: ";
   cin >> x;
   cout << "Dati ordinul radicalului: ";
   cin >> ordin;
   cout << "Radical de ordinul " << ordin << " din " << x << " este " << radical(x, ordin);  */
   unsigned int n, m;
   cin >> n ;
  // descompunere_recursiva(n, 2);
  //  cout << fib(5);
cout << este_fibo(n);
    return 0;
}
