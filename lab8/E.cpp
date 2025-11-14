#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
string restore_str(const vector<ll> & a){
    int n = a.size();
    string res;
    ll pow = 2;
    for (int i = 0; i < n; i++)
    {
        ll cur;
        if(i == 0){
            cur = a[0]; 
        }
        else {
            cur = (a[i]-a[i-1])/pow;
            pow*=2;
        }
        res.push_back(char(cur+97));
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin>>n;
    vector<ll>h(n);
    for (int i = 0; i < n ; i++)
    {
        cin>>h[i];
    }
    string s = restore_str(h);
    cout << s<< endl;
    return 0;
}