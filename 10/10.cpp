
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge
{
    int u, v, weight;
};

void bellmanFord(int V, int E, vector<Edge> &edges, int source)
{
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Step 1: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++)
    {
        for (const Edge &edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.weight;

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 2: Detect a negative-weight cycle
    for (const Edge &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;

        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v])
        {
            cout << "Negative-weight cycle detected!\n";
            return;
        }
    }

    // Step 3: Print shortest distances
    cout << "Shortest distances from source "
         << source << ":\n";

    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << '\n';
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    bellmanFord(V, E, edges, source);

    return 0;
}
