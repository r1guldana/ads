#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll pw1 = 31;
const ll pw2 = 37;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size();
    
    vector<ll> h1(n + 1, 0), h2(n + 1, 0);
    vector<ll> p1(n + 1, 1), p2(n + 1, 1);
    
    for (int i = 0; i < n; i++) {
        p1[i + 1] = (p1[i] * pw1) % mod1;
        p2[i + 1] = (p2[i] * pw2) % mod2;
        h1[i + 1] = (h1[i] * pw1 + (s[i] - 'a' + 1)) % mod1;
        h2[i + 1] = (h2[i] * pw2 + (s[i] - 'a' + 1)) % mod2;
    }
    
    set<pair<ll, ll> > unique_h;

    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r <= n; r++) {
            ll hash1 = (h1[r] - h1[l] * p1[r - l] % mod1 + mod1) % mod1;
            ll hash2 = (h2[r] - h2[l] * p2[r - l] % mod2 + mod2) % mod2;
            unique_h.insert({hash1, hash2});
        }
    }
    cout << unique_h.size() << endl;
    return 0;
}