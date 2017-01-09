#include <iostream>

using namespace std;
void TiparireTriunghiPascal (int m){
int i=0;
while(i<m){
    int element = 1;
    cout<<element<<" ";
    for(int j=1; j<=i; j++){
        element=element * (i-j+1)/j;
        cout<<element<<" ";
    }
    cout<<endl;
    i++;
}
}
int main()
{
   int m;
   cin>>m;
   TiparireTriunghiPascal(m);
    return 0;
}
