# 🌲 Binary Tree Problem Set (C++)

Welcome to the **Binary Tree Problem Set**! 🌿
This collection contains common **binary tree problems** solved in **C++**, each with code, input/output format, time complexity, and practice links.

---

## 📑 Table of Contents

1. [🌳 Maximum Depth of Binary Tree](#1--maximum-depth-of-binary-tree)
2. [🌿 Diameter of Binary Tree](#2--diameter-of-binary-tree)
3. [🌴 Balanced Binary Tree](#3--balanced-binary-tree)
4. [🌲 Identical Binary Trees](#4--identical-binary-trees)
5. [🌰 Sum Tree Check](#5--sum-tree-check)
6. [🌾 Zigzag Traversal](#6--zigzag-traversal)

---

## 1️⃣  Maximum Depth of Binary Tree

**Problem:** Find the maximum depth (height) of a binary tree.

**Code:**

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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = maxDepth(root->left); // height left tree ka 
        int right = maxDepth(root->right); // height right tree ka 
         
         int val = max(left , right)+ 1 ;// +1 because root ko alag se add kar rhe hai 
         return val;
    }
};

```

**Input Example:**

```
Input: [3,9,20,null,null,15,7]
```

**Output:**

```
Output: 3
```

**Time Complexity:** `O(N)`
**Space Complexity:** `O(H)` (where H = height of tree)

**Practice:** [LeetCode - 104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

---

## 2️⃣ Diameter of Binary Tree

**Problem:** Find the diameter (longest path between any two nodes) of a binary tree.

**Code:**

```cpp
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    private:
    
    int height(struct Node* root){
        if(root==NULL){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left , right)+1;
        return ans;
    }
      // Helper function that returns {diameter, height}
    pair<int, int> diameterFast(Node* root) {
        // Base case
        if (root == NULL) {
            return {0, 0};
        }

        // Recursive calls
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int op1 = left.first;                       // Diameter of left subtree
        int op2 = right.first;                      // Diameter of right subtree
        int op3 = left.second + right.second + 1;   // Diameter through root

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));        // Final diameter
        ans.second = max(left.second, right.second) + 1;  // Height

        return ans;
    }
  public:
    int diameter(Node* root) {
        //// Subtract 1 because the problem expects diameter in edges, not nodes
        return diameterFast(root).first-1; 
    }
};

```

**Input Example:**

```
Input: [1,2,3,4,5]
```

**Output:**

```
Output: 3
```

**Time Complexity:** `O(N)`
**Space Complexity:** `O(H)`

**Practice:** [LeetCode - 543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

---

## 3️⃣ Balanced Binary Tree

**Problem:** Check whether a binary tree is height-balanced.

**Code:**

```cpp
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    // Helper function that returns a pair:
    // first  -> bool (true if subtree is balanced)
    // second -> int  (height of the subtree)
    pair<bool, int> isBalancedFast(Node* root) {
        
        // Base case: An empty tree is always balanced and its height is 0
        if (root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        // Recursive call for left and right subtrees
        // Each call returns {isBalanced, height}
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);

        // Check if left and right subtrees are balanced
        bool leftAns = left.first;
        bool rightAns = right.first;

        // Check if the height difference between left and right subtrees is <= 1
        bool diff = abs(left.second - right.second) <= 1;

        // Prepare the answer for the current node
        pair<bool, int> ans;
        // Height = max height of both subtrees + 1 (for current node)
        ans.second = max(left.second, right.second) + 1;

        // If both subtrees are balanced and the height difference is within 1,
        // then the current subtree is balanced
        if (leftAns && rightAns && diff) {
            ans.first = true;
        } 
        else {
            ans.first = false;
        }

        // Return the pair {isBalanced, height} for current node
        return ans;
    }

    // Main function to check if the entire tree is balanced
    bool isBalanced(Node* root) {
        // Only return the boolean part from the helper function
        return isBalancedFast(root).first;
    }
};

```

**Input Example:**

```
Input: [3,9,20,null,null,15,7]
```

**Output:**

```
Output: true
```

**Time Complexity:** `O(N)`
**Space Complexity:** `O(H)`

**Practice:** [LeetCode - 110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

---

## 4️⃣ Identical Binary Trees

**Problem:** Check if two binary trees are identical.

**Code:**

```cpp
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // agar dono r1 and r2 null then return true 
        if(r1 ==NULL && r2 == NULL){
            return true;
        }
        //agar r1 null nhi hai aur r2 null taab bhi false identical nhi hoga 
        if(r1 != NULL && r2 == NULL){
            return false;
        }
        //agar r1 null hai aur r2 not null taab  bhi false identical nhi hoga
        if(r1==NULL && r2 != NULL){
            return false;
        }
        
        //ab compare kar rhe hai ek roo ko lekar ek tree ke root ke left node se aur dusre tree ke left se 
        bool left = isIdentical(r1->left , r2->left);
        //ab compare kar rhe hai ek roo ko lekar ek tree ke root ke right node se aur dusre tree ke right se 
        bool right = isIdentical(r1->right , r2->right);
        //root node compare kar rhe hai 
        bool val = r1->data == r2->data;
        //agar root , left , right dono tree ka similar then identical 
        if(left && right && val){
            return true;
        }
        else{
            return false;
        }
    }
};


