#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) 
        z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
         z[i]++;
        if (i + z[i] - 1 > r)
         l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> z = z_function(s);
    int cnt = 0;
    for (int L = 1; 2 * L < n; L++) {
        if (z[L] >= L) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
