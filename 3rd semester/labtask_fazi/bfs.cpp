#include <iostream>
#include <list>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph {
    int V; // No. of vertices

    // Pointer to an array containing adjacency lists
    list<int> *adj; 

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w); 

    // prints BFS traversal from a given source s
    void BFS(int s); 
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    // Create a mapping from integers to characters
    char map[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << map[s] << " "; // Use the mapping to print the original label
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                queue.push_back(*i);
                visited[*i] = true;
            }
        }
    }
}

int main() {
    // Create a graph given in the diagram
 /*     A
       / \
      B   C
     /   / \
    D   E   F
 */
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4);
    g.addEdge(2, 5); 

    cout << "Breadth First Traversal is: ";
    g.BFS(0); // Start BFS from A (0)

    return 0;
}
