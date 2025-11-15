#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int rotation_shift(string text, string pattern) {
    int n = text.size();
    string doubled = text + text;
    string s = pattern + "#" + doubled;
    vector<int> pi = prefix_function(s);
    int m = pattern.size();

    for (int i = m + 1; i < s.size(); i++) {
        if (pi[i] == m) {
            int pos = i - m ; 
            return pos % n;
        }
    }
    return -1; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, T;
    
    cin>>s;
    cin>> T;
    int cnt =  rotation_shift(T, s) ;
    cout << cnt <<endl;
    
    return 0;
}