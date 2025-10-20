# 🌳 Introduction to Trees  

In the world of **Data Structures and Algorithms**, understanding **binary trees** lays the groundwork for hierarchical organisation and efficient data manipulation.  

Up until now, we have studied **arrays, linked lists, stacks, and queues** — the fundamental **linear data structures**.  
Binary Trees, on the other hand, allow **hierarchical organisation**, resembling a real tree with branches expanding in a **non-linear fashion**.  

---

## 🌲 Binary Tree  

A **Binary Tree** is a hierarchical data structure where each node has **at most two children**:  
- **Left Child**  
- **Right Child**  

- its a non linear data structures.
### 📌 Nodes  
- Each node contains **data** and **pointers** to its children.  
- This enables traversal in a hierarchical manner.  

---
## 🌳 Tree Data Structure — Key Terminologies with Examples

## 🌟 Key Terminologies

### 🌐 Root Node

The **topmost node** of the tree, serving as the **entry point**.
**Example:** In a tree, if A is at the top and connects to B and C, then **A** is the root.

### 🧩 Parent Node

A node that has **one or more child nodes** connected to it.
**Example:** In the tree A → B, A is the **parent** of B.

### 👶 Children Nodes

Nodes **directly connected** to a parent node.

* A parent can have **0, 1, or 2 children**.
  **Example:** If A has two branches going to B and C, then **B and C** are children of A.

### 🌿 Descendants

All nodes that **originate from a given node** (its **children, grandchildren, and so on**).
**Example:** If A → B → D, then **B and D** are descendants of **A**, and **D** is a descendant of **B**.

### 🧑‍🦝‍🧑 Ancestors

All nodes that lie on the **path from a node to the root**.
**Example:** If A → B → D, then **A and B** are ancestors of **D**.

### 🔗 Sibling Nodes

Nodes that **share the same parent**.
**Example:** If A → B and A → C, then **B and C** are siblings.

### 🍃 Leaf Nodes

Nodes with **no children**, lying at the **ends of branches**.
**Example:** In A → B → D, if D has no further nodes, then **D** is a leaf.

### 📏 Depth

The **number of edges** from the **root to a given node**.
**Example:** If A is root and A → B → D, then **depth of D = 2**.

### 🧮 Height

The **longest path** from a node down to a **leaf node**.

* The **height of the tree** is the height of its root.
  **Example:** In A → B → D, height of **A = 2**.

### 🧽 Subtree

A **portion of a tree** that itself forms a **complete tree structure**, starting from any node.
**Example:** If A is root, and A → B → D, then the part starting from **B** (including D) is a **subtree**.

### 🔁 Degree of a Node

The **number of children** a node has.
**Example:** If node A has two children (B, C), degree of **A = 2**.

### 🔄 Binary Tree

A tree where **each node has at most two children** — a **left child** and a **right child**.
**Example:**

```
     A
    / \
   B   C
```

Here A has two children, so it’s a binary tree.

### 🧠 Binary Search Tree (BST)

A special binary tree where

* **Left child < Parent < Right child**
* Enables **efficient searching and sorting**.
  **Example:**

```
     8
    / \
   3   10
  / \    \
 1   6    14
```

Here all left nodes are smaller and right nodes are greater.

### 🔍 Traversal

The process of **visiting all nodes** in a specific order.

* Common types:

  * **Inorder (Left → Root → Right)**
  * **Preorder (Root → Left → Right)**
  * **Postorder (Left → Right → Root)**
  * **Level Order (Breadth-first)**

**Example (Inorder Traversal):** For tree

```
   A
  / \
 B   C
```

Result = **B A C**.

### ⚖️ Balanced Tree

A tree where the **heights of left and right subtrees** of every node **differ by at most one**.
**Example:**

```
     10
    /  \
   5    15
```

Both subtrees have equal height → **Balanced**.

### 💿 Node Value / Data Field

The **information stored** in each node.
**Example:** In a node structure, if a node stores `7`, then 7 is its **data value**.

### 🧱 Edge

The **connection (link)** between two nodes — from **parent to child**.
**Example:** In A → B, the link between A and B is an **edge**.

---

## 🧹 Simple Tree Example Diagram

```
        A (Root)
       / \
     B     C
    / \   /
   D   E  F

Root Node: A  
Children of A: B, C  
Leaf Nodes: D, E, F  
Siblings: B and C  
Ancestors of E: B, A  
Descendants of B: D, E  
```

---

## 🌳 Types of Binary Trees  

### ✅ Full Binary Tree  
- Also called **Strict Binary Tree**.  
- Every node has **0 or 2 children**.  
- Promotes balance and efficient traversal.  

### ✅ Complete Binary Tree  
- All levels are **completely filled**, except possibly the last.  
- The last level is filled **from left to right**.  
- Commonly used in **heaps**.  

### ✅ Perfect Binary Tree  
- All **internal nodes** have exactly 2 children.  
- All **leaf nodes** are at the **same level**.  
- Maximises the number of nodes for a given height.  

