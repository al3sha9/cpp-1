#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Graph {
public:
    vector<list<int>> adj;
    Graph(int V) : adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void BFS(int v) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        visited[v] = true;
        q.push(v);
        while (!q.empty()) {
            v = q.front(); q.pop();
            cout << v << " ";
            for (auto i : adj[v])
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
        }
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (auto i : adj[v])
            if (!visited[i])
                DFS(i, visited);
    }
};

void printBinaryTreeBFS(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
}

void printBinaryTreeDFS(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printBinaryTreeDFS(root->left);
    printBinaryTreeDFS(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "BFS traversal of Binary Tree: ";
    printBinaryTreeBFS(root);
    cout << endl;

    cout << "BFS traversal of Graph: ";
    g.BFS(0);
    cout << endl;

    cout << "DFS traversal of Binary Tree: ";
    printBinaryTreeDFS(root);
    cout << endl;

    cout << "DFS traversal of Graph: ";
    vector<bool> visited(g.adj.size(), false);
    g.DFS(0, visited);
    cout << endl;


    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
