#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
vector<Edge> edge_list;
int dist[1005];

void bellman_ford(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dist[a] != INT_MAX && dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;

    bellman_ford(n);

    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (auto ed : edge_list)
    //     {
    //         int a, b, c;
    //         a = ed.a;
    //         b = ed.b;
    //         c = ed.c;
    //         if (dist[a] != INT_MAX && dist[a] + c < dist[b])
    //         {
    //             dist[b] = dist[a] + c;
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++)
        cout << i << " -> " << dist[i] << endl;

    // for(auto ed:  edge_list)
    // {
    //     cout << ed.a << " " << ed.b << " " << ed.c << endl;
    // }

    return 0;
}