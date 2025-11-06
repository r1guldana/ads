#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

string get_hash(const string& s) {
    long long h = 0;
    long long ppow = 1;
    for (int i = 0 ; i<s.size(); i++) {
        h = (h + (s[i]- 47) * ppow) % mod;
        ppow = (ppow * 11) % mod;
    }
    stringstream ss;
    ss << h;
    return ss.str();
}
bool is_num(const vector<string>& str, const string& s) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == s ) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    vector<string> mixed(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> mixed[i];
    }
    vector<string> used;
    
    for (int i = 0; i < 2 * n; i++) {
        string candidate = mixed[i];
        bool found_used = false ;
        for (int j = 0; j < used.size(); j++) {
            if (used[j] == candidate) {
                found_used  = true;
                break;
            }
        }
        if(found_used) continue;
        string hash = get_hash(candidate);
        if(is_num(mixed, hash)  && hash!=candidate){
            cout << "Hash of string \"" << candidate << "\" is " << hash << endl;
            used.push_back(candidate);
            used.push_back(hash);
        }   
    }
    return 0;
}