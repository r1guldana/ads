#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST{
    
    public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data <= node->data) 
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

            return node;
    }
      Node *search(Node *node, int data) {
        if (node == NULL || node->data == data)
            return node;
        
        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }
    int subtree(Node *node){
        if(node == NULL) return 0;
        else return 1+subtree(node->left)+subtree(node->right);
    }
    
    
};

int main() {
    BST *bst = new BST();
    int N, X;
    cin >> N ;


    for(int i = 0 ; i<N;i++){
        int j;
        cin >> j;
         bst->root = bst->insert(bst->root, j);
    }
    cin >> X;
    Node* subroot = bst->search(bst->root, X);
    cout << bst->subtree(subroot) << endl ;
  
    return 0;
}