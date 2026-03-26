#include <list>
#include<queue>
#include <vector>
#include <iostream>

using namespace std;

class Graph{
    private:
        int V; // vertices
        vector<list<int>> adj; 
    
    public:
        Graph(int v);
        void addEdge(int v, int u);
        vector<int> BFS(int s);

};

Graph::Graph(int v) {
    // Set number of verticest
    V= v;
    // Resize the number of adjacency lists
    adj.resize(v);
}

void Graph::addEdge(int u, int v){
    
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> Graph::BFS(int s){
    vector<int> res;
    vector<bool> visited(V,false);
    queue<int> traversal;

    visited[s] = true;
    traversal.push(s);

    while (!traversal.empty()){
        int curr = traversal.front();
        traversal.pop();
        res.push_back(curr);

        for(auto i : adj[curr]){
            if(!visited[i]){
                visited[i] = true;
                traversal.push(i);
            }
        }
    }

    return res;
}


int main(){
    Graph g(6);
     // Create some edges to the vertices
  // Connections for vertex 0
  g.addEdge(0, 1);
  g.addEdge(0, 2);

  // Connections for vertex 1
  g.addEdge(1, 0);
  g.addEdge(1, 3);
  g.addEdge(1, 4);

  // Connections for vertex 2
  g.addEdge(2, 0);
  g.addEdge(2, 4);

  // Connections for vertex 3
  g.addEdge(3, 1);
  g.addEdge(3, 4);
  g.addEdge(3, 5);

  // Connections for vertex 4
  g.addEdge(4, 1);
  g.addEdge(4, 2);
  g.addEdge(4, 3);
  g.addEdge(4, 5);

  // Connections for vertex 5
  g.addEdge(5, 3);
  g.addEdge(5, 4);

  vector<int> results = g.BFS(2);
  for(auto r : results){
        cout << r << " ";
    }
cout << endl;

    return 0;
}