#include <bits/stdc++.h>
using namespace std;
int main(){
    queue <long long> boris;
    queue <long long> nursik;

    long long count = 0;

    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        boris.push(a);
    }
    for(int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        nursik.push(a);
    }

    while(true){
        if(boris.empty()){
            cout << "Nursik " << count << endl;
            break;
        }
        else if (nursik.empty()){
            cout << "Boris " << count << endl;
            break;
        }
        else if (count >= 1000000){
            cout << "blin nichya" << endl;
            break;
        } 
        

       int b = boris.front();
       int n = nursik.front();

        boris.pop();
        nursik.pop();

       if((b==0 && n==9 ) ){   
              boris.push(b);
              boris.push(n);
              
              
              count++;
         }
          else if((b==9 && n==0 )  ){
              
              nursik.push(b);
              nursik.push(n);
              
              count++;
         }
        else if(b>n ){
                
                boris.push(b);
                boris.push(n);
                
                count++;
             }
        
       
        else if (n>b){
                
                nursik.push(b);
                nursik.push(n);
                count++;    
        }
        
        
    }
    
    return 0;


}