#include <bits/stdc++.h>
using namespace std;
void leaders(int n, string str){
    deque <int> K;
    deque <int> S;
    for (int i = 0 ; i < n ; i++){
        if(str[i] == 'K'){
            K.push_back(i);
        }
        else {
            S.push_back(i);
        }
    }

    while (!K.empty() && !S.empty()){
        int k_vote = K.front(); 
        K.pop_front();
        int s_vote = S.front(); 
        S.pop_front();

        if( k_vote < s_vote){
              
            
            K.push_back(k_vote + n);
            
        }
        else {
            S.push_back(s_vote+n);
        
        }
    }
    if(K.empty()){
        cout << "SAKAYANAGI" << endl ;
    }
    else {
        cout << "KATSURAGI" << endl ;
    }

}


int main(){
    int n ;
    cin >> n ;
    string str ;
    cin >> str ;

    leaders(n, str);


    return 0;
}