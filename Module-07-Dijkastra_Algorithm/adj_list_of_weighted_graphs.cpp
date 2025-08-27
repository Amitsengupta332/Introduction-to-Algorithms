#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj_list[n];
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for(auto p : adj_list[i])
        {
            cout << p.first << " " << p.second << ", ";
        }
        cout << endl;
        // for (pair<int, int> p : adj_list[i])
        //     cout << p.first << " " << p.second << ", ";
        // cout << endl;
    }

    return 0;
}