# 🌳 Binary Search Tree (BST) Implementation in C++

Welcome to the **BST Problem Set**! 💡
This collection features **common problems solved using Binary Search Tree in C++**.
Each problem includes **problem statement, examples, your solution code, complexity analysis, and practice links**.

---
## 📑 Table of Contents

1. [📘 Create a Binary Search Tree and Perform Tree Traversals](#create-a-binary-search-tree-and-perform-tree-traversals)
2. [🔍 Search a Node in BST](#search-a-node-in-bst)
3. [🌳 Binary Search Tree Deletion Operations in C++](#binary-search-tree-deletion-operations-in-c)
4. [🌳 Two Sum in BST - LeetCode Problem](#two-sum-in-bst---leetcode-problem)
5. [🌿 Flatten BST To A Sorted List](#flatten-bst-to-a-sorted-list)
6. [🌲 Normal BST To Balanced BST](#normal-bst-to-balanced-bst)

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

### 🌐 Practice Websites

* [LeetCode - Two Sum IV: Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
* [Coding Ninjas - Pair Sum in BST](https://www.codingninjas.com/codestudio/problems/pair-sum-in-bst_920493)


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


---


# 🌳 Flatten BST To A Sorted List

### 🌐 Practice Websites

* [Coding Ninjas - Flatten BST to Sorted List](https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1112606)
* [GeeksforGeeks - Flatten BST to Linked List](https://practice.geeksforgeeks.org/problems/flatten-bst-to-sorted-list/1)
* [LeetCode - Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/)


## 🧩 Problem Statement
You have been given a **Binary Search Tree (BST)**. Your task is to **flatten the given BST to a sorted list**. More formally, you have to make a **right-skewed BST** from the given BST, i.e., the **left child of all the nodes must be NULL**, and the value at the **right child must be greater than the current node**.  

A **binary search tree (BST)**, also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each store a value greater than all the values in the node's left subtree and less than those in its right subtree.  

### ⚡ Follow Up
Can you solve this in **O(N) time** and **O(H) space complexity**?

---

## 🖼️ Example

![BST Image](image-4.png)  
![BST Image](image-2.png)  
![Flattened BST Image](image-3.png)

---

## 💡 Approach / Solution

1. **Inorder Traversal:**  
   Since **inorder traversal of a BST gives sorted values**, we first collect the BST nodes in sorted order.  

2. **Create New Right-Skewed Tree:**  
   Using the inorder values, create a new tree where:
   - `left` child of all nodes = `NULL`
   - `right` child points to the next node in sorted order  

3. **Return the New Root:**  
   The first node of inorder becomes the root of the flattened tree.

---

## 💻 C++ Code Implementation
```cpp
/*************************************************************/
// question me bol rha hai ki , -> isko flat kar ke linked list bna do jo ki sorted hona chahiye  means sorted linkedlist
// soln : hme pta hai bst ki property ki inorder sorted me hota hai , toh kyu na iorder nikaalle aur node bna de inorder ka value ko . 
// aur left pointer null (jo ki question me bola hai ) , aur right pointer ko aage wala element par 
// aur last step , last wala element ka left bhi null kar do aur right bhi 
// aur last me hme flatteerd bn jaayega 
void inorder(TreeNode<int>*root ,vector<int>& inorderVal){
    if(root==NULL){
        return;
    }
    inorder(root->left , inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right ,inorderVal);

}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorderVal;
    inorder(root , inorderVal);
    
    int n = inorderVal.size();
    // create new node with first value 
    TreeNode<int>* newroot = new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr = newroot;   // point to the first node 
    
    // Create remaining nodes and link them as right child
    for(int i =1; i<n;i++){
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->left = NULL;   // left child is always NULL
        curr->right = temp;   // link new node as right child
        curr=temp;            // move current pointer forward

    }

       // Make sure last node has NULL children
    curr->left =NULL;
    curr->right = NULL;

    return newroot;  // return root of flattened tree
}
```

---



## 🌲 Normal BST To Balanced BST

### 🧩 Problem Statement

You have been given a **Binary Search Tree (BST)** of integers with **N nodes**. Your task is to convert it into a **Balanced BST** with the **minimum height** possible.

A **Binary Search Tree (BST)** is a binary tree that follows these properties:

* The **left subtree** of a node contains only nodes with data **less than** the node’s data.
* The **right subtree** of a node contains only nodes with data **greater than** the node’s data.
* Both the left and right subtrees must also be **binary search trees**.

A **Balanced BST** is defined as a BST where the **height difference** between the left and right subtrees of every node is **at most 1**.

---

---

### 🌐 Practice Links

* 🔗 [LeetCode - Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
* 🔗 [Coding Ninjas - Normal BST To Balanced BST](https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472)
* 🔗 [GeeksForGeeks - Convert Normal BST to Balanced BST](https://www.geeksforgeeks.org/convert-normal-bst-to-balanced-bst/)

---

### 🧠 Intuition

The **inorder traversal** of a BST always gives elements in **sorted order**. So, if we perform an inorder traversal and store the elements, then construct a new BST from this sorted array, the resulting BST will automatically be **balanced** if we always pick the **middle element** as the root.

---

### 🖼️ Example

**Original BST → Inorder Traversal → Balanced BST**

![Normal BST](image-7.png)

![Inorder Traversal](image-5.png)

![Balanced BST](image-6.png)

---

### 💡 Approach

1. **Perform Inorder Traversal**
   Store all elements of BST in a sorted array (`inorderVal`).

2. **Construct Balanced BST**
   Use the sorted array to construct a new BST:

   * Pick the **middle element** as the root.
   * Recursively build **left** and **right** subtrees from the left and right halves of the array.

3. **Return the new root.**

---

### 💻 C++ Code Implementation

```cpp
/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

/**************************************************************/
// normal bst to balanced bst me karna hai, -> hme pta hai ek chiz ki normal bst ki inorder ya balanced bst ki inorder same hogi
// sorted order me inorder ko  fark nhi fark nhi padta ki normal bst hai ya balanced bst 
// toh kyu na inorder nikaal le given tree se aur uske baad inorder se bst bna le oo balanced bst hi bna kar de dega 


void inorder(TreeNode<int>* root , vector<int> &inorderVal){
    if(root==NULL){
        return;
    }
    inorder(root->left , inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right , inorderVal);
}
TreeNode<int>* inorderToBst(int start , int end, vector<int>& inorderVal){
   if(start>end){
       return NULL;
   }
   int mid= (start+end)/2;

   TreeNode<int>* root = new TreeNode<int>(inorderVal[mid]);
   root->left = inorderToBst(start, mid-1,inorderVal);
   root->right=  inorderToBst(mid+1 , end, inorderVal);

   return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderVal;
    inorder(root ,inorderVal);

    return inorderToBst(0, inorderVal.size()-1 , inorderVal);

}
```


---

### ⏱️ Time Complexity

* **O(N)** — for inorder traversal to collect elements.
* **O(N)** — for constructing a balanced BST from sorted array.
* **Total:** `O(N)`

### 🧮 Space Complexity

* **O(N)** — to store inorder traversal.
* **O(H)** — recursion stack (height of tree while constructing BST).


### 🏁 Summary

✅ Inorder traversal gives sorted elements.
✅ Constructing BST using middle element ensures balance.
✅ Efficient O(N) solution with O(H) extra space.
