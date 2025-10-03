#include <iostream>
using namespace std ;

class Node{
    public:
    int data;
    Node *left, *right; 
    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    } 
};
class BST{
    public:
    Node*root ;
    BST(){
        root = NULL;
    }
    Node* insert(Node*node, int data){
        if(node == NULL){
            node = new Node(data);
            return node;
        }
        if(data <= node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;      
    }
    int countt(Node*node){
        if(node == NULL) return 0;
         int count = 0;
         if(node->left != NULL && node->right != NULL) {
            count = 1;
        }
        return count + countt(node->left)+countt(node->right) ;
    }
};
int main(){
    int N ;
    cin >> N;
    BST *bst = new BST();
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        bst->root = bst->insert(bst->root, val);
    }

cout << bst->countt(bst->root) << endl ;

return 0;
}