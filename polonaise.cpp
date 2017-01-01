#include <iostream>

using namespace std;

int main()
{
    int X[100], lungime=0;
    char op;
    int element;
    int ok;
    char d;
    cout<<"Doriti sa continuati (d/n) ? \n";
    cin>>d;
    while( d=='d')
    {
    cout<<"Introduceti operand/operator (1/0): ";
    {
        cin>>ok;
        if(ok==1)
        {
            cout<<"Dati operandul: ";
            cin>>element;
            X[lungime]=element;
            lungime++;
        }
        else
        {
            if(ok==0)
            {
                cout<<"Dati operatorul ( + * / - ): ";
                cin>>op;
                switch(op)
                {
                case '+':
                    {
                    X[lungime-2]+=X[lungime-1];
                    lungime--;
                    break;
                    }
                case '*':
                    {
                    X[lungime-2]*=X[lungime-1];
                    lungime--;
                    break;
                    }
                case '/':
                    {
                    X[lungime-2]/=X[lungime-1];
                    lungime--;
                    break;
                    }
                case '-':
                    {
                    X[lungime-2]-=X[lungime-1];
                    lungime--;
                    break;
                    }
                }

            }
            else
                cout<<"=eroare la introducere optiune=";
        }
        cout<<"Doriti sa continuati (d/n) ? \n" ;
        cin>>d;
    }
    }
    cout<<"Rezultatul operatiei este: \n "<<X[0];

    return 0;
}
