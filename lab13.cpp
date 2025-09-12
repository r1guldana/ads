#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int main() {
    string text1, text2;
    cin >> text1 >> text2;

    queue<string> q1;
    queue<string> q2;
    for (int i = 0; i < text1.size(); i++) {
        if(text1[i] == '#'){
            if (!text1.empty()){ q1.pop();}
        }
       else {
            string s(1, text1[i]);
            q1.push(s);
        }
    }
    for (int i = 0; i < text2.size(); i++) {
        if(text2[i] =='#'){
            if (!text2.empty()){
             q2.pop();
            }
        }
       else {
            string s(1, text2[i]);
            q2.push(s);
}}

if (q1.size() != q2.size()) { {
        cout << "NO" << endl;
        return 0;
    }
    while (!q1.empty() && !q2.empty()) {
        if (q1.front() != q2.front()) {
            cout << "NO" << endl;
            return 0;
        }
        q1.pop();
        q2.pop();
    }}

    cout << "YES" << endl;
    return 0;

}