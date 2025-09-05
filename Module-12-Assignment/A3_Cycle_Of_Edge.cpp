#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 100005;
int par[MAXN];
int group_size[MAXN];

int find(int node)
{
    if (par[node] == -1)
        return node;
    return par[node] = find(par[node]);
}

void dsu_union(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);
    if (leaderA == leaderB)
        return;

    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{

    int n, e;
    cin >> n >> e;

    memset(par, -1, sizeof(par));
    for (int i = 1; i <= n; i++)
        group_size[i] = 1;
    int cycleEdges = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderU = find(a);
        int leaderV = find(b);

        if (leaderU == leaderV)
        {
            cycleEdges++;
        }
        else
        {
            dsu_union(a, b);
        }
    }

    cout << cycleEdges << "\n";
    return 0;
}