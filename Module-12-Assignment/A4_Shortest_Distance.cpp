#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
long long distMat[MAXN][MAXN];
int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                distMat[i][j] = 0;
            else
                distMat[i][j] = LLONG_MAX;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        distMat[a][b] = min(distMat[a][b], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (distMat[i][k] != LLONG_MAX && distMat[k][j] != LLONG_MAX)
                {
                    distMat[i][j] = min(distMat[i][j], distMat[i][k] + distMat[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (distMat[x][y] == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << distMat[x][y] << "\n";
    }
    return 0;
}