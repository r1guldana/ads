#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000007;
const ll pw = 31;

vector<ll> prefix_hash(const string &s) {
    int n = s.size();
    vector<ll> h(n + 1, 0), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw + (s[i] - 'a' + 1)) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }
    return h;
}

ll get_hash(const vector<ll> &h, const vector<ll> &p, int l, int r) {
    ll res = (h[r] - h[l] * p[r - l]) % mod;
    if (res < 0) res += mod;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s;

    int n;
    cin >> n;

    int len = s.size();
    string check(len, '0');

    vector<ll> h = prefix_hash(s);
    vector<ll> p(len + 1, 1);
    for (int i = 1; i <= len; i++) {
        p[i] = (p[i - 1] * pw) % mod;
    }

    for (int i = 0; i < n; i++) {
        cin >> t;
        ll hash_t = 0;
        for (char c : t) {
            hash_t = (hash_t * pw + (c - 'a' + 1)) % mod;
        }

        for (int j = 0; j + t.size() <= len; j++) {
            ll substr_hash = get_hash(h, p, j, j + t.size());
            if (substr_hash == hash_t) {
                for (int k = j; k < j + t.size(); k++) {
                    check[k] = '1';
                }
            }
        }
    }

    for (char c : check) {
        if (c == '0') {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
