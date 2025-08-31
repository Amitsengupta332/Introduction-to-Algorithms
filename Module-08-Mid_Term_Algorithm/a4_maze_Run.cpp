#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> maze;
pair<int, int> start, dest;

vector<pair<int, int>> d = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}};

bool bfs()
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(M, {-1, -1}));

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;

    while (!q.empty() && !found)
    {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + d[dir].first;
            int ny = y + d[dir].second;

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (!visited[nx][ny] && (maze[nx][ny] == '.' || maze[nx][ny] == 'D'))
                {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});

                    if (maze[nx][ny] == 'D')
                    {
                        found = true;
                        dest = {nx, ny};
                        break;
                    }
                }
            }
        }
    }

    if (!found)
        return false;

    pair<int, int> cur = dest;
    while (cur != start)
    {
        auto [px, py] = parent[cur.first][cur.second];
        if (maze[cur.first][cur.second] == '.')
            maze[cur.first][cur.second] = 'X';
        cur = {px, py};
    }
    return true;
}

int main()
{
    
    cin >> N >> M;
    maze.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < M; j++)
        {
            if (maze[i][j] == 'R')
                start = {i, j};
            if (maze[i][j] == 'D')
                dest = {i, j};
        }
    }

    bfs();
    for (auto &row : maze)
        cout << row << endl;
    return 0;
}
