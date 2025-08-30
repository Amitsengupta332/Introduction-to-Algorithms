#include <bits/stdc++.h>
using namespace std;

char grid[8][8];
bool vis[8][8];
int level[8][8];
vector<pair<int, int>> d = {{2, -1}, {1, -2}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int n = 8, m = 8;
int main()
{
    n = 8, m = 8;
    string src, des;
    cin >> src >> des;

    int si, sj, di, dj;
    // cin >> si >> sj >> di >> dj;
    si = src[1] - '1';
    sj = src[0] - 'a';
    di = des[1] - '1';
    dj = des[0] - 'a';

    // cout << si << sj << " " << di << dj << endl;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    // bfs(si, sj);
    cout << level[di][dj] << endl;

    return 0;
}