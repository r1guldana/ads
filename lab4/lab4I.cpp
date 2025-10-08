    #include <iostream>
    using namespace std ;


    struct Node {
        int data;
        int count ;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->count = 1;
            left = NULL;
            right = NULL;
        } 
    };

    Node* getMin(Node* root) {
    if(root == NULL) return NULL ;
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    Node* add(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }  
        else if (root->data == data) {
        root->count++;
    }
        else if (root->data > data) {
           /* if (root->left == NULL) {
                root->left = new Node(data);
            } else {*/
                root->left = add(root->left, data);
            //}
        } else if (root->data < data) {
           /* if (root->right == NULL) {
                root->right = new Node(data);
            } else {*/
                root->right = add(root->right, data);
            // }
        }
        return root;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == NULL) {
            return NULL;
        } else if (root->data > data) {
            root->left = deleteNode(root->left, data);
            return root;
        } else if (root->data < data) {
            root->right = deleteNode(root->right, data);
            return root;
        } else {
            if(root->count > 1)
                {root->count--;
                return root ;}
            else{
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else {
                Node* temp = getMin(root->right);
                 if (temp == NULL) {
                delete root;
                return NULL;
            } 
                root->data = temp->data;
                root->count = temp->count ;
                temp->count = 1;
                root->right = deleteNode(root->right, temp->data);
                 }
            }
            return root;
           
        }
    }

    Node* find(Node* root, int x) {
        if (root == NULL) {
            return NULL;
        } 
        else if (root->data == x) {
            return root;
        } 
        else if (root->data < x) {
            return find(root->right, x);
        } 
        else {
            return find(root->left, x);
        }


        
    }

    int main(){
        Node* root = NULL; 
        int n ;
        cin >> n ;
        for(int i = 0 ; i<n ; i++){
            string query;
            int num ;
            cin >> query >> num ;

            if (query=="insert"){
                root = add(root, num);
            }
            else if (query == "cnt"){
                Node*node =  find(root, num);

                if(node!= NULL){
                    cout << node ->count << endl ;
                }
                else{cout << 0 << endl; 
                }
                
            }
            else if (query == "delete"){
                root = deleteNode(root, num);
            }


        }
 
        
        return 0;
    }
