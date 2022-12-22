#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cout<<"Enter number of vertices and edges: "<<endl;
    cin>>n>>m;
    int adj[n][m];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cout<<"Enter edge (v1, v2) : ";
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout<<"Graph is : \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(adj[i][j] == 1 && adj[j][i] == 1)
            {
                cout<<" --> "<<adj[j][i];
            }
        }
    }
}