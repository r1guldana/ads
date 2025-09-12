#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n < 2) return false;
    for(int index = 2 ; index*index <= n ; index++){ 
        if(n % index == 0){
            return false;}
    }
    return true;
}


int main(){
    int n;
    cin >> n;
    if(isprime(n)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}