### ✅ Balanced Binary Tree  
- Heights of left and right subtrees of any node differ by **at most 1**.  
- Height ≈ **log₂N** (where N = number of nodes).  
- Prevents skewed tree growth.  

### ✅ Degenerate Tree  
- Nodes are arranged in a **single path** (like a linked list).  
- Height = **number of nodes**.  
- Causes **inefficient searches**.  

---

## 📝 In Summary  

- **Binary Trees** introduce hierarchical structures beyond linear DS.  
- **Full Binary Trees** → Each node has 0 or 2 children.  
- **Complete Binary Trees** → All levels filled, last filled left to right.  
- **Perfect Binary Trees** → All levels fully filled, leaves at same level.  
- **Balanced Binary Trees** → Subtree heights differ by at most 1.  
- **Degenerate Trees** → Linear structure, worst-case performance.  

Binary Trees form the **foundation for advanced trees** like **BST, AVL, Heaps, and B-Trees**, which are crucial in efficient searching, sorting, and storage.  



# QUESTION 1. 🌳 Binary Tree Creation and Traversals in C++

This program demonstrates:  
- **Binary Tree creation (recursive input)**  
- **Level Order Traversal**  
- **Inorder Traversal**  
- **Preorder Traversal**  
- **Postorder Traversal**  

---

## 📌 Code  

```cpp
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

// Tree creation
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

// 🌳 Function to perform Level Order Traversal (Breadth-First Search)
void levelOrderTraversal(node* root) {

    // Create a queue to store nodes for BFS traversal
    queue<node*> q;

    // Push the root node into the queue
    q.push(root);

    // Push a NULL marker to indicate the end of the first level
    q.push(NULL);

    // Continue traversal until the queue becomes empty
    while(!q.empty()) {

        // Take out the front node from the queue
        node* temp = q.front();
        q.pop();
         
        // 👉 If we encounter NULL, that means one level is completed
        if(temp == NULL) {
            cout << endl; // Move to next line for new level

            // If there are still nodes left in the queue,
            // push another NULL to mark the end of the next level
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            // Print the data of the current node
            cout << temp->data << " ";

            // Push the left child into the queue if it exists
            if(temp->left) {
                q.push(temp->left);
            }

            // Push the right child into the queue if it exists
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void buildFromLevelOrder(node* root){
    queue<node*> q;
    cout<<"enter data for root :"<<endl;
    int data;
    cin>>data;
    root =new node(data);
    q.push(root);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        cout<<enter left data for :<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"enter right data for :"<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

// Inorder Traversal (LNR)
void inOrder(node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// Preorder Traversal (NLR)
void preOrder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// Postorder Traversal (LRN)
void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root = NULL;

    // root = buildTree(root);
    
    // cout<<"printing the level order traversal output "<<endl;
    // levelOrderTraversal(root);

    // cout<<"inorder traversal : ";
    // inOrder(root);

    // cout<<"preorder traversal : ";
    // preOrder(root);

    // cout<<"postorder traversal : ";
    // postOrder(root);

    buildFromLevelOrder(root);

    return 0;
}
```


# question 2 🌳 Inorder Traversal of a Binary Tree

**Difficulty:** 🟢 Easy
**Points:** 78 / 100

---

## 📌 Problem Statement

Given the **root of a binary tree**, return the **Inorder Traversal** of the binary tree.

* **Inorder Traversal (LNR):**

  1. Traverse the **Left Subtree**
  2. Visit the **Node**
  3. Traverse the **Right Subtree**

---

## 🖼️ Examples

### Example 1

**Input:**

```text
root = [1, 4, null, 4, 2]
```

**Output:**

```text
[4, 4, 2, 1]
```

---

### Example 2

**Input:**

```text
root = [1, null, 2, 3]
```

**Output:**

```text
[1, 3, 2]
```

---

## 💻 C++ Solution

### 🔹 Recursive Approach

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

