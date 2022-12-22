#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph 
{
    int V;
    vector<list<int>> adj;
    vector<bool> visited;
public:
    Graph(int v);
    void addEdge(int u, int v);
    void DFS(int v);
};

Graph :: Graph(int v)
{
    this->V = v;
    adj.resize(V);
    visited.resize(V, false);
}

void Graph :: addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph :: DFS(int s)
{
    visited[s] = true;
    cout<<" "<<s;

    for(auto adjelement : adj[s])
    {
        if(!visited[adjelement])
        {
            DFS(adjelement);
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}