#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int cnt = 1;  
    for (auto dir : d)
    {
        int ci = si + dir.first;
        int cj = sj + dir.second;
        if (valid(ci, cj) && grid[ci][cj] == '.' && !vis[ci][cj])
        {
            cnt += dfs(ci, cj);
        }
    }
    return cnt;
}
int main()
{

    return 0;
}