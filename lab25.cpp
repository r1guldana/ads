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

    bool occurence(Node* head, Node* current){
        Node* temp = head ;
        while(temp != current){
            if(temp->data == current->data){
                return false ;
            }
            temp = temp -> next ;

        }
        return true ;
    }

    int count(Node* head ){
        Node* unique_head = NULL;
        Node* unique_tail = NULL;
        int counts = 0;
        Node* cur = head ;
        while(cur != NULL){
            string cur_name = cur -> data ;
            if(!contain_name(unique_head, cur_name)){
                if(unique_head == NULL){
                    unique_head = unique_tail = new Node(cur_name);
                }
                else{
                    unique_tail->next = new Node(cur_name);
                    unique_tail = unique_tail->next;
                    }
             counts++;
        
            }
            cur = cur->next ;
        }
            return counts ;
}

    void sorting(Node* head , int n){
        if(head == NULL || head ->next == NULL) return ;
        
            for(int i = 0 ; i<n-1 ; i++ ){
                Node* cur = head ;
                for(int j = 0 ; j < n-1-i; j++){

                    if(cur-> data > cur->next->data){ //i>i+1
                        string temp = cur-> data ;
                        cur-> data  = cur->next->data ;
                        cur->next->data = temp ;
                    }
                    cur = cur-> next ;
                }
            
        }
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
    cn.sorting(head, n) ;

    int sudents_num = cn.count(head) ;
    cout <<"All in all: " << sudents_num << endl;

    cout <<"Students:" << endl;

    Node* current = head;

    while(current != NULL){
    if(cn.occurence(head, current)){
       
        cout << current->data << endl ;
    }
        current = current -> next ;        
}
return 0 ;

 
  }