#include <bits/stdc++.h>

 using namespace std ;

class Node{
    public :
    string data;
    Node* next ;
    
    Node(string data){
      this -> data = data ;
      this -> next = NULL ;
    }
    
};
class LinkedList {
    public:
    Node* head;
    Node* tail;
    

    LinkedList() {
        head = NULL;
        tail = NULL;
        
    }

    void insert_at_tail(string val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }}

    void cyclic_shift(int k, int n) {
        if (head == NULL || k==0) 
            return;
       
        Node* old_tail = head;
       while (old_tail->next != NULL) {
        old_tail = old_tail->next;
    }

    old_tail->next = head;

    Node* new_tail = head;
    for (int i = 1; i < k; ++i) {
        new_tail = new_tail->next;
    }
    Node* new_head = new_tail->next;

    new_tail->next = NULL;

    head = new_head;
    tail = new_tail;
}};


 int main(){

    int n, k;
    cin >> n >> k ;

    LinkedList poem ;
    
    for(int i=0 ; i<n ; i++ ){
      string  val;
      cin >> val;
    poem.insert_at_tail(val);
    }


   
    poem.cyclic_shift(k, n);
    
    Node* current = poem.head ;
    while(current != NULL ){
    cout << current-> data <<' ';
    current = current->next;
    }
        cout << endl;
    return 0 ;
 }