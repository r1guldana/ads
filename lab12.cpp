#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ages(n);
    for (int i = 0 ; i<n ; i++){
        cin >> ages[i];
    }
    stack<int> stk ;
    vector<int> result(n);
    for (int i = 0; i < n; i++){
        while (!stk.empty() && ages[stk.top()]> ages[i] ){
            stk.pop();
        }
        if (stk.empty()){
            result[i] = -1 ;
        } else {
            result[i]= ages[stk.top()];
        }
         stk.push(i);
    }
    for(int i = 0 ; i<n ; i++){
        cout << result[i] << " ";
    }
    return 0;
}