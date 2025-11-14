#include <bits/stdc++.h>
using namespace std ;
vector<int> prefix_func(string a1){
    int n = a1.size();
    vector<int> pi(n);
    pi[0] = 0;    
    for (int i = 1; i <n; i++)
    {
        int j = pi[i-1];
        while(j>0 && a1[i]!=a1[j]){
            j = pi[j-1];
        }
        if(a1[i]==a1[j]) j++;
        pi[i] = j ;
    }
    return pi;
}
string possible_names(string city, string P){
    string s = city + "#" + P;
    int n = P.size();
    int m = city.size();
    int count = 0 ;
    //vector<int> prfx_P = prefix_func(P);
    // vector<int> prfx_city = prefix_func(city);
    vector<int> prefix = prefix_func(s);
    int len = prefix.back();
    if(len>0){
        string suffix = P.substr(P.length() - len);
        if(city.substr(0, len) == suffix) return city;
    }
/*
    for(int i = m+1 ; i<s.size(); i++){
        if(prefix[i]==m ){ 
            return city;
        }
    }
*/
    return "";
}
int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    string P;
    cin>> P ;
    transform(P.begin(), P.end(), P.begin(), ::tolower);
    int N;
    cin>>N;
    vector<string>cities;
    vector<string> pssbl_n ;
    for (int i = 0; i < N; i++)
    {
        string Lower;
        cin>> Lower;
        transform(Lower.begin(), Lower.end(), Lower.begin(), ::tolower);
        cities.push_back(Lower);
    }
    int max_len = 0;
    vector<string> candidates;
    for (int i = 0; i < N; i++)
    {
        string name = possible_names(cities[i], P);
        if(!name.empty()) {
          pssbl_n.push_back(name);
          string s = cities[i] + "#" + P;
            vector<int> prefix = prefix_func(s);
            int match_len = prefix[s.size() - 1];
            
            if (match_len > max_len) {
                max_len = match_len;
                candidates.clear();
                candidates.push_back(cities[i]);
            }
            else if (match_len == max_len) {
                candidates.push_back(cities[i]);
          }
      }
    }
    cout << candidates.size()<<endl;
        for(int i = 0 ; i< candidates.size(); i++ ){
          string name = candidates[i];
          if(!name.empty()) name[0] = toupper(name[0]);
        cout << name << endl;
    }
    
    return 0;
}