#include <bits/stdc++.h>
using namespace std;

bool reachable(int n)
{
    queue<int> q;
    vector<bool> visited(n + 1, false);
    
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == n) return true;

        // Next moves
        long long add = cur + 3;
        long long mul = cur * 2;

        if (add <= n && !visited[add]) {
            visited[add] = true;
            q.push(add);
        }
        if (mul <= n && !visited[mul]) {
            visited[mul] = true;
            q.push(mul);
        }
    }
    return false;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (reachable(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}