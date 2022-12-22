#include<iostream>
#include<vector>
#include<list>
#include<queue>
using  namespace std;

class Graph{
    int V;
    vector<list<int>> adj;
public:
    Graph(int v); //constructor
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph :: Graph(int v)
{
    this -> V = v;
    adj.resize(V);
}

void Graph :: addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    queue<int> q;
    vector<bool> visited;
    visited.resize(this->V, false);
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        s = q.front();
        cout<<" "<<s;
        q.pop();

        for(auto adjelement : adj[s])
        {
            if(!visited[adjelement])
            {
                q.push(adjelement);
                visited[adjelement] = true;
            }
        }
    }
}

int main()
{
    int v = 4;
    Graph g(v);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}