// C++ Code for Prim’s Spanning Tree Algorithm
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define MAX_VERTICES 100
#define INF INT_MAX
vector<vector<int>> graph(MAX_VERTICES, vector<int>(MAX_VERTICES));
void primMST(int numVertices)
{
    vector<int> parent(numVertices);
    vector<int> key(numVertices);
    vector<bool> mstSet(numVertices);
    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < numVertices - 1; count++) {
        int minKey = INF;
        int minIndex = 0;

        for (int X = 0; X < numVertices; X++) {
            if (mstSet[X] == false && key[X] < minKey) {
                minKey = key[X];
                minIndex = X;
            }
        }
        mstSet[minIndex] = true;

        for (int X = 0; X < numVertices; X++) {
            if (graph[minIndex][X] && mstSet[X] == false && graph[minIndex][X] < key[X]) {
                parent[X] = minIndex;
                key[X] = graph[minIndex][X];
            }
        }
    }
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < numVertices; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}
int main()
{
    int numVertices = 3;
    cout << "Number of vertices: "<<numVertices<<endl;
    int pgraph[3][3] = {
        {2, 3, 4},
        {4, 5, 6},
        {6, 7, 8}
    };
    cout << "Adjacency matrix:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout<<"pgraph["<<i<<"]"<<"["<<j<<"]"<<" = "<<pgraph[i][j]<<endl;
            graph[i][j] = pgraph[i][j];
        }
    }
    primMST(numVertices);
    return 0;
}