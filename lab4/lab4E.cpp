#include <iostream>
#include <queue>
#include <algorithm>
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

    BST() {
        root = NULL;
    }

Node* find_node(Node*cur, int val){
    if (cur == NULL) return NULL;
    if (cur->data == val) return cur;
    Node*left_side = find_node(cur->left, val);
    if(left_side!= NULL) return left_side;
    return find_node(cur->right, val) ;


}

    void addNode(int x, int y, int z){
        Node* parent_node = find_node(root, x) ;
       if(parent_node!= NULL){

        if(z == 0){
            parent_node->left = new Node(y);
        }
        else{parent_node->right = new Node(y);
        }
    }
    }


     int find_width(Node*node ){
        if(node == NULL) return 0;
    queue<Node*> que ;
    int max_width = 0 ;
    que.push(node);
    while(!que.empty()){
        int count =  (int)que.size(); 
        max_width = max(max_width, count);
        for(int i = 0 ; i<count; i++) {
            Node * cur = que.front();
            que.pop();
            if (cur->left)  que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
    }
         return max_width ;

    }

};

int main(){
    BST bst ;
    int n ;
    cin >> n;

     bst.root = new Node(1);
    
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        bst.addNode(x, y, z);
    }
    cout << bst.find_width(bst.root) << endl ;
    

    return 0 ;
}