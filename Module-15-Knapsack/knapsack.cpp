#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];


int knapsack(int i, int mx_weight)
{
    // 2 options
    // bag e rakhbo 
    // bag e rakhbo na
    int op1= knapsack(i-1, mx_weight-weight[i]);
    int op2= knapsack(i-1, mx_weight);

    return max(op1, op2);

}
int main()
{
    int n, mx_weight;
    cin >> n;
    int val[n], weight[n];

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cin >> mx_weight;

    knapsack(n-1, mx_weight);

    return 0;
}