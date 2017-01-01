#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>
using namespace std;
char Litere[9]="bcdgknpt";
char VocalePosibile[4]="aou";

void CitireFraza(char C[100], int& length)
{
    char c[100];
    cout<<"Dati sirul: \n";
    cin.get(c, '\n');
    strcpy(C, c);
    length=strlen(c);

}

char CelMaiApropiatCaracter(char c, char Litere[10], int length)
{
    int distmin=30;
    char l;
  if(c>='A' && c<='Z')
    c=c+32;

  for(int i=0; i<strlen(Litere); i++){
        if(c==Litere[i])
        {
            return Litere[i];
        }

        if((abs)(Litere[i]-c)<distmin )
        {
            l=Litere[i];
            distmin=(abs)(Litere[i]-c);
        }
    }
        return l;
}

void ModificareCuvant(char p[100], char Litere[10], int length)
{
  p[0]= CelMaiApropiatCaracter(p[0], Litere, strlen(Litere));

    for(unsigned int i=1; i<strlen(p)-1; i++)
    {
        if(p[i]=='-')
      p[i+1]=p[0];
    }

    if(strchr(Litere, p[strlen(p)-1])!=0)
        {
          /*  strcat(p, CelMaiApropiatCaracter(p[strlen(p)-1], VocalePosibile, strlen(VocalePosibile)));
            strcat(p, 'h'); */
            cout<<p<<CelMaiApropiatCaracter(p[strlen(p)-1], VocalePosibile, strlen(VocalePosibile))<<'h'<<" ";
        }
        else
            cout<<p<<" ";
}

void ExtrageCuvinte(char c[100], int length)
{
    char *q;
    q=strtok(c, " ");
    while(q)
    {
        ModificareCuvant(q, Litere, strlen(q));
        q=strtok(NULL, " ");
    }

}

int main()
{
    char C[100];
    int length;
    CitireFraza(C, length);
ExtrageCuvinte(C, strlen(C));
    return 0;
}
