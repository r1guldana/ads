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
  class occurense{
    public:
     int occurs(Node* head, int element){
        int count = 0 ;
        Node* cur = head ;
        while(cur!= NULL){
            if(cur->data == element){
                count++ ;
            }
            cur=cur->next ;
        }
        return count ;
     }

     void sort(Node* head, int N){
        if (head == NULL || head->next == NULL) return;

        for (int i = 0; i < N- 1; i++) {
        Node* current = head ;
         
            for (int j = 0; j < N - i - 1; j++) {
                if ( current-> data < current->next->data) {
                    int temp = current-> data ;
                    current-> data  = current-> next -> data ;
                    current-> next -> data = temp;
                }
                current = current->next;
            }
        }
    
}
     int find_max(Node* head){
        
            int max_frqncy = 0;

            int mode = head -> data;
            
            Node* cur = head;
       while(cur != NULL){
        int freq = occurs(head, cur->data); 
            if (freq > max_frqncy) {
                max_frqncy = freq;
                mode = cur -> data ;

            }
            cur = cur->next;
        }
        return max_frqncy;
    
     }


     bool contaun(Node* head , int val){
        Node* cur = head ;
        while(cur != NULL){
            if(cur-> data == val){
                return true ;
            }
            cur = cur-> next ;

        }
        return false ;
     }
  };



int main(){
    int N ;
    cin >> N ;
     Node* head = NULL;
     Node* tail = NULL ;

    for (int i = 0 ; i<N; i++){
        int j ;
        cin >> j;
        if(head == NULL){head = tail = new Node(j);}

        else{ tail->next = new Node(j);
        tail = tail ->next ;}
        }
    occurense oc ;
    int max = oc.find_max(head);

    //new mode node
Node*mode_head = NULL;
Node* mode_tail = NULL;
Node* cur = head ;
while(cur != NULL){
    int element = cur->data;
    int freq = oc.occurs(head, element);
    if (freq == max && !oc.contaun(mode_head, element)){
        if(mode_head == NULL){
            mode_head = mode_tail = new Node(element);
        }
        else{
            mode_tail->next = new Node(element);
            mode_tail = mode_tail->next;
        }
    }
    cur = cur->next ;

}

int counts = 0 ;
cur = mode_head ;
   while(cur != NULL){
    counts ++ ;
    cur = cur->next;
   }

oc.sort(mode_head, counts);
cur = mode_head ;
while(cur != NULL){
    cout << cur-> data ;
    if(cur->next != NULL){
        cout << " ";
    }
    cur = cur ->next ;
}
cout << endl ;

     
    return 0;
}