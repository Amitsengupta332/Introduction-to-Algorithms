#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[105][105];
int level[105][105];

vector<pair<int, int>> d = {
    {2, -1}, {1, -2}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
bool valid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == di && y == dj)
            return level[x][y];  

        for (auto dir : d)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (valid(nx, ny) && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                level[nx][ny] = level[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        int ki, kj, qi, qj;
        cin >> ki >> kj;
        cin >> qi >> qj;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        int ans = bfs(ki, kj, qi, qj);
        cout << ans << "\n";
    }

    return 0;
}