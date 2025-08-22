#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int cnt = 1;  
    for (auto dir : d)
    {
        int dx = dir.first;
        int dy = dir.second;
        int ci = si + dx;
        int cj = sj + dy;
        if (valid(ci, cj) && grid[ci][cj] == '.' && !vis[ci][cj])
        {
            cnt += dfs(ci, cj);
        }
    }
    return cnt;
}


int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    vector<int> rooms;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                int cnt = dfs(i, j);
                rooms.push_back(cnt);
            }
        }
    }

    if (!rooms.empty())
    {
        sort(rooms.begin(), rooms.end());
        for (int i = 0; i < (int)rooms.size(); i++)
        {
            cout << rooms[i] << (i + 1 == (int)rooms.size() ? '\n' : ' ');
        }
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}