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
    int len = prefix[s.size()-1];
    if(len>0 && len>= city.length()){
        string suffix = P.substr(P.length() - len);
        if(city.substr(0, len) == suffix) return city;
    }

    for(int i = m+1 ; i<s.size(); i++){
        if(prefix[i]==m ){ 
            return city;
        }
    }
    return "";
}
int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    string P;
    cin>> P ;
    int N;
    cin>>N;
    vector<string>cities(N);
    vector<string> pssbl_n ;
    for (int i = 0; i < N; i++)
    {
        string Lower;
        cin>> Lower;
        transform(Lower.begin(), Lower.end(), Lower.begin(), ::tolower);
        cities.push_back(Lower);
    }
    for (int i = 0; i < N; i++)
    {
        string name = possible_names(cities[i], P);
        if(!name.empty()) pssbl_n.push_back(name);
    }
    cout << pssbl_n.size()<<endl;
        for(int i = 0 ; i< pssbl_n.size(); i++ ){
        cout << pssbl_n[i] << endl;
    }
    
    return 0;
}