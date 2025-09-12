#include <bits/stdc++.h>
using namespace std;

bool isPileWord(const string &s1, const string &s2)
{
    if (s1.size() != s2.size())
        return false;
    vector<int> freq(26);

    for (char c : s1)
        freq[c - 'a']++;
    for (char c : s2)
        freq[c - 'a']--;

    for (int f : freq)
    {
        if (f != 0)
            return false;
    }
    return true;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (isPileWord(s1, s2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}