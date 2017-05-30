#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    Graph()   {
    ifstream f ("graph1k.txt");
    int v, lats;
    f >> v;
    this->V = v;
    adj = new list<int>[V];
    f >> lats;
    while(lats){
        int a, b, c;
        f >> a >> b >> c;
        this->addEdge(a, b);
        lats --;
    }
     }
    ~Graph()       { delete [] adj; }

    void addEdge(int v, int w);
    void greedyColoring(int vertice);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

void Graph::greedyColoring(int vertice)
{
    int result[V];
    result[vertice]  = 0;
    for (int u = 0; u < V; u++)
        if ( u != vertice )
        result[u] = -1;  // no color is assigned to u

        /*
    cout << "\n\nResult: \n";
    for ( int i = 0; i < V; ++ i )
        cout << result[i] << " ";
    cout << endl;
*/
    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;
/*
    cout << "\nAvailable: \n";
    for ( int i = 0; i < V; ++ i )
        cout << available[i] << " ";
    cout << endl;
*/

    for (int u = 0; u < V; u++)
    {
        if ( u == vertice )
            continue;
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;
    /*
        cout << "\n\nAvailable: \n";
        for ( int i = 0; i < V; ++ i )
            cout << available[i] << " ";
        cout << endl;
*/
        result[u] = cr; // Assign the found color
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
/*
        cout << "\n\nResult: \n";
        for ( int i = 0; i < V; ++ i )
            cout << result[i] << " ";
        cout << endl;
        cout << "\n\nAvailable: \n";
        for ( int i = 0; i < V; ++ i )
            cout << available[i] << " ";
        cout << endl;

*/
    }

    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;


    cout << "\n\nTotal number of colors: ";

    int colors_used[V+1];
    for ( int i = 0; i < V+1; ++ i )
        colors_used[i] = 0;

    for ( int i = 0; i < V; ++ i ){
        colors_used[ result[ i ] ] ++;
    }

    int number_of_colors_used = 0;
    for ( int i = 0; i < V; ++ i ){
        if ( colors_used[i] > 0 )
            number_of_colors_used ++;
    }
cout << number_of_colors_used << endl;

}

int main()
{
  /*  Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Coloring of graph 1 \n";
    g1.greedyColoring(0);

    cout << "Coloring of graph 1 staring from vertice 2 \n";
    g1.greedyColoring(2);
*/

    Graph g1;
    g1.greedyColoring(0);

    g1.greedyColoring(1);

    g1.greedyColoring(100);

  /*  Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColoring of graph 2 \n";
    g2.greedyColoring(0);
*/
    return 0;
}



