// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> v(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> v[i];
//         }
//         sort(v.begin(), v.end());
//         int mn = v[0];
//         int mx = v[n - 1];
//         if (mn % 2 == 0 && mx % 2 == 0)
//         {
//             cout << 0 << endl;
//         }
//         else
//         {
//             int i = 0, cnt1 = 0;
//             while (v[i] % 2 != mx % 2)
//             {
//                 i++;
//                 cnt1++;
//             }
//             int j = 0, cnt2 = 0;
//             while (v[j] % 2 != mn % 2)
//             {
//                 j--;
//                 cnt2++;
//             }

//             cout << min(cnt1, cnt2) << endl;
//         }

//         return 0;
//     }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int mn = v[0], mx = v[n - 1];

        // Case 1: Already fashionable
        if (mn % 2 == mx % 2) {
            cout << 0 << "\n";
            continue;
        }

        // Case 2: Need to remove some elements
        int cnt1 = n, cnt2 = n;

        // Option 1: remove from left side
        for (int i = 1; i < n; i++) {
            if (v[i] % 2 == mx % 2) {
                cnt1 = i;
                break;
            }
        }

        // Option 2: remove from right side
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] % 2 == mn % 2) {
                cnt2 = n - 1 - i;
                break;
            }
        }

        cout << min(cnt1, cnt2) << "\n";
    }

    return 0;
}
