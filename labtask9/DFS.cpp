#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
public:
    vector<list<int>> adj;

    Graph(int V) : adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        for (auto i : adj[v])
            if (!visited[i])
                DFS(i, visited);
    }

    int countConnectedComponents() {
        int count = 0;
        vector<bool> visited(adj.size(), false);
        for (int i = 0; i < adj.size(); ++i) {
            if (!visited[i]) {
                DFS(i, visited);
                count++;
            }
        }
        return count;
    }
};

int main() {
    Graph g(6); 

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 5); 

    int components = g.countConnectedComponents();
    cout << "Number of connected components: " << components << endl;

    return 0;
}
