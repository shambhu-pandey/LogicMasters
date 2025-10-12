#include<bits/stdc++.h>
#include<queue>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        
    }
};

// tree creation
node* buildTree(node* root){
    cout<<"enter the data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"enter data for inserting in left"<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data for inserting in right:"<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// thoda tree format me dikhane ke liye 
void levelOrderTraversal(node* root){
     queue<node*> q;
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
        node* temp = q.front();
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

void inOrder(node* root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

void preOrder(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    node* root = NULL;

    root = buildTree(root);
    
    cout<<"printing the level order traversal output "<<endl;
    levelOrderTraversal(root);

    cout<<"inorder traversal : ";
    inOrder(root);

       cout<<"preorder traversal : ";
    preOrder(root);

       cout<<"postorder traversal : ";
    postOrder(root);
    return 0;
}