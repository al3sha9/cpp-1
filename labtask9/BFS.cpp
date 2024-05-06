#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> bfsShortestPath(vector<vector<int>>& adjList, int startNode, int endNode)
{
    queue<int> q;
    unordered_map<int, int> parent;
    vector<int> path;

    q.push(startNode);
    parent[startNode] = -1;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        if (currentNode == endNode) {
            while (currentNode != -1) {
                path.push_back(currentNode);
                currentNode = parent[currentNode];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int neighbor : adjList[currentNode]) {
            if (!parent.count(neighbor)) {
                q.push(neighbor);
                parent[neighbor] = currentNode;
            }
        }
    }

    return path;
}

void addEdge(vector<vector<int>>& adjList, int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adjList(vertices);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    int startNode = 0;
    int endNode = 4;

    vector<int> shortestPath = bfsShortestPath(adjList, startNode, endNode);

    cout << "Shortest path from " << startNode << " to " << endNode << ": ";
    for (int node : shortestPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
