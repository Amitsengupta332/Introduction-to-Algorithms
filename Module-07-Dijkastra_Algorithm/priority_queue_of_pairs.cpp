#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({2, 10});
    pq.push({1, 5});
    // while (!pq.empty())
    // {
    cout <<  pq.top().first << " " << pq.top().second << endl;
    // cout << pq.top() << " ";
    pq.pop();
    // }

    return 0;
}