#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007LL;
typedef long long ll;

pair< vector<long long>, vector<long long> > prefix_hash(const string &s, long long pw) {
    int n = (int)s.size();
    vector<long long> h(n + 1, 0);
    vector<long long> p(n + 1, 1);
    for (int i = 0; i < n; ++i) {
        int val = (s[i] - 'a' + 1);
        h[i + 1] = ( (h[i] * pw) + val ) % mod; //hash
        p[i + 1] = (p[i] * pw) % mod; // power
    }
    return std::make_pair(h, p);
}

long long substr_hash(const vector<long long> & h, const vector<long long> & p, int l, int r) {
    long long res = (h[r] - (h[l] * p[r - l]) % mod) % mod;
    if (res < 0) res += mod;
    return res;
}

long long get_hash(const string &s, long long pw) {
    long long hh = 0; //hashes
    for (int i = 0; i < (int)s.size(); ++i) {
        int val = (s[i] - 'a' + 1);
        hh = (hh * pw + val) % mod;
    }
    return hh;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const long long pw = 29LL;

    while (1) {
        int n;
        if (!(cin >> n)) return 0;
        if (n == 0) break;

        vector<string> patterns(n);
        for (int i = 0; i < n; ++i) {
            cin >> patterns[i];
        }

        string text;
        cin >> text;

        pair< vector<long long>, vector<long long> > hp = prefix_hash(text, pw);
        vector<long long> h = hp.first;
        vector<long long> p = hp.second;

        vector<int> counts(n, 0);
        int L = (int)text.size();

        for (int i = 0; i < n; ++i) {
            const string &pat = patterns[i];
            int m = (int)pat.size();
            if (m > L) {
                counts[i] = 0;
                continue;
            }

            long long hash_pat = get_hash(pat, pw);
            int cnt = 0;
            for (int start = 0; start + m <= L; ++start) {
                long long subh = substr_hash(h, p, start, start + m);
                if (subh == hash_pat) {
                    bool equal = true;
                    for (int k = 0; k < m; ++k) {
                        if (text[start + k] != pat[k]) {
                            equal = false;
                            break;
                        }
                    }
                    if (equal) ++cnt;
                }
            }
            counts[i] = cnt;
        }

        int mx = INT_MIN;
        for (int i = 0; i < n; ++i)
            if (counts[i] > mx) mx = counts[i];

        cout << mx << endl;
        for (int i = 0; i < n; ++i) {
            if (counts[i] == mx) cout << patterns[i] << endl;
        }
    }

    return 0;
}
