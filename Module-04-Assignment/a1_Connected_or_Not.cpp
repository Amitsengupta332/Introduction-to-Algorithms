#include <bits/stdc++.h>
using namespace std;

int main()
{
  
    int n, e;
    cin >> n >> e;

    set<pair<int, int>> edges;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.insert({u, v});
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (a == b || edges.count({a, b}))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
