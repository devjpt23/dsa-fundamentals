/**
 * Breadth-First Search (BFS) - Graph Traversal
 *
 * BFS explores a graph level by level, visiting all neighbors of the
 * current vertex before moving deeper. It uses a queue (FIFO) to
 * maintain traversal order and a visited array to avoid revisiting nodes.
 *
 * Time Complexity:  O(V + E) where V = vertices, E = edges
 * Space Complexity: O(V) for the visited array and queue
 */

#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
   private:
    int V;                   // Number of vertices
    vector<list<int>> adj;   // Adjacency list representation

   public:
    Graph(int v);
    void addEdge(int u, int v);
    vector<int> BFS(int s);
};

// Initialize the graph with v vertices and v empty adjacency lists
Graph::Graph(int v) {
    V = v;
    adj.resize(v);
}

// Add an undirected edge between vertex u and vertex v
// to change to digraph: remove either one of the statements below.
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/**
 * Perform BFS starting from vertex s.
 *
 * Algorithm:
 * 1. Create a visited array (all false) and a queue
 * 2. Mark the start vertex as visited and enqueue it
 * 3. While the queue is not empty:
 *    a. Dequeue the front vertex (current)
 *    b. Add it to the result
 *    c. For each unvisited neighbor: mark visited and enqueue
 * 4. Return the traversal order
 */
vector<int> Graph::BFS(int s) {
    vector<int> res;
    vector<bool> visited(V, false);
    queue<int> traversal;

    // Seed the BFS with the starting vertex
    visited[s] = true;
    traversal.push(s);

    while (!traversal.empty()) {
        int curr = traversal.front();
        traversal.pop();
        res.push_back(curr);

        // Explore all neighbors of the current vertex
        for (auto neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                traversal.push(neighbor);
            }
        }
    }

    return res;
}

int main() {
    /*
     * Graph Structure (undirected):
     *
     *       0 --- 1
     *       |   / | \
     *       |  /  |  3
     *       | /   | / \
     *       2 --- 4 --- 5
     *
     *  Adjacency List:
     *  0: 1, 2
     *  1: 0, 3, 4, 2
     *  2: 0, 4, 1
     *  3: 1, 4, 5
     *  4: 2, 3, 5, 1
     *  5: 3, 4
     */
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "BFS starting from vertex 2: ";
    vector<int> results = g.BFS(2);
    for (auto r : results) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}