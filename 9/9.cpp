#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int dist[MAX];
    bool visited[MAX];

    // Initialize
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    // Dijkstra's algorithm
    for (int i = 0; i < n - 1; i++)
    {
        int u = -1;
        int minDist = INT_MAX;

        // Find vertex with minimum distance
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        // Relax adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Display result
    cout << "\nShortest distances from source vertex "
         << source + 1 << ":\n";

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i + 1 << " : INF\n";
        else
            cout << "Vertex " << i + 1 << " : "
                 << dist[i] << "\n";
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, source;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    cout << "(Enter 0 if there is no edge)\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source vertex (1 to " << n << "): ";
    cin >> source;

    // Convert to 0-based indexing
    source--;

    dijkstra(graph, n, source);

    return 0;
}
