#include <bits/stdc++.h>
using namespace std;

int compare(const string& s, int i, int m, const string& t ){
    for(int j = 0 ; j < m ; j++){
        if (i + j >= s.size()) return 1;  
        if (s[i + j] < t[j]) return -1;
        if (s[i + j] > t[j]) return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    int n1 = s1.size(); 
    int n2 = s2.size();
    int m = t.size();
    int m_len = min(n1, n2)- m + 1;
    vector<long long> p;
    int count = 0;
    for (int i = 0 ; i < m_len; i++){
        if(s1.compare(i, m, t) == 0 && s2.compare(i, m, t) == 0 ){
        count++;
        }
    }
    cout << count << endl;
    return 0;
}
