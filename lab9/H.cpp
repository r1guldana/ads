#include <bits/stdc++.h>
using namespace std;

void constructLps(const string &s, vector<int> &lps) {
    int n = s.size();
    lps.assign(n, 0);
    int len = 0;
    for (int i = 1; i < n; ++i) {
        while (len > 0 && s[i] != s[len])
            len = lps[len - 1];
        if (s[i] == s[len]) ++len;
        lps[i] = len;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;
    int n = s.size();

    vector<int> lps;
    constructLps(s, lps);

    int cnt = 0;
    for (int L = 1; 2 * L <= n; ++L) {
        int idx = 2 * L - 1; 
        if (lps[idx] > L) ++cnt; 
    }

    cout << cnt << endl;
    return 0;
}
