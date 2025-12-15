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
bool find(vector<int>p, int count, int m){
    bool found = false;
    for (int val : p) {
        if (val == m) {
            found = true;
            break;
        }
    }
    if (found) return true;
    return false;
}
    
int min_num(const string& A, const string& B){
    string repeat_A = A;
    int count = 1;
    int m =(int)B.size();
    int n = repeat_A.size();
    
    while (n<m)
    {
        repeat_A += A;
        n+=A.size(); // B substring
        count++;
    }
    string s = B + "#" + repeat_A;
    vector<int>p = prefix_func(s);
      
    if(find(p, count, m)) return count;
    
    repeat_A+=A ;
    count++ ;   
    s = B + "#" + repeat_A;
    p = prefix_func(s);

    if(find(p, count, m)) return count;
       
    
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



//find prefix
vector <int>pref(string s){
    int n = s.size();
    vector<int>pi (n);
    pi[0] = 0;
    for(int i = 0; i<n; i++){
        int j = pi[i-1];
        while(j>0 && s[i]!= s[j]){
            j = pi[j-1];
        } 
        if(s[i]==s[j])
        {
            j++ ;
        }
            pi[i] = j;
    }
    return pi;
}




