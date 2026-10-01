#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge
{
    int u, v, w;
};

// ---------- PRIM'S ALGORITHM ----------

void prims(vector<vector<int>> graph, int n)
{
    vector<bool> visited(n + 1, false);

    int total = 0;
    visited[1] = true;

    cout << "\n--- Prim's Algorithm ---\n";

    for (int k = 0; k < n - 1; k++)
    {

        int minWeight = INT_MAX;
        int u = -1, v = -1;

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                for (int j = 1; j <= n; j++)
                {

                    if (!visited[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < minWeight)
                    {

                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Prevent segmentation fault
        if (v == -1)
        {
            cout << "Graph is not connected.\n";
            return;
        }

        visited[v] = true;

        cout << u << " - " << v
             << " : " << minWeight << endl;

        total += minWeight;
    }

    cout << "Total MST Weight = " << total << endl;
}

// ---------- KRUSKAL'S ALGORITHM ----------

int findParent(vector<int> &parent, int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

void unite(vector<int> &parent, int a, int b)
{
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (a != b)
        parent[b] = a;
}

void kruskals(vector<Edge> edges, int n)
{

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.w < b.w;
         });

    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int total = 0;
    int count = 0;

    cout << "\n--- Kruskal's Algorithm ---\n";

    for (Edge e : edges)
    {

        if (findParent(parent, e.u) !=
            findParent(parent, e.v))
        {

            unite(parent, e.u, e.v);

            cout << e.u << " - " << e.v
                 << " : " << e.w << endl;

            total += e.w;
            count++;

            if (count == n - 1)
                break;
        }
    }

    cout << "Total MST Weight = " << total << endl;
}

// ---------- MAIN ----------

int main()
{

    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    vector<Edge> edges;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;

        edges.push_back({u, v, w});
    }

    prims(graph, n);
    kruskals(edges, n);

    return 0;
}
