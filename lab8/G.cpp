#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll pw1 = 31;
const ll pw2 = 37;

pair<vector<ll>, vector<ll> > prefix_hash(const string &s, ll mod_val, ll pw_val) {
    int n = s.size();
    vector<ll> h(n + 1, 0), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw_val + (s[i] - 'a' + 1)) % mod_val;
        p[i + 1] = (p[i] * pw_val) % mod_val;
    }
    return make_pair(h, p);
}

ll get_hash(const vector<ll> &h, const vector<ll> &p, int l, int r, ll mod_val) {
    ll res = (h[r] - h[l] * p[r - l]) % mod_val;
    if (res < 0) res += mod_val;
    return res;
}

ll hashify(string tmp){
    ll hash_tmp = 0;
    for (int i = 0; i < tmp.size(); i++) {
        hash_tmp = (hash_tmp * pw1 + (tmp[i] - 'a' + 1)) % mod;
    }
    return hash_tmp;
}

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int n, l, r;
    unordered_map<uint64_t, int> mp;

    cin >> s >> n;

    pair<vector<ll>, vector<ll>> h1_p1 = prefix_hash(s, mod1, pw1);
    pair<vector<ll>, vector<ll>> h2_p2 = prefix_hash(s, mod2, pw2);
    
    vector<ll> h1 = h1_p1.first;
    vector<ll> p1 = h1_p1.second;
    vector<ll> h2 = h2_p2.first;
    vector<ll> p2 = h2_p2.second;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j <= s.size(); j++) {
            ll x1 = get_hash(h1, p1, i, j, mod1);
            ll x2 = get_hash(h2, p2, i, j, mod2);
            uint64_t key = ((uint64_t)x1 << 32) | (uint64_t)x2;
            mp[key]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        l--;
        ll x1 = get_hash(h1, p1, l, r, mod1);
        ll x2 = get_hash(h2, p2, l, r, mod2);
        uint64_t combine = ((uint64_t)x1 << 32) | (uint64_t)x2;
        cout << mp[combine] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}