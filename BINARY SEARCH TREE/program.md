# 🌳 Binary Search Tree (BST) Implementation in C++

Welcome to the **BST Problem Set**! 💡
This collection features **common problems solved using Binary Search Tree in C++**.
Each problem includes **problem statement, examples, your solution code, complexity analysis, and practice links**.

## 📑 Table of Contents
1. [📘 Create a Binary Search Tree and Perform Tree Traversals](#📘-create-a-binary-search-tree-and-perform-tree-traversals)
2. [🔍 Search a Node in BST](#🔍-search-a-node-in-bst)
3. [🌳 Binary Search Tree Deletion Operations in C++](#🌳-binary-search-tree-deletion-operations-in-c)
4. [🌳 Two Sum in BST - LeetCode Problem](#🌳-two-sum-in-bst---leetcode-problem)

---

### 📘 Create a Binary Search Tree and Perform Tree Traversals {#bst-traversals}

**File:** `BST_Traversal.cpp`
**Language:** C++
**Link:** [👉 Click here for source code](#) <!-- Update with actual link -->

---

### 🧩 Problem Statement

Write a C++ program to:

1. Create a **Binary Search Tree (BST)** by taking user input.
2. Perform and print:

   * **Inorder Traversal**
   * **Preorder Traversal**
   * **Postorder Traversal**
   * **Level Order Traversal**
   * **minimum node (value) in BST**
   * **mAXIMUM node (value) in BST**
---

### 🧠 Concept

A **Binary Search Tree (BST)** is a binary tree where:

* The left subtree contains nodes with values **less than** the parent node.
* The right subtree contains nodes with values **greater than** the parent node.

This property allows for efficient searching, insertion, and traversal.

---

### 💻 Code Implementation

```cpp
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// INORDER Traversal (Left → Root → Right)
void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// PREORDER Traversal (Root → Left → Right)
void preOrder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// POSTORDER Traversal (Left → Right → Root)
void postOrder(Node* root){
    if(root==NULL) return;
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

// LEVEL ORDER Traversal (Breadth-first)
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
         
        if(temp == NULL){ // End of current level
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data <<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

// Insert data into BST
Node* insertIntoBST(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data > root->data)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);

    return root;
} 

// Take user input until -1 is entered
void takeInput(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        insertIntoBST(root, data);
        cin >> data;
    }
}

// Main function
int main(){
    Node* root = NULL;
    cout << "Enter data to create BST (-1 to stop):" << endl;
    takeInput(root);
 
    cout << "\nPrinting the BST using LEVEL ORDER TRAVERSAL:" << endl;
    levelOrderTraversal(root);

    cout << "\nPrinting INORDER traversal:" << endl;
    inOrder(root);

    cout << "\n\nPrinting PREORDER traversal:" << endl;
    preOrder(root);
    
    cout << "\n\nPrinting POSTORDER traversal:" << endl;
    postOrder(root);

    
    return 0;
}
```

---

### 🔍 Search a Node in BST {#search-node-bst}

**Practice this question on:**
[GeeksforGeeks](https://www.geeksforgeeks.org/binary-search-tree-data-structure/) | [LeetCode](https://leetcode.com/) | [Coding Ninjas](https://www.codingninjas.com/)

---

**Difficulty:** Easy
**Accuracy:** 68.46%
**Submissions:** 108K+
**Points:** 2
**Average Time:** 15m

Given the root of a Binary Search Tree and a node value `key`, find if the node with value `key` is present in the BST or not.

### Examples:

![alt text](image.png)
![alt text](image-1.png)

---

## 🔹 Approach 1: Recursion

```cpp
/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {

     if(root == NULL){
         return false;
     }
     if(root->data== key){
         return true;
     }
     
     if(root->data>key){
         //left part
        return  search(root->left , key);
     }
     else{
        return search(root->right , key);
     }
        
    }
};
```

**Time Complexity:** O(h) where h is the height of BST (O(log n) for balanced, O(n) for skewed)
**Space Complexity:** O(h) due to recursion stack

---

## 🔹 Approach 2: Iterative

```cpp
/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
      // Node bna liye 
        BinaryTreeNode<int>* temp= root;

        while(temp!=NULL){
            if(temp->data == x){
                return true;
            }
            else if(temp->data > x){
                temp=temp->left;
            }
            else{
                temp=  temp->right;
            }
        }
        return false;
}
```

**Time Complexity:** O(h) where h is the height of BST
**Space Complexity:** O(1) (iterative)

---

**💡 Notes:**

* Recursion is more intuitive but uses extra stack space.
* Iterative approach is memory efficient.
* For a balanced BST, both methods are efficient (O(log n)), but for skewed BST it can degrade to O(n).




## 🌳 Binary Search Tree (BST) - Deletion Operations in C++

This file demonstrates **deletion operations in a BST** along with **all traversals, min/max, and insertion**.

---

### 🌳 Binary Search Tree Deletion Operations in C++ {#bst-deletion}

**File:** `BST_Deletion.cpp`
**Language:** C++
**Practice:** [GeeksforGeeks BST](https://www.geeksforgeeks.org/binary-search-tree-data-structure/) | [LeetCode BST Problems](https://leetcode.com/tag/binary-search-tree/) | [CodingNinjas](https://www.codingninjas.com/)

---

### 🧩 Problem Statement

Given a BST, implement deletion of a node with a given value. Handle all cases:

1. Node with **0 children** (leaf node)
2. Node with **1 child** (left or right)
3. Node with **2 children** (replace with in-order successor or predecessor)

Also, implement:

* Insertion
* Traversals: Inorder, Preorder, Postorder, Level Order
* Finding Min and Max values


---

### 💻 Code Implementation

```cpp
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Find Minimum Value in BST
Node* minValue(Node* root){
     if(root==NULL) return NULL; 
     Node* temp=root; 
     while(temp->left!=NULL) {
     temp=temp->left;
      }
       return temp; 
 }

// Find Maximum Value in BST
Node* maxValue(Node* root){
     if(root==NULL) return NULL; 
     Node* temp=root; 
     while(temp->right!=NULL){
         temp=temp->right;
      }
 return temp; }
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

// Insert Node
Node* insertIntoBST(Node* &root, int data){
    if(root==NULL){ root=new Node(data); return root; }
    if(data>root->data) root->right=insertIntoBST(root->right,data);
    else root->left=insertIntoBST(root->left,data);
    return root;
}

// Take Input
void takeInput(Node* &root){
    int data; cin>>data;
    while(data!=-1){ insertIntoBST(root,data); cin>>data; }
}

int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST (-1 to stop):"<<endl;
    takeInput(root);

    cout<<"\nBST Level Order Traversal:"<<endl;
    levelOrderTraversal(root);


    cout<<"\nMinimum value in BST: "<<minValue(root)->data<<endl;
    cout<<"Maximum value in BST: "<<maxValue(root)->data<<endl;

    int val;
    cout<<"\nEnter value to delete from BST: "; cin>>val;
    root = deleteFromBST(root,val);

    cout<<"\nBST after deletion (Level Order):"<<endl;
    levelOrderTraversal(root);

    return 0;
}
```

---

### 📊 Complexity Analysis

* **Time Complexity:** O(h), where h is the height of BST

  * O(log n) for balanced BST
  * O(n) for skewed BST
* **Space Complexity:** O(h) for recursion stack during deletion

---

**💡 Notes:**

* Handles all cases of deletion.
* Maintains BST properties.
* Supports traversals and min/max queries.



### 🌳 Two Sum in BST - LeetCode Problem {#two-sum-bst}

This Markdown file demonstrates a **Two Sum problem in a Binary Search Tree (BST)** using **inorder traversal and two-pointer approach**.

---

## 📘 Problem: Two Sum in BST

**Difficulty:** Medium
**LeetCode Link:** [LeetCode 653 - Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
**Language:** C++

### 🧩 Problem Statement

Given the `root` of a **Binary Search Tree** and an integer `k`, return `true` if there exist **two elements** in the BST such that their sum equals `k`, otherwise return `false`.

**Example:**

```
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
```

---

### 💻 Solution (C++)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // 2 node ka pair batana hai  , ki target value ke equal hai ki nhi agar sum karenge 2 node ko toh
 // toh hm isko inorder find kar ke kar sakte hai because , inorder sorted order me data return karta hai 
 // uske baad 2 pinter wala approach lga lenge inorder ke first element 'i' and last element ko 'j' maan lenge  aur sum karayenge aur agar sum chota hoga target se toh i++ kra denge ya agar sum bda hoga toh j--
 // aise hi hme ek point par mil jaayega toh true return  ya nhi milege toh false 
class Solution {
public:
    // Inorder traversal to get sorted elements of BST
    TreeNode* inorderTraversal(TreeNode* root , vector<int>& inorder){
        if(root == NULL) return NULL;
        inorderTraversal(root->left , inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right , inorder);
        return root;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root , inorder);

        int i = 0;                  // Start pointer
        int j = inorder.size() - 1; // End pointer

        while(i < j){
            int sum = inorder[i] + inorder[j];
            if(sum == k) return true;   // Found a pair
            else if(sum > k) j--;       // Sum too big, move end pointer
            else i++;                    // Sum too small, move start pointer
        }
        return false; // No pair found
    }
};
```

---

### 🔹 Approach Explanation

1. **Inorder Traversal:**
   Traverse BST inorder to get elements in **sorted order**.

2. **Two-Pointer Technique:**

   * Start with two pointers, `i` at the beginning and `j` at the end of the sorted array.
   * Calculate the sum:

     * If sum == target, return `true`
     * If sum < target, move `i++`
     * If sum > target, move `j--`
   * Continue until `i >= j`.

3. **Return false** if no such pair exists.

---

### 📊 Complexity Analysis

* **Time Complexity:** O(n)

  * O(n) for inorder traversal
  * O(n) for two-pointer search

* **Space Complexity:** O(n)

  * Due to vector storing inorder traversal

---

**💡 Notes:**

* Inorder traversal is key because it gives sorted elements of BST.
* Two-pointer approach works efficiently on the sorted array.
