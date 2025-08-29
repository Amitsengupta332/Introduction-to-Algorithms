#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}
// bool bfs(int si, int sj, int di, int dj) {
//     if (grid[si][sj] == '-' || grid[di][dj] == '-') return false;

//     queue<pair<int,int>> q;
//     q.push({si, sj});
//     vis[si][sj] = true;

//     while (!q.empty()) {
//         auto [x, y] = q.front();
//         q.pop();

//         if (x == di && y == dj) return true; // destination পাওয়া গেছে

//         for (auto dir : d) {
//             int nx = x + dir.first;
//             int ny = y + dir.second;
//             if (valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == '.') {
//                 vis[nx][ny] = true;
//                 q.push({nx, ny});
//             }
//         }
//     }
//     return false;
// }

bool dfs(int si, int sj, int di, int dj) {
    if (si == di && sj == dj) return true;  
    vis[si][sj] = true;

    for (auto dir : d) {
        int nx = si + dir.first;
        int ny = sj + dir.second;
        if (valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == '.') {
            if (dfs(nx, ny, di, dj)) return true;
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

       int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    memset(vis, false, sizeof(vis));

    if (dfs(si, sj, di, dj)) cout << "YES\n";
    else cout << "NO\n";
  
    return 0;
}