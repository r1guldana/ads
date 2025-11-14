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
    
    vector<ll> h1(n + 1), h2(n + 1), p1(n + 1, 1), p2(n + 1, 1);
    
    for (int i = 0; i < n; ++i) {
        p1[i + 1] = p1[i] * pw1 % mod1;
        p2[i + 1] = p2[i] * pw2 % mod2;
        h1[i + 1] = (h1[i] * pw1 + s[i] - 96) % mod1;
        h2[i + 1] = (h2[i] * pw2 + s[i] - 96) % mod2;
    }
    
    unordered_set<uint64_t> st;
    st.reserve(n * n);
    
    for (int l = 0; l < n; ++l) {
        ll base1 = h1[l], base2 = h2[l];
        int max_r = n - l;
        for (int len = 1; len <= max_r; ++len) {
            int r = l + len;
            ll hash1 = (h1[r] - base1 * p1[len]) % mod1;
            ll hash2 = (h2[r] - base2 * p2[len]) % mod2;
            if (hash1 < 0) hash1 += mod1;
            if (hash2 < 0) hash2 += mod2;
            st.insert(((uint64_t)hash1 << 32) | hash2);
        }
    }
    
    cout << st.size() << endl;
    return 0;
}