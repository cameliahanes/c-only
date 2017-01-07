#include <iostream>
#include<fstream>
#define dim 1000009
using namespace std;
int k[dim],i,n,max1,x,p[dim];

int main()
{
    ifstream f("mincinosi.in");
    ofstream g("mincinosi.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
   f>>p[i];
   k[p[i]]++;
  }
    for(i=1;i<=n;i++)
      if(i+k[i]==n)
        if (max1<k[i])
        {
   max1=k[i];
   x=i;
  }
   g<<max1<<"\n";
    for(i=0;i<=n;i++)
       if (p[i]==x)
   g<<i<<"\n";
f.close();
g.close();
    return 0;
}
