#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        string s;
        long long k;
        cin >> s >> k;
        int n = s.size();
        vector<int> pi = prefix_function(s);
        int overlap = pi[n - 1]; 
        long long ans = n + (k - 1) * (n - overlap);
        cout << ans << endl;
    }
    return 0;
}
