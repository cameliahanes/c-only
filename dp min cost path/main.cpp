#include <bits/stdc++.h>
using namespace std;
#define R 100
#define C 100

int min(int x, int y, int z);

int minCost(int cost[R][C], int m, int n)
{
     int i, j;

     int dp[R][C];

     dp[0][0] = cost[0][0];

     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++)
        dp[i][0] = dp[i-1][0] + cost[i][0];
    /* now first line */
     for (j = 1; j <= n; j++)
        dp[0][j] = dp[0][j-1] + cost[0][j];

     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            dp[i][j] = min(dp[i-1][j-1],
                           dp[i-1][j],
                           dp[i][j-1]) + cost[i][j];



cout << endl << "cost matrix \n\n";
     for (i = 0; i <= m; i++){
        for (j = 0; j <= n; j++)
            cout << cost[i][j] << " ";
            cout << endl;
    }
    cout << endl;

cout << endl << "dp matrix \n\n";
     for (i = 0; i <= m; i++){
        for (j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
            cout << endl;
    }
    cout << endl;

     return dp[m][n];
}

int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int main()
{
    int cost[R][C];
    ifstream f("graph.txt");
    int v, e;
    f >> v >> e;
    for ( int i = 0; i < v; ++ i ){
        for ( int j = 0 ; j < v; ++ j )
            cost[i][j] = 32766;
    }
    int i = 0;
    while ( i < e ){
        int a, b, c;
        f >> a >> b >> c;
        cost[a][b] = c;
        i++;
    }
    int cos = minCost(cost, 2, 2);
    if ( cos <= 0 )
        printf("The graph contains a negative cost cycle.\n");
    else if (cos >= 32766)
        printf("There is no path between the edges.\n");
   printf(" %d ", cos);
   return 0;
}
