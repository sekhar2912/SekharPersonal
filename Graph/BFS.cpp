#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


class Graph
{
private:
int no_of_vertices;
std::list<int> *adj;
public:
Graph(int V):no_of_vertices(V)
{
    adj = new list<int>[V];
}
void addEdge(int v,int e);
void BFS(int s);
};

void Graph::addEdge(int v,int e)
{
    
    adj[v].push_back(e);
}

void Graph::BFS(int s)
{
     bool *visited = new bool[no_of_vertices];
     for(int i =0;i<no_of_vertices;i++)
        visited[i] = false;

     queue<int> q;
     visited[s] = true;
     q.push(s);

     while (!q.empty())
     {
         s = q.front();
         std::cout << s << " " << std::endl;
         q.pop();

         for(auto i = adj[s].begin(); i!=adj[s].end();++i)
         {
             if(!visited[*i])
             {
               visited[*i] = true;
               q.push(*i);
             }
         }
     }
     
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
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}