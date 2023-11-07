// C++ Code for Kruskal’s Spanning Tree Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};
// Class to represent a graph
class Graph {
    int V;
    vector<Edge> edges;
public:
    Graph(int vertices) : V(vertices) {}

    // Function to add an edge to the graph
    void addEdge(int u, int v, int w) {
        Edge edge = {u, v, w};
        edges.push_back(edge);
    }
    // Function to find the parent of a node
    int find(vector<int>& parent, int i) {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }
    // Function to perform union of two sets of x and y
    void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);
        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
    // Function to perform Kruskal's algorithm
    void kruskal() {
        vector<Edge> result;
        int i = 0;
        int e = 0;
        // Sort the edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });
        vector<int> parent(V);
        vector<int> rank(V);

        for (int node = 0; node < V; node++) {
            parent[node] = node;
            rank[node] = 0;
        }
        // Apply Kruskal's algorithm
        while (e < V - 1) {
            Edge nextEdge = edges[i++];
            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);
            if (x != y) {
                e++;
                result.push_back(nextEdge);
                Union(parent, rank, x, y);
            }
        }
       // print the minimum spanning tree
        cout << "Minimum Spanning Tree" << endl;
        for (const auto& edge : result) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        }
    }
};
int main() {
    Graph g(4);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 1, 6);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 20);
    g.addEdge(2, 3, 10);
    g.kruskal();
    return 0;
}