class Solution {
private:
    void recursiveInorder(TreeNode* root, vector<int> &arr) {
        if(root == nullptr) return;

        // Traverse left subtree
        recursiveInorder(root->left, arr);

        // Visit current node
        arr.push_back(root->data);

        // Traverse right subtree
        recursiveInorder(root->right, arr);
    }

public:
    vector<int> inorder(TreeNode* root) {
        vector<int> arr;      
        recursiveInorder(root, arr);
        return arr;           
    }
};
```

---


## 📝 Explanation

* **Recursive:**

  1. Traverse **left subtree** recursively.
  2. Visit **current node**.
  3. Traverse **right subtree** recursively.


## 📊 Complexity Analysis

| Approach  | Time Complexity | Space Complexity |
| --------- | --------------- | ---------------- |
| Recursive | O(N)            | O(N)             |
| Iterative | O(N)            | O(N)             |

---

## ✅ Key Points

* Inorder traversal returns values in **sorted order** if the tree is a **Binary Search Tree (BST)**.
* Works for both **balanced** and **unbalanced** trees.
* Two main approaches: **Recursive (simple)** and **Iterative (stack-based)**.




# question 3. 🌲 Preorder Traversal of a Binary Tree

**Difficulty:** 🟢 Easy
**Points:** 66 / 100

---

## 📌 Problem Statement

Given the **root of a binary tree**, return the **Preorder Traversal** of the binary tree.

* **Preorder Traversal (NLR):**

  1. Visit the **Node**
  2. Traverse the **Left Subtree**
  3. Traverse the **Right Subtree**

---

## 🖼️ Examples

### Example 1

**Input:**

```text
root = [1, 4, null, 4, 2]
```

**Output:**

```text
[1, 4, 4, 2]
```

### Example 2

**Input:**

```text
root = [1]
```

**Output:**

```text
[1]
```

---

## 💻 C++ Solution

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

class Solution {
private:
    void recursivePreOrder(TreeNode* root, vector<int> &arr) {
        if(root == nullptr) return;

        // Visit current node
        arr.push_back(root->data);

        // Traverse left subtree
        recursivePreOrder(root->left, arr);

        // Traverse right subtree
        recursivePreOrder(root->right, arr);
    }

public:
    vector<int> preorder(TreeNode* root) {
        vector<int> arr;
        recursivePreOrder(root, arr);
        return arr;
    }
};
```

---

## 📝 Explanation

1. Visit the **current node** and store its value.
2. Traverse the **left subtree** recursively.
3. Traverse the **right subtree** recursively.
4. The result is stored in a vector and returned.

---

## 📊 Complexity Analysis

| Approach  | Time Complexity | Space Complexity |
| --------- | --------------- | ---------------- |
| Recursive | O(N)            | O(N)             |

---

## ✅ Key Points

* Preorder traversal is useful for **copying the tree** or **expressing it as a string**.
* Works for both **balanced** and **unbalanced** trees.
* Simple **recursive solution**, can also be implemented iteratively using a stack.



# question 4 🍂 Postorder Traversal of a Binary Tree

**Difficulty:** 🟢 Easy
**Points:** 52 / 100

---

## 📌 Problem Statement

Given the **root of a binary tree**, return the **Postorder Traversal** of the binary tree.

* **Postorder Traversal (LRN):**

  1. Traverse the **Left Subtree**
  2. Traverse the **Right Subtree**
  3. Visit the **Node**

---

## 🖼️ Examples

### Example 1

**Input:**

```text
root = [1, 4, null, 4, 2]
```

**Output:**

```text
[4, 2, 4, 1]
```

### Example 2

**Input:**

```text
root = [1, null, 2, 3]
```

**Output:**

```text
[3, 2, 1]
```

---

## 💻 C++ Solution

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

class Solution {
private:
    void recursivePostOrder(TreeNode* root, vector<int> &arr) {
        if(root == nullptr) return;

        // Traverse left subtree
        recursivePostOrder(root->left, arr);

        // Traverse right subtree
        recursivePostOrder(root->right, arr);

        // Visit current node
        arr.push_back(root->data);
    }

public:
    vector<int> postorder(TreeNode* root) {
        vector<int> arr;
        recursivePostOrder(root, arr);
        return arr;
    }
};
```

---

## 📝 Explanation

1. Traverse the **left subtree** recursively.
2. Traverse the **right subtree** recursively.
3. Visit the **current node** and store its value.
4. The result is stored in a vector and returned.

---

## 📊 Complexity Analysis

| Approach  | Time Complexity | Space Complexity |
| --------- | --------------- | ---------------- |
| Recursive | O(N)            | O(N)             |

---

## ✅ Key Points

* Postorder traversal is useful for **deleting trees** or **evaluating expression trees**.
* Works for both **balanced** and **unbalanced** trees.
* Simple **recursive solution**, can also be implemented iteratively using a stack.

---

## Build tree from Level order traversal

```cpp

void buildFromLevelOrder(node* root){
    queue<node*> q;
    cout<<"enter data for root :"<<endl;
    int data;
    cin>>data;
    root =new node(data);
    q.push(root);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        cout<<enter left data for :<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"enter right data for :"<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
```

## count complete tree 
### leetcode problem

```cpp
class Solution {
    private:
    int inOrder(TreeNode* root , int& ans){
        if(root==NULL){
            return 0;
        }
        inOrder(root->left , ans);
        ans++; // count current node
        inOrder(root->right , ans);

        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        int ans = 0 ;
        inOrder(root , ans);
       
       return ans;
    }
};
```

## count leaf nodes 
### geekfor geeks
```cpp
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
    private:
    void inOrder(Node* root , int& count){
        if(root==NULL) return;
        inOrder(root->left , count);
        if(root->left==NULL && root->right==NULL){
            count++;
        }
        inOrder(root->right , count);
    }
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        int count=0;
        inOrder(root , count);
        return count;
    }
};
```

