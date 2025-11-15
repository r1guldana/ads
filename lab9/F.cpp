#include <bits/stdc++.h>
using namespace std ;


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
void occurence(string pattern, string text){
    string s = pattern + "#" + text;

    int n = s.size();
    int m = pattern.size();

    vector<int> pi = prefix_function(s);
    vector<int>count;
    for (int i = m + 1; i < n; i++) {
        if (pi[i] == m) {
            int pos = i - 2 * m;
            count.push_back(pos+1);
        }
    }
    cout << count.size()<<endl;
    for (int i = 0; i < count.size(); i++)
    {
        cout << count[i]<< " ";
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin>> s1>>s2 ;

    occurence(s2, s1);
    
    return 0 ;
}