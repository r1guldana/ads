#include <iostream>
#include <vector>
#include <string>
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
    bool path(Node*root, string path){
        Node* cur = root ;
        for(int i = 0 ; i<path.size(); i++){
            if(cur == NULL){
                return false;
            }
            if(path[i] == 'L'){
                cur = cur ->left ;
            }
            else{
                cur = cur ->right ;
            }
        }
        return cur != NULL ;
    }
};

int main() {
    BST *bst = new BST();
    int N, M ;
    cin >> N >> M;
    vector<string>pathSTR(M) ;
    for(int i = 0 ; i<N;i++){
        int j;
        cin >> j;
         bst->root = bst->insert(bst->root, j);
    }
    for(int i = 0 ; i< M; i++){
        cin >> pathSTR[i] ;
    }
    BST B ;
    for(int i = 0 ; i< M; i++){
        
    if(bst->path(bst->root, pathSTR[i])){  //?
        cout<< "YES" << endl;
    }
    
    else{
        cout << "NO" << endl;
    }

    }
    return 0;
}