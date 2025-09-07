#include <bits/stdc++.h>
using namespace std;

int rec(int n)
{
    if (n > 5)
        return 0;

    int sum = rec(n + 1);
    return n + sum;
    // cout << n << endl;
    // recursion(n + 1);
}

int main()
{
    cout << rec(1) << endl;
    // rec(1);
    return 0;
}