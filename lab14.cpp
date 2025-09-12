#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(){
    string str ;
    cin >> str ;
    stack <string> st;

    for (int i = 0; i < str.size(); i++) {
   
    string s(1, str[i]);

     if(!st.empty() && (st.top() == s)){ 
            st.pop();
        }
     else {
            st.push(s);}
       }
        

    if(st.empty()){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}   