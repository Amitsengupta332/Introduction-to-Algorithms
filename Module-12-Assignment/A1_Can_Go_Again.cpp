#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
long long dist[1005];
int n, e;

bool bellman_ford(int source)
{
    for (int i = 1; i <= n; i++)
        dist[i] = LLONG_MAX;  
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (const Edge &ed : edge_list)
        {
            if (dist[ed.a] != LLONG_MAX && dist[ed.a] + ed.c < dist[ed.b])
            {
                dist[ed.b] = dist[ed.a] + ed.c;
            }
        }
    }

   
    for (const Edge &ed : edge_list)
    {
        if (dist[ed.a] != LLONG_MAX && dist[ed.a] + ed.c < dist[ed.b])
        {
            return false;  
        }
    }
    return true;  
}

int main()
{
    cin >> n >> e;
    edge_list.reserve(e);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge_list.emplace_back(a, b, c);
    }

    int source;
    cin >> source;

    int T;
    cin >> T;
    vector<int> queries(T);
    for (int i = 0; i < T; i++)
    {
        cin >> queries[i];
    }

    if (!bellman_ford(source))
    {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

    for (int d : queries)
    {
        if (dist[d] == LLONG_MAX)
            cout << "Not Possible\n";
        else
            cout << dist[d] << "\n";
    }

    return 0;
}