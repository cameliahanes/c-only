#include <iostream>
#include <fstream>
#define white 0
#define grey 1
#define black 2
#define nmax 50005
using namespace std;

ifstream f("sortaret.in");
ofstream g("sortaret.out");

typedef struct node {
    int v;
    node* next;
} *pnode, nod;


pnode L[nmax]; //neighbour list for each node
pnode address; //single linked list
int color[nmax];
int n, m;

void add(int i, int j){
    pnode p = new node;
    p->v = j;
    p->next = L[i];
    L[i] = p;
}

void Push(int noode){
    pnode p = new node;
    p->v = noode;
    p->next = address;
    address = p;
}

void DFS(int noode){
    color[noode] = grey;
    for ( pnode p = L[noode]; p; p = p->next )
        if (color[p->v] == white )
        DFS(p->v);
    color[noode] = black;
    Push(noode);
}

void topological_sort(){
    for ( int i = 1; i <= n; ++i )
        if ( color[i] == white )
        DFS(i);
}

void read(){
    f >> n >> m;
    int x, y;
    for ( ; m > 0; --m ){
        f >> x >> y;
        add(x, y);
    }
    f.close();
}

void write(){
    for ( pnode p = address; p; p = p->next )
        g << p->v << " ";
    g.close();
}

int main()
{
    read();
    topological_sort();
    write();
    return 0;
}
