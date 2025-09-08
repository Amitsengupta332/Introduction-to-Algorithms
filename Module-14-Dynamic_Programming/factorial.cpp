#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n == 1)
        return 1;
    int mul = fibo(n - 1);
    return n * mul;
}

int main()
{
    cout << fibo(5) << endl;
    return 0;
}