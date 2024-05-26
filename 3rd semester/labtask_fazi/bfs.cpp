#include <iostream> // Include the I/O stream library
#include <queue> // Include the queue library
#include <vector> // Include the vector library

using namespace std; // Use the standard namespace

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfs(vector<vector<int>>& adjList, int startNode,
         vector<bool>& visited)
{
    // Create a queue for BFS
    queue<int> q; // Declare a queue data structure of integers

    // Mark the current node as visited and enqueue it
    visited[startNode] = true; // Mark the start node as visited
    q.push(startNode); // Enqueue the start node

    // Iterate over the queue
    while (!q.empty()) { // While the queue is not empty
        // Dequeue a vertex from queue and print it
        int currentNode = q.front(); // Get the front element of the queue
        q.pop(); // Remove the front element from the queue
        cout << currentNode << " "; // Print the current node

        // Get all adjacent vertices of the dequeued vertex
        // currentNode If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int neighbor : adjList[currentNode]) { // Iterate over adjacent vertices
            if (!visited[neighbor]) { // If the neighbor has not been visited
                visited[neighbor] = true; // Mark it as visited
                q.push(neighbor); // Enqueue it
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adjList, int u, int v)
{
    adjList[u].push_back(v); // Add edge from u to v in the adjacency list
}

int main()
{
    // Number of vertices in the graph
    int vertices = 5; // Initialize the number of vertices

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(vertices); // Declare a vector of vectors to represent the graph

    // Add edges to the graph
    addEdge(adjList, 0, 1); // Add edge from 0 to 1
    addEdge(adjList, 0, 2); // Add edge from 0 to 2
    addEdge(adjList, 1, 3); // Add edge from 1 to 3
    addEdge(adjList, 1, 4); // Add edge from 1 to 4
    addEdge(adjList, 2, 4); // Add edge from 2 to 4

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false); // Initialize a vector to mark visited vertices

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth First Traversal starting from vertex "
            "0: ";
    bfs(adjList, 0, visited); // Perform BFS traversal from vertex 0

    return 0; // Return 0 to indicate successful execution
}

