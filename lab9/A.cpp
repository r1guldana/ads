#include <bits/stdc++.h>
using namespace std ;
vector<int> prefix_func(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0]= 0;
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j])
        {
            j = pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
int min_num(const string& A, const string& B){
    string repeat_A = A;
    int count = 1;
    int m = B.size();
    int n = repeat_A.size();

    string s = B + "#" + repeat_A;
    vector<int>p = prefix_func(s);
    while (n<m+A.size())
    {
        n+=A.size();  // B substring
        count++;
    }
    
    if(p.back()== m) {
        return count ;
    }
    
        repeat_A+=A ;
        count++ ;   
        s = B + "#"+repeat_A;
        p = prefix_func(s);
        if(p.back() == m) return count;
        else{return -1;}
    
    return -1;
}
int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >>B;
    int res = min_num(A, B);
    cout << res<<endl;
return 0;
}