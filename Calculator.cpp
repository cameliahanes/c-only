#include <iostream>
#include <cmath>
using namespace std;

typedef struct
{

	int numarator,numitor;

}Rational;

Rational undoList[50];
int nrOperatiiU=0;
int nrOperatiiR=0;



void init_rational(Rational &r, int a, int b)
{
r.numarator = a;
r.numitor = b;
}

/*

	returneaza cel mai mare divizor comun a doua nr
	date: a,b, a,b - nr naturale, cel putin unul nenul

	rezultate: d, d nr natural, d=cmmdc(a,b)

*/

int cmmdc_rec(int a, int b)
{

	if (a == b)
	return a;
    else
    if (a>b)
    return cmmdc_rec(a - b, b);
        else
		return cmmdc_rec(a, b - a);

}

int cmmdc(int a, int b)
{

	if (a == 0)
    return b;

	if (b == 0)
     return a;

	return cmmdc_rec(a, b);

	//while (a != b)

	//{

	//	if (a > b)

	//		a = a - b;

	//	else

	//		b = b - a;

	//}

	//return a; //sau b

}
/*

	simplifica o fractie

*/

void simplifica(Rational &r, int valoare)
{
r.numarator /= valoare;
r.numitor /= valoare;
}

/*

	aduce o fractie la forma ireductibila

	date: r, r-Rational

*/

void ireductibil(Rational& r)
{
int d = cmmdc((unsigned int)(r.numarator), (unsigned int)(r.numitor));
simplifica(r, d);
}



Rational rational_aduna(Rational a, Rational b)
{
Rational suma;
    suma.numarator = a.numarator * b.numitor + a.numitor*b.numarator;
    suma.numitor = a.numitor*b.numitor;
    ireductibil(suma);

	return suma;
	}

Rational rational_scade(Rational a, Rational b)
{
    Rational diferenta;
    diferenta.numarator=a.numarator*b.numitor-a.numitor*b.numarator;
    diferenta.numitor=a.numitor*b.numitor;
    ireductibil(diferenta);
    return diferenta;
}

Rational rational_inmulteste(Rational a, Rational b)
{
    Rational produs;
    produs.numarator=a.numarator*b.numarator;
    produs.numitor=a.numitor*b.numitor;
    ireductibil(produs);
    return produs;
}

Rational rational_imparte(Rational a, Rational b)
{
    Rational impartire;
    impartire.numarator=a.numarator*b.numitor;
    impartire.numitor=a.numitor*b.numarator;
    ireductibil(impartire);
    return impartire;
}

void afiseazaNumar(Rational r)
{
cout << r.numarator << "/" << r.numitor << endl;
}

void calculator_aduna(Rational& total)
{
Rational r;
cout << "Dati numaratorul:";
cin >> r.numarator;
cout << "Dati numitorul:";
cin >> r.numitor;

undoList[++nrOperatiiU] = total;
total = rational_aduna(total, r);
}

void calculator_scade(Rational & total)
{
    Rational r;
    cout << "Dati numaratorul:";
    cin >> r.numarator;
    cout << "Dati numitorul:";
    cin >> r.numitor;

    undoList[++nrOperatiiU]=total;
    total=rational_scade(total, r);
}

void calculator_inmulteste(Rational &total)
{
    Rational r;
    cout << "Dati numaratorul:";
cin >> r.numarator;
cout << "Dati numitorul:";
cin >> r.numitor;

undoList[++nrOperatiiU] = total;
total=rational_inmulteste(total, r);
}

void calculator_imparte(Rational &total)
{
    Rational r;
    cout<<"Dati numaratorul:";
    cin>>r.numarator;
    cout<<"Dati numitorul:";
    cin>>r.numitor;

    undoList[++nrOperatiiU]=total;
    total=rational_imparte(total, r);
}

void runMenu(Rational& total)
{
char op;
do{
cout << "Total:";
afiseazaNumar(total);
cout << "+ Aduna \n - Scade \n * Inmulteste \n % Imparte \n c Reset \n u Undo \n r Redo \n x Exit \n >>"<<endl;
cin>>op;

switch (op)
{
case '+':
calculator_aduna(total);
break;

case '-':
calculator_scade(total);
break;
case 'c':
    init_rational(total, 0, 1);
    break;

case 'u':
    {
    int k = nrOperatiiU;
if (k > 0)
        {
            total = undoList[k];

           k--;
        }
    }
break;


case '*':
calculator_inmulteste(total);
break;

case '%':
calculator_imparte(total);
break;
}
	}while (op != 'x');

}

int main()

{
Rational total;
init_rational(total, 0, 1);
runMenu(total);

	return 0;

}
