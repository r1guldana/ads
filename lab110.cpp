#include <bits/stdc++.h>
using namespace std;
int main(){
    string str ;
    deque <int> deq ;
    while(cin >> str ){
    if (str == "!"){
        break ; }
   
    else if(str == "+" ){
        int n ;
        cin >> n ;
        deq.push_front(n);
    }
    else if(str == "-" ){
        int n ;
        cin >> n ;
        deq.push_back(n) ;
    }
    else if(str == "*" ){
        if(!deq.empty()){
            if(deq.size() == 1){
                cout << deq.front() * 2 << endl ;
                deq.pop_front() ;
            }
            else {
        int a = deq.front() ;
        int b = deq.back() ;
        
        deq.pop_front();
        deq.pop_back();
        int sum = a + b ;
        cout << sum << endl ;}
        }
        else if(deq.empty()){ 
            cout << "error" << endl ;
        }
    }
    else {
        cout << "error" << endl ;
    }
    
}    return 0;
}