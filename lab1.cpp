#include <bits/stdc++.h>
using namespace std;

void trick(int a){
    vector <int> v(a);
    queue <int> q;
    for(int i = 0 ; i < a ; i++){
        q.push(i);
    }

    for(int k = 1 ; k <= a ; k++){
        for(int l = 1 ; l <= k ; l++){
            q.push(q.front());
            q.pop();
        }


        v[q.front()] = k;
        q.pop();
    }

    for(int i = 0 ; i < a ; i++){
        cout << v[i] <<  " ";
    }
    cout << endl;

}

int main() {
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;

        trick(a);
    }
    return 0;

}