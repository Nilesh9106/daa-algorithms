#include <bits/stdc++.h>
using namespace std;

void floyed(vector<vector<int>> cost,int v)
{
    vector<vector<int> > a(v,vector<int> (v,10000));
    
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            a[i][j] = cost[i][j];
        }
        a[i][i]=0;
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    // sample input
    // 4
    // 6
    // 0 1 3
    // 1 0 2
    // 0 3 5
    // 3 2 2
    // 1 3 4
    // 2 1 1
    //sample output
    // 0       3       7       5
    // 2       0       6       4
    // 3       1       0       5
    // 5       3       2       0
    
    int v;
    cout << "enter Number of vertices" << endl;
    cin >> v;
    int e;
    cout << "enter Number of Edges" << endl;
    cin >> e;
    vector<vector<int>> cost(v, vector<int>(v, 100000));
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
    }

    floyed(cost,v);

    return 0;
}