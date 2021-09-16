#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph
{
private:
    int no_of_vertices;
    bool *visited = new bool[no_of_vertices];
    std::list<int> *adj;

public:
    Graph(int V) : no_of_vertices(V)
    {
        adj = new list<int>[V];
        for (int i = 0; i < no_of_vertices; i++)
            visited[i] = false;
    }
    void addEdge(int v, int e);
    void DFS(int s);
};

void Graph::addEdge(int v, int e)
{

    adj[v].push_back(e);
}

void Graph::DFS(int s)
{
    visited[s] = true;
    cout << s << " ";
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}