```

**Input Example:**

```
Tree 1: [1,2,3]  
Tree 2: [1,2,3]
```

**Output:**

```
Output: true
```

**Time Complexity:** `O(N)`
**Space Complexity:** `O(H)`

**Practice:** [GeeksforGeeks - Identical Trees](https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1)

---

## 5️⃣ Sum Tree Check

**Problem:** Check if a binary tree is a Sum Tree (every node’s value equals the sum of values of its children).

**Code:**

```cpp
class Solution {
  public:
    //   Returns a pair:
    //   1. first  -> true if the subtree is a Sum Tree, false otherwise.
    //   2. second -> the sum of all nodes in this subtree.
  pair<bool, int> isSumTreeFast(Node* root) {

      // Base Case 1: If the node is NULL, it is considered a Sum Tree.
      // Sum of an empty tree is 0.
      if (root == NULL) {
          return make_pair(true, 0);
      }

      // Base Case 2: If the node is a leaf node (no children),
      // it is also a Sum Tree by definition.
      if (root->left == NULL && root->right == NULL) {
          return make_pair(true, root->data);
      }

      // Recursive call to check left and right subtrees.
      pair<bool, int> leftAns = isSumTreeFast(root->left);
      pair<bool, int> rightAns = isSumTreeFast(root->right);

      // Extracting values from the returned pairs.
      bool isLeftSumTree = leftAns.first;    // Is left subtree a Sum Tree?
      bool isRightSumTree = rightAns.first;  // Is right subtree a Sum Tree?
      int leftSum = leftAns.second;          // Sum of left subtree nodes
      int rightSum = rightAns.second;        // Sum of right subtree nodes

      // Check the current node’s condition for Sum Tree:
      // A node is a Sum Tree if its data equals the sum of left and right subtree sums.
      bool cond = (root->data == leftSum + rightSum);

      // Create a pair to store the result for the current subtree.
      pair<bool, int> ans;

      // The current subtree is a Sum Tree if:
      // 1. Left subtree is a Sum Tree.
      // 2. Right subtree is a Sum Tree.
      // 3. The current node satisfies the Sum Tree property.
      if (isLeftSumTree && isRightSumTree && cond) {
          ans.first = true;  // Current subtree is a Sum Tree
          // Total sum of this subtree (including current node)
          ans.second = root->data + leftSum + rightSum;
      } 
      else {
          ans.first = false; // Not a Sum Tree
          ans.second = 0;    // Sum value doesn’t matter in this case
      }

      // Return the result for the current subtree
      return ans;
  }

  bool isSumTree(Node* root) {
    
      return isSumTreeFast(root).first;
  }
};


```

**Input Example:**

```
Input: [3,1,2]
```

**Output:**

```
Output: true
```

**Time Complexity:** `O(N)`
**Space Complexity:** `O(H)`

**Practice:** [GeeksforGeeks - Sum Tree](https://www.geeksforgeeks.org/problems/sum-tree/1)

---

## 6️⃣ Zigzag Traversal

**Problem:** Traverse the binary tree in zigzag (spiral) order.

**Code:**

```cpp
/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        // Final result vector
        vector<int> result;

        // If tree is empty, return empty result
        if (root == NULL) {
            return result;
        }

        // Queue for level order traversal
        queue<Node*> q;
        q.push(root);

        // Direction flag: true → left to right, false → right to left
        bool leftToRight = true;

        // Traverse level by level
        while (!q.empty()) {
            int size = q.size();  // Number of nodes at the current level
            vector<int> ans(size); // Temporary vector to store current level data

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                // Get index to insert depending on traversal direction
                int index = leftToRight ? i : (size - i - 1);
                ans[index] = frontNode->data;

                // Push left and right children into the queue
                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            // After processing one level, toggle direction
            leftToRight = !leftToRight;

            // Add current level's data to the final result
            for (auto val : ans) {
                result.push_back(val);
            }
        }

        return result;
    }
};
```

**Input Example:**

```
Input: [1,2,3,4,5,6,7]
```

**Output:**

```
Output: [1,3,2,4,5,6,7]
```

**Time Complexity:** `O(N)`
**Space Complexity:** `O(N)`

**Practice:** [GeeksforGeeks - ZigZag Tree Traversal](https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1)

---
