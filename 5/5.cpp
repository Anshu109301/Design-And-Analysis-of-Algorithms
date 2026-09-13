#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

void DFS(int v, int removed)
{
    visited[v] = 1;

    for (int i = 0; i < n; i++)
        if (graph[v][i] && !visited[i] && i != removed)
            DFS(i, removed);
}

bool isCutVertex(int v)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int start = (v == 0) ? 1 : 0;

    DFS(start, v);

    for (int i = 0; i < n; i++)
        if (i != v && !visited[i])
            return true;

    return false;
}

int main()
{
    int e, u, v;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Cut Vertices: ";

    for (int i = 0; i < n; i++)
        if (isCutVertex(i))
            cout << i << " ";

    return 0;
}