#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p){
    if (head == NULL || p == 0) {
        node->next = head;
        return node;
    }
    
    Node* cur = head;
    for(int i = 0; i < p-1 && cur != NULL; i++){
        cur = cur->next;
    }
    
    if (cur != NULL) {
        node->next = cur->next;
        cur->next = node;
    }
    return head;
}

Node* remove(Node* head, int p){
    if (head == NULL) return NULL;
    
    if(p == 0){
        Node* new_head = head->next;
        delete head;
        return new_head;
    }
    
    Node* cur = head;
    for(int i = 0; i < p-1 && cur != NULL; i++){
        cur = cur->next;
    }
    
    if (cur != NULL && cur->next != NULL) {
        Node* del = cur->next;
        cur->next = del->next;
        delete del;
    }
    return head;
}

Node* replace(Node* head, int p1, int p2){
    if (head == NULL || p1 == p2) return head;
    
    Node* repl = NULL;
    Node* prev = NULL;
    
    if (p1 == 0) {
        repl = head;
        head = head->next;
        repl->next = NULL;
    } else {
        Node* cur = head;
        for (int i = 0; i < p1 - 1 && cur != NULL; i++) {
            cur = cur->next;
        }
        if (cur == NULL || cur->next == NULL) return head;
        
        repl = cur->next;
        cur->next = repl->next;
        repl->next = NULL;
    }
    
    if (p2 == 0) {
        repl->next = head;
        return repl;
    } else {
        Node* cur = head;
        for (int i = 0; i < p2 - 1 && cur != NULL; i++) {
            cur = cur->next;
        }
        if (cur == NULL) {
           
            cur = head;
            while (cur->next != NULL) cur = cur->next;
            cur->next = repl;
        } else {
            repl->next = cur->next;
            cur->next = repl;
        }
        return head;
    }
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* cur = head;
    Node* next_ = NULL;

    while(cur != NULL){
        next_ = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_;
    }
    return prev;
}

void print(Node* head){
    if (head == NULL) {
        cout << -1 << endl;
        return;
    }
    Node* cur = head;
    while(cur != NULL){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x){
    if (head == NULL || x == 0) return head;
    
    int len = 0;
    Node* current = head;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    
    x = x % len;
    if (x == 0) return head;
    
    Node* new_tail = head;
    for(int i = 0; i < x - 1; i++){
        new_tail = new_tail->next;
    }
    
    Node* new_head = new_tail->next;
    Node* tail = new_head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    tail->next = head;
    new_tail->next = NULL;
    return new_head;
}

Node* cyclic_right(Node* head, int x){
    if (head == NULL || x == 0) return head;
    
    int len = 0;
    Node* current = head;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    
    x = x % len;
    if (x == 0) return head;
    
    return cyclic_left(head, len - x);
}

int main(){
    Node* head = NULL;
    while (true) {
        int command; cin >> command;
        if (command == 0){
            break;
        } else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        } else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        } else if (command == 3){
            print(head);
        } else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5){
            head = reverse(head);
        } else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}