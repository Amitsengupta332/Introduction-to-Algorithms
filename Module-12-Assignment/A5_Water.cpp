#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        int idxMax1 = -1, idxMax2 = -1;
        for (int i = 0; i < n; ++i)
        {
            if (idxMax1 == -1 || h[i] > h[idxMax1])
            {
                idxMax2 = idxMax1;
                idxMax1 = i;
            }
            else if (idxMax2 == -1 || h[i] > h[idxMax2])
            {
                idxMax2 = i;
            }
        }

        int left = min(idxMax1, idxMax2);
        int right = max(idxMax1, idxMax2);

           cout << left << " " << right << endl;
    }

    return 0;
}