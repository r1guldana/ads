#include <bits/stdc++.h>
using namespace std ;

class Node {
    public:
    string data;
    Node *next;

    Node(string data){
      this -> data = data ;
      this -> next = NULL ;
    }
  };
class count_name{
public:
    bool contain_name(Node* head, string stdnt_name){
        Node* cur = head ;
        while(cur!= NULL){
            if(cur->data == stdnt_name){
                return true ;
            }
            cur = cur->next ;
    }
    
            return false; }

    void remove(Node* head ){
        Node* current= head ;
        while(current != NULL && current->next != NULL){
             if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } 
            else{
            current = current->next;
        }
        }
    }

    int count(Node* head ){
       
        long long counts = 0;
        Node* cur = head ;
        while(cur != NULL){
             counts++;
             cur = cur->next ;
            }
            
        
            return counts ;
}

void print_reverse_recursive(Node* head) {
    if (head == NULL) return;
    print_reverse_recursive(head->next);
    cout << head->data << endl;
}

};

  int main(){
    int n ;
    cin >> n ;
    Node* head = NULL ;
    Node* tail = NULL ;
    for(int i = 0 ; i < n ; i++){
        string name ;
        cin >> name;
        if(head == NULL){
            head = tail = new Node(name);
        }
        else{
            tail->next =  new Node(name);
            tail = tail ->next ;
        }
    }


    count_name cn ;
     cn.remove(head);

    long long sudents_num = cn.count(head) ;
   
    cout <<"All in all: " << sudents_num << endl;

    cout <<"Students:" << endl;

    Node* current = head;
 cn.print_reverse_recursive(head);
 
return 0 ;

 
  }