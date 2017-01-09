#include <iostream>

using namespace std;
void citire_Radacini ( double x[], int& grad ){
cout << "Care este gradul polinomului si cate radacini are aceste? ";
cin >> grad;
cout << "Acum dati radacinile polinomului: \n";
for ( int i = 0; i<=grad; i++ )
    cin >> x[i];
}
void DeterminaCoeficienti ( double x[], int grad, double a[] ){
//functia determina coeficientii polinomului, pe bza radainilor acestuia date ca parametru prin vectorul de double dat ca parametru
a[0] = 1;
a[grad] = 0;
for ( int k = 1; k< grad; k++ )
for ( int j = k; j >0; j-- ){
    a[j] = a[j-1] - a[j] * x[k-1];
}
}

void tparireCoeficientiPolinom (double a[], int grad){
for ( int i = 0; i<=grad; i++)
    cout << a[i] <<" ";
}
int main()
{
   int grad;
double a[100], x[100];
citire_Radacini(x, grad);
DeterminaCoeficienti(x, grad, a);
tparireCoeficientiPolinom(a, grad);
    return 0;
}
