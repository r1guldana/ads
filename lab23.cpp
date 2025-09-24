#include <bits/stdc++.h>
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
    int N ;
    cin >> N ;
     Node* head = NULL;
     Node* tail = NULL;
    for (int i = 0 ; i<N; i++){
        int j ;
        cin >> j;
        

        if (head == NULL){
            head = tail = new Node(j);}
        else {tail -> next = new Node(j);
          tail = tail->next;
        }}

    Node* current  = head;
    while ( current != NULL && current->next  != NULL){
      Node* del = current ->next;
      current ->next = del->next ;
      delete del ;
      current = current->next ;
    }

    Node* new_elements = head ;
    while( new_elements != NULL){
      cout <<  new_elements->data << " ";
       new_elements =  new_elements->next;
      
    }
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}