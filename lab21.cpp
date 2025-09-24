#include <bits/stdc++.h>
#include <cmath>
 using namespace std ;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
      this -> data = data ;
      this -> next = NULL ;
    }
  };

  int main(){
    int n , k;
    cin >> n ;
    Node* front = NULL;
    Node* tail = NULL;
    for(int i=0 ; i<n ; i++ ){
      int val;
      cin >> val;
      
      Node* newNode = new Node(val);

      if(!front){
        front = tail = newNode ;
      }
      else{
        tail -> next = newNode ;  /*1, 2, 3, ...  */
        tail = newNode;
      }
    }
    cin >> k ;

    int index = 0;
    int current_i = 0;
    Node* current = front ;
    int close_offset = abs(current->data - k) ;
     

    while (current != NULL)
    {
      int offst = abs(current->data - k);
      if(offst < close_offset){
        close_offset = offst ;
        index = current_i ;

      }
      current = current->next ;
      current_i++ ; 
    }
    

    cout << index << endl;
    return 0;
    
    
  }