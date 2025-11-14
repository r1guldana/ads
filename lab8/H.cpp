#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod1 = 1e9+7, mod2 = 1e9+9;
const ll p1 = 31, p2 = 37;
int k;

string find_common(vector<string>& v, int len) {
    if (len == 0) return "";
    
    set<pair<ll, ll>> common;
    string s1 = v[0];
    ll h1 = 0, h2 = 0, pow1 = 1, pow2 = 1;
    
    for (int i = 0; i < len; i++) {
        h1 = (h1 * p1 + s1[i] - 'a' + 1) % mod1;
        h2 = (h2 * p2 + s1[i] - 'a' + 1) % mod2;
        pow1 = (pow1 * p1) % mod1;
        pow2 = (pow2 * p2) % mod2;
    }
    common.insert({h1, h2});
    
    for (int i = len; i < s1.size(); i++) {
        h1 = (h1 * p1 - (s1[i-len] - 'a' + 1) * pow1 + s1[i] - 'a' + 1) % mod1;
        h2 = (h2 * p2 - (s1[i-len] - 'a' + 1) * pow2 + s1[i] - 'a' + 1) % mod2;
        if (h1 < 0) h1 += mod1;
        if (h2 < 0) h2 += mod2;
        common.insert({h1, h2});
    }
    
    for (int idx = 1; idx < k; idx++) {
        set<pair<ll, ll>> cur;
        string s = v[idx];
        h1 = 0; h2 = 0; pow1 = 1; pow2 = 1;
        
        for (int i = 0; i < len; i++) {
            h1 = (h1 * p1 + s[i] - 'a' + 1) % mod1;
            h2 = (h2 * p2 + s[i] - 'a' + 1) % mod2;
            pow1 = (pow1 * p1) % mod1;
            pow2 = (pow2 * p2) % mod2;
        }
        if (common.count({h1, h2})) cur.insert({h1, h2});
        
        for (int i = len; i < s.size(); i++) {
            h1 = (h1 * p1 - (s[i-len] - 'a' + 1) * pow1 + s[i] - 'a' + 1) % mod1;
            h2 = (h2 * p2 - (s[i-len] - 'a' + 1) * pow2 + s[i] - 'a' + 1) % mod2;
            if (h1 < 0) h1 += mod1;
            if (h2 < 0) h2 += mod2;
            if (common.count({h1, h2})) cur.insert({h1, h2});
        }
        
        common = cur;
        if (common.empty()) return "";
    }
    
    string s = v[0];
    h1 = 0; h2 = 0; pow1 = 1; pow2 = 1;
    
    for (int i = 0; i < len; i++) {
        h1 = (h1 * p1 + s[i] - 'a' + 1) % mod1;
        h2 = (h2 * p2 + s[i] - 'a' + 1) % mod2;
        pow1 = (pow1 * p1) % mod1;
        pow2 = (pow2 * p2) % mod2;
    }
    if (common.count({h1, h2})) return s.substr(0, len);
    
    for (int i = len; i < s.size(); i++) {
        h1 = (h1 * p1 - (s[i-len] - 'a' + 1) * pow1 + s[i] - 'a' + 1) % mod1;
        h2 = (h2 * p2 - (s[i-len] - 'a' + 1) * pow2 + s[i] - 'a' + 1) % mod2;
        if (h1 < 0) h1 += mod1;
        if (h2 < 0) h2 += mod2;
        if (common.count({h1, h2})) 
            return s.substr(i-len+1, len);
    }
    
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> k;
    vector<string> v(k);
    int min_len = 1e9;
    
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        min_len = min(min_len, (int)v[i].size());
    }
    
    int l = 0, r = min_len;
    string ans = "";
    
    while (l <= r) {
        int mid = (l + r) / 2;
        string res = find_common(v, mid);
        if (!res.empty()) {
            ans = res;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}