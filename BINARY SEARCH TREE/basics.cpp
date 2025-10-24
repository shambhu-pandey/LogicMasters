#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left ;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//INORDER
void inOrder(Node* root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

//PREORDER
void preOrder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//POSTORDER
void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

Node* minValue(Node* root){
       if(root==NULL) return NULL;
    Node* temp = root;

    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root==NULL) return NULL;
    Node* temp = root;

    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}
// Deletion function for a Binary Search Tree (BST)
Node* deleteFromBST(Node* root , int val){
    // Base Case: Agar root NULL hai, toh wapis NULL return karo (If root is NULL, return NULL)
    if(root == NULL){
        return NULL;
    }

    // Node found: If the current node is the one to be deleted (root->data == val)
    if(root->data == val){
        cout<< "Successfully deleted node with value: " << val << endl;
        
        // Case 1: 0 Child Node deletion (Leaf Node)
        // Node is a leaf: simply delete it and return NULL to its parent
        if(root->left ==  NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // Case 2: 1 Child Node deletion (Left child exists)
        // Left child present, Right child is NULL
        else if(root->left != NULL && root->right == NULL){ 
            // Store the left child to promote it
            Node* temp = root->left;
            delete root;
            // Return the left child to replace the deleted node
            return temp;
        } 

        // Case 3: 1 Child Node deletion (Right child exists)
        // Right child present, Left child is NULL
        else if(root->left == NULL && root->right != NULL){ 
            // Store the right child to promote it
            Node* temp = root->right;
            delete root;
            // Return the right child to replace the deleted node
            return temp;
        }

        // Case 4: 2 Child Nodes deletion
        else if (root->left != NULL && root->right != NULL){
            // Strategy: Replace the node's data with the minimum value from its RIGHT subtree.
            // (Alternate strategy: Use max value from the LEFT subtree)

            // Step 1: Find the minimum value in the right subtree (In-order Successor)
            // min value nikaal liye right se 
            int mini = minValue(root->right)->data;
            
            // Step 2: Copy this minimum value to the current node (replacing the value we want to delete)
            // root ka jo data hai usme copy kar liye 
            root->data = mini;
            
            // Step 3: Now, delete the actual minimum value node from the right subtree (it has 0 or 1 child)
            // ab delete kar denge min value ko right wala 
            root->right = deleteFromBST(root->right , mini);
            
            // Return the modified root
            return root;
        }
    }
    
    // Traversal (If node is NOT found at current root)
    
    // If the value is smaller, search in the left subtree
    else if(val < root->data){ 
        // root->left ko update karo with the result of deletion in the left subtree
        root->left = deleteFromBST(root->left , val);
    }
    
    // If the value is larger, search in the right subtree
    else{ // val > root->data
        // root->right ko update karo with the result of deletion in the right subtree
        root->right = deleteFromBST(root->right, val);
    }
    
    // Return the current root pointer for recursive calls to reconnect the tree
    return root;
}

// LEVEL ORDER TRAVERSAL
// thoda tree format me dikhane ke liye 
void levelOrderTraversal(Node* root){
     queue<Node*> q;
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
        Node* temp = q.front();
        q.pop();
         
        if(temp ==NULL){ // purana level complete traverse ho chuka hai 
            cout<<endl;
            if(!q.empty()){//queue still has some child node
             q.push(NULL);//separator
            }
        }
        else{
        cout<<temp->data <<" ";
        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

     }
}

//insert 
Node* insertIntoBST(Node* &root, int data){
    //base case
    // starting me jab ek bhi node create nhi hai toh 
    //create kar de rhe hai jo bhai value aaaya hai usko node me daal ke 
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data>root->data){
        //right part me insert karna hai
        root->right = insertIntoBST(root->right , data);
    }
    else{
        //left part me insert 
        root->left = insertIntoBST(root->left , data);
    }

    return root;
} 
//take input
void takeInput(Node* &root){
    int data;
    cin>>data;

    // taab tak le jab tak data ke value me -1 na enter kar de  
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}

int main(){
    Node* root = NULL;
    cout<<"enter data to create BST"<<endl;
    takeInput(root);
 
    cout<<"printing the BST using LEVEL ORDER TRAVERSAL :"<<endl;
    levelOrderTraversal(root);

    cout<<"printing inorder :"<<endl;
    inOrder(root);

    cout<<endl<<"printing preorder :"<<endl;
    preOrder(root);
    
    cout<<endl<<"printing postorder :"<<endl;
    postOrder(root);

  
    cout << "\nMinimum value in BST: " << minValue(root)->data << endl;
    cout << "Maximum value in BST: " << maxValue(root)->data << endl;
    
   // Example: Deleting a node
int val;
cout<<"\nEnter value to delete from BST: ";
cin >> val;
root = deleteFromBST(root, val);
cout<<"\nBST after deletion (Level Order):"<<endl;
levelOrderTraversal(root);

    return 0;
}