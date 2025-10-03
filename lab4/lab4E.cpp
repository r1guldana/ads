#include <iostream>
using namespace std ;
class Node{
    public:
    int data ;
    Node * left, * right ;
    Node(int data){
        this ->data = data ;
        left = NULL;
        right=NULL;
    }
};

class BST {
    
    public:
    Node* root;
    Node *nodes[10001];
    int lvl_count[10001];

    BST() {
        root = NULL;
        for(int i = 0; i < 1001; i++) {
            nodes[i] = NULL;
            lvl_count[i] = 0;
        }
    }

void dfs(Node*node, int lvl){
    
    if(node==NULL) return ;

    lvl_count[lvl]++ ;

    dfs(node->left, lvl + 1);
    dfs(node->right,lvl + 1);
}
int max_width(){
    for(int i = 0 ; i<10001; i++){
        lvl_count[i] = 0 ;
    }

    dfs(root, 0);

    int max_w = 0;

    for(int i = 0; i<10001; i++){
        if(lvl_count[i] > max_w){
            max_w = lvl_count[i];
        }
    }
    return max_w ;
}
};

int main(){
    BST bst ;
    int n ;
    cin >> n;
    
    bst.nodes[ 1] = new Node(1);
    bst.root = bst.nodes[1];

    for (int i = 0 ; i<n-1; i++){
        int x ,y ,z ;
        cin >> x >> y>>z ;

        if(bst.nodes[x]==NULL){
            bst.nodes[x] = new Node(x);
        }
        if(bst.nodes[y]==NULL){
            bst.nodes[y] = new Node(y);
        }
        if (z == 0){
            bst.nodes[x]->left = bst.nodes[y];
        }
        else{
            bst.nodes[x]->right = bst.nodes[y];
            }
            }

    int max_w = bst.max_width();
    
     cout << max_w << endl;

     for(int i = 1; i <= n; i++) {
        if(bst.nodes[i] != NULL) {
            delete bst.nodes[i];
        }
    }
    return 0 ;
}