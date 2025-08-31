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
int n, e;
void bellman_ford()
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

    bool cycle = false;
    for (auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if (dist[a] != INT_MAX && dist[a] + c < dist[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative cycle detected" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dist[i] << endl;
       
    }
}

int main()
{

    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); // undirected
    }

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;

    bellman_ford();

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

    // for(auto ed:  edge_list)
    // {
    //     cout << ed.a << " " << ed.b << " " << ed.c << endl;
    // }

    return 0;
}

/*
4 4
0 2 5
0 3 12
2 1 2
1 3 3
*/