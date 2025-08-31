#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[105];
int dist[105];
void dijkastra(int src)
{
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // queue<pair<int, int>> q;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {

        pair<int, int> par = pq.top();
        pq.pop();
        int par_node = par.first;
        int par_dist = par.second;

        // children k push kora
        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dist = child.second;
            if (par_dist + child_dist < dist[child_node])
            {
                dist[child_node] = par_dist + child_dist;
                pq.push({ child_node, dist[child_node] });
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
        int a, b, w;
        cin >> a >> b >> w;
        adj_list[a].push_back({b, w});
        // adj_list[b].push_back({a, w});
    }
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dijkastra(0);
    for (int i = 0; i < n; i++)
        cout << i << " -> " << dist[i] << endl;
    // memset(dist, INT_MAX, sizeof(dist));

    return 0;
}

/*
5 8
0 1 10
1 2 1
0 2 7
0 3 4
2 3 1
3 4 5
1 4 3
2 4 5
*/