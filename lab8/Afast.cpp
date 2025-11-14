#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

string hashing(const string &s) {
    ll h = 0, p = 1;
    for (int i = 0; i < s.size(); i++) {
        h = (h + ((s[i] - 47) * p) % mod) % mod;
        p = (p * 11) % mod;
    }
    return to_string(h);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> v;
    unordered_set<string> st;
    
    for (int i = 0; i < n * 2; i++) {
        string s;
        cin >> s;
        v.push_back(s);
        st.insert(s);
    }
    
    int cnt = 0;
    
    for (int i = 0; i < v.size(); i++) {
        if (cnt == n) break;
        string hs = hashing(v[i]);
        if (st.find(hs) != st.end()) {
            cout << "Hash of string \"" << v[i] << "\" is " << hs << endl;
            cnt++;
        }
    }
    
    return 0;
}