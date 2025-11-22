#include <bits/stdc++.h>
using namespace std;

int main(){ 
    ios:: sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int A, B;
    cin >> A >> B;

    vector<int> path;
    int count = 0;

    while (B > A) {
        path.push_back(B);
        count++;
        if (B % 2 == 0) {
            B /= 2;
        } else {
            B += 1;
        }
    }

    while (A > B) {
        path.push_back(B);
        count++;
        B++;
    }

    reverse(path.begin(), path.end());

    cout << count << "\n";
    for (int i = 0 ; i<path.size();i++) cout << path[i] << " ";
    cout << endl;

    return 0 ;
}