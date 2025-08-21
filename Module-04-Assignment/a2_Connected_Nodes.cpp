#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int a[n];
    vector<int> adj_list[n];

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // undirected
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;

        if (!adj_list[x].empty())
        {
            sort(adj_list[x].begin(), adj_list[x].end(), greater<int>());
            for (int node : adj_list[x])
                cout << node << " ";
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}