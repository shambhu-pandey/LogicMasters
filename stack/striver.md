# 📚 Stack & Queue — Master Table of Contents  


---

## 🟦 Stack Implementations
1. 🧱 **ArrayStack** — Stack using arrays  
   🔗 [GeeksforGeeks](https://www.geeksforgeeks.org/stack-data-structure/) | [LeetCode Discuss](https://leetcode.com/tag/stack/)  

2. 🔗 **LinkedListStack** — Stack using linked list nodes  
   🔗 [GeeksforGeeks](https://www.geeksforgeeks.org/implement-stack-using-linked-list/)  

3. 🔄 **QueueStack** — Stack implemented using two queues  
   🔗 [GeeksforGeeks](https://www.geeksforgeeks.org/implement-stack-using-two-queues/)  

4. 🧩 **Valid Parentheses** — Balanced brackets check using stack  
   🔗 [LeetCode](https://leetcode.com/problems/valid-parentheses/) | [GeeksforGeeks](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)  

5. 📈 **Next Greater Element (Single Array)** — Monotonic stack approach  
   🔗 [GeeksforGeeks](https://www.geeksforgeeks.org/next-greater-element/) | [LeetCode](https://leetcode.com/tag/stack/)  

6. 🔄 **Next Greater Element II (Circular Array)** — Handle circular arrays with stack  
   🔗 [LeetCode](https://leetcode.com/problems/next-greater-element-ii/)  

7. 🗂️ **Next Greater Element I (Two Arrays)** — nums1 lookup in nums2  
   🔗 [LeetCode](https://leetcode.com/problems/next-greater-element-i/)  

8. 🧮 **Sum of Subarray Minimums** — Contribution technique with prev/next smaller  
   🔗 [LeetCode](https://leetcode.com/problems/sum-of-subarray-minimums/) | [GeeksforGeeks](https://www.geeksforgeeks.org/sum-of-subarray-minimums/)  

9. ☄️ **Asteroid Collision** — Simulate asteroid collisions using stack  
   🔗 [LeetCode](https://leetcode.com/problems/asteroid-collision/)  

---

## 🟩 Queue Implementations
10. 📦 **ArrayQueue** — Queue using arrays with circular indexing  
    🔗 [GeeksforGeeks](https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/)  

11. 🔗 **LinkedListQueue** — Queue using linked list nodes  
    🔗 [GeeksforGeeks](https://www.geeksforgeeks.org/queue-linked-list-implementation/)  

12. 🔄 **StackQueue** — Queue implemented using two stacks  
    🔗 [GeeksforGeeks](https://www.geeksforgeeks.org/queue-using-stacks/)  

---

## 🟨 Array/DP Related (Stack/Queue Logic Applied)
13. 💡 **Maximum Subarray (Kadane’s Algorithm)** — Largest sum contiguous subarray  
    🔗 [LeetCode](https://leetcode.com/problems/maximum-subarray/) | [GeeksforGeeks](https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/)  

14. 📊 **Sum of Subarray Ranges** — Brute force calculation of max-min ranges  
    🔗 [LeetCode](https://leetcode.com/problems/sum-of-subarray-ranges/)  

---


## 🟦 Stack Problems

15. 💡 **Remove K Digits** — Greedy monotonic stack for smallest number  
   🔗 [LeetCode](https://leetcode.com/problems/remove-k-digits/)  

16. 📉 **Min Stack** — Stack supporting getMin in O(1)  
   🔗 [LeetCode](https://leetcode.com/problems/min-stack/)  

17. 🪟 **Sliding Window Maximum** — Monotonic deque for max in window  
   🔗 [LeetCode](https://leetcode.com/problems/sliding-window-maximum/)  

18. 🌊 **Trapping Rain Water** — Prefix/suffix max arrays for trapped water  
   🔗 [LeetCode](https://leetcode.com/problems/trapping-rain-water/)  

19. 📊 **Largest Rectangle in Histogram** — Max area using left/right smaller  
   🔗 [LeetCode](https://leetcode.com/problems/largest-rectangle-in-histogram/)  

20. 🏢 **Maximal Rectangle in Binary Matrix** — Histogram extension row by row  
   🔗 [LeetCode](https://leetcode.com/problems/maximal-rectangle/)  

21. 📈 **Stock Span Problem** — Consecutive days span using monotonic stack  
   🔗 [GeeksforGeeks](https://www.geeksforgeeks.org/the-stock-span-problem/)  

22. 🎭 **Celebrity Problem** — Find celebrity using elimination + verification  
   🔗 [GeeksforGeeks](https://www.geeksforgeeks.org/the-celebrity-problem/)  

---



# 1 📚 Stack Implementation using Arrays (C++)

**Difficulty:** 🟢 Easy  
**Tags:** Stack, Data Structures, Arrays  

---

### 🧩 Problem Statement  
Implement a stack using arrays with the following operations:  
- **push(x):** Insert element `x` at the top of the stack.  
- **pop():** Remove and return the top element.  
- **top():** Return the top element without removing it.  
- **isEmpty():** Check if the stack is empty.  

---

### 💡 Approach  
1. Use a **dynamic array (`int* st`)** to store stack elements.  
2. Maintain a variable `topIndex` to track the current top position.  
   - Initially `topIndex = -1` (empty stack).  
3. **Push:** Increment `topIndex` and insert the element.  
   - Check for overflow (`topIndex >= capacity-1`).  
4. **Pop:** Return element at `topIndex` and decrement it.  
   - Check for underflow (`isEmpty()`).  
5. **Top:** Return element at `topIndex` without removing it.  
6. **isEmpty:** Return true if `topIndex == -1`.  

---

### 💻 Your Code (Unchanged)

```cpp
class ArrayStack {
    public:
    int* st;
    int capacity;
    int topIndex;

    ArrayStack(int size=1000) {
      capacity= size;
      st = new int[capacity];
      topIndex = -1;  
    }
    ~ArrayStack(){
        delete[] st;
    }
    void push(int x) {
        if(topIndex >= capacity-1){
          cout<<"stack overflow"<<endl;
          return;
        }
        st[++topIndex]=x;
    }
    
    int pop() {
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return st[topIndex--];
    }
    
    int top() {
        if(isEmpty()){
             cout<<"stack is empty"<<endl;
            return -1;
        }
      return st[topIndex];
    }
    
    bool isEmpty() {
            return topIndex == -1;
    }
};
```

---

### 📊 Complexity  
- **Push:** O(1)  
- **Pop:** O(1)  
- **Top:** O(1)  
- **isEmpty:** O(1)  
- **Space Complexity:** O(n) (array size)  

---

Excellent, Shambhu ✅. You’ve implemented a **Queue using Arrays** with circular indexing. Let’s make this examiner‑friendly by explaining the **approach, dry run, and visual representation of queue operations** while keeping your code untouched.

---

# 2 📚 Queue Implementation using Arrays (C++)

**Difficulty:** 🟢 Easy  
**Tags:** Queue, Data Structures, Arrays  

---

### 🧩 Problem Statement  
Implement a queue using arrays with the following operations:  
- **push(x):** Insert element `x` at the rear of the queue.  
- **pop():** Remove and return the front element.  
- **peek():** Return the front element without removing it.  
- **isEmpty():** Check if the queue is empty.  

---

### 💡 Approach  
1. Use a **dynamic array (`int* q`)** to store queue elements.  
2. Maintain two indices:  
   - `start` → points to the front element.  
   - `end` → points to the rear element.  
3. **Push:**  
   - If queue is full → overflow.  
   - If empty → initialize `start=0, end=0`.  
   - Otherwise → move `end = (end+1) % maxSize` (circular increment).  
   - Insert element at `q[end]`.  
4. **Pop:**  
   - If empty → underflow.  
   - Store element at `q[start]`.  
   - If only one element → reset `start` and `end` to `-1`.  
   - Otherwise → move `start = (start+1) % maxSize`.  
   - Return the popped element.  
5. **Peek:** Return `q[start]`.  
6. **isEmpty:** Return true if `currentSize == 0`.  

---

### 💻 Your Code (Unchanged)

```cpp
class ArrayQueue {
private:
    int* q;
    int start;
    int end;
    int currentSize , maxSize;

public:
    ArrayQueue(int size =1000) {
        maxSize = size;
        q = new int[size];
        start=-1;
        end=-1;
        currentSize=0;
    }
    
    void push(int x) {
      if(currentSize == maxSize){
        cout<<"queue is full";
        exit(1);
      }
      if(end == -1){
        start=0;
        end=0;
      }
      else{
        end = (end+1)% maxSize;
      }
      q[end]= x;
      currentSize++;
    }
    
    int pop() {
      if(start == -1){
        cout<<"queue is empty";
        exit(1);
      }

      int element = q[start];
      if(currentSize ==1){
        start = -1;
        end = -1;
      }
      else{
        start = (start+1)% maxSize;
      }
      currentSize--;
      return element;
      
    }
    
    int peek() {
    return q[start];
    }
    
    bool isEmpty() {
      return currentSize == 0;
    }
};
```

---

### 📊 Complexity  
- **Push:** O(1)  
- **Pop:** O(1)  
- **Peek:** O(1)  
- **isEmpty:** O(1)  
- **Space Complexity:** O(n) (array size)  

---

Perfect, Shambhu ✅. You’ve implemented a **Stack using Queues** (the *two‑queue method*). Let’s make this examiner‑friendly with a clear **approach, dry run, and complexity analysis**, while keeping your code untouched.

---

# 3 📚 Stack Implementation using Queues (Two‑Queue Method)

**Difficulty:** 🟡 Medium  
**Tags:** Stack, Queue, Data Structures  

---

### 🧩 Problem Statement  
Implement a stack using two queues (`q1` and `q2`) with the following operations:  
- **push(x):** Insert element `x` into the stack.  
- **pop():** Remove and return the top element.  
- **top():** Return the top element without removing it.  
- **isEmpty():** Check if the stack is empty.  

---

### 💡 Approach  
1. **Push(x):**  
   - Move all elements from `q1` to `q2`.  
   - Push the new element into `q1`.  
   - Move all elements back from `q2` to `q1`.  
   - This ensures the newest element is always at the **front of q1** (so it behaves like stack top).  

2. **Pop():**  
   - Return and remove the front element of `q1`.  

3. **Top():**  
   - Return the front element of `q1` without removing it.  

4. **isEmpty():**  
   - Return true if `q1` is empty.  

---

### 💻 Your Code (Unchanged)

```cpp
class QueueStack {
    queue<int> q1;
    queue<int> q2;
public:
    QueueStack() {
    }
    
    void push(int x) {
      while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
      }
      q1.push(x);

      while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
      }
    }
    
    int pop() {
      int element = q1.front();
      q1.pop();
      return element;
    }
    
    int top() {
       return q1.front();
    }
    
    bool isEmpty() {
      return q1.empty();
    }
};
```

---


### 📊 Complexity  
- **Push:** O(n) (moving elements between queues)  
- **Pop:** O(1)  
- **Top:** O(1)  
- **isEmpty:** O(1)  
- **Space Complexity:** O(n)  

---

# 4️⃣ Queue Implementation using Stacks (Two‑Stack Method)

**Difficulty:** 🟡 Medium  
**Tags:** Queue, Stack, Data Structures  

---

### 🧩 Problem Statement  
Implement a queue using two stacks (`s1` and `s2`) with the following operations:  
1. **push(x):** Insert element `x` into the queue.  
2. **pop():** Remove and return the front element.  
3. **peek():** Return the front element without removing it.  
4. **isEmpty():** Check if the queue is empty.  

---

### 💡 Approach  
1. **Push(x):**  
   - Move all elements from `s1` to `s2`.  
   - Push the new element into `s1`.  
   - Move all elements back from `s2` to `s1`.  
   - This ensures the **front of the queue** is always at the **top of s1**.  

2. **Pop():**  
   - Return and remove the top element of `s1`.  

3. **Peek():**  
   - Return the top element of `s1` without removing it.  

4. **isEmpty():**  
   - Return true if `s1` is empty.  

---

### 💻 Solution (C++)  
*(Your exact code, unchanged)*

```cpp
class StackQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    StackQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int element = s1.top();
        s1.pop();
        return element;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool isEmpty() {
        return s1.empty();
    }
};
```

---

### 📊 Complexity  
- **Push:** O(n) (moving elements between stacks)  
- **Pop:** O(1)  
- **Peek:** O(1)  
- **isEmpty:** O(1)  
- **Space Complexity:** O(n)  

---


# 5️⃣ Stack Implementation using Linked List

**Difficulty:** 🟡 Medium  
**Tags:** Stack, Linked List, Data Structures  

---

### 🧩 Problem Statement  
Implement a stack using a singly linked list with the following operations:  
1. **push(x):** Insert element `x` at the top of the stack.  
2. **pop():** Remove and return the top element.  
3. **top():** Return the top element without removing it.  
4. **isEmpty():** Check if the stack is empty.  

---

### 💡 Approach  
1. Each node contains:  
   - `val` → data value.  
   - `next` → pointer to the next node.  
2. Maintain a pointer `topIndex` to the current top of the stack.  
3. **Push(x):**  
   - Create a new node.  
   - Link it to the current `topIndex`.  
   - Update `topIndex` to the new node.  
4. **Pop():**  
   - If stack empty → return `-1`.  
   - Otherwise, store `topIndex->val`, move `topIndex` to `topIndex->next`, delete old node, return value.  
5. **Top():**  
   - Return `topIndex->val` if stack not empty, else `-1`.  
6. **isEmpty():**  
   - Return true if `size == 0`.  

---

### 💻 Your Code (Unchanged)

```cpp
struct Node{
    int val;
    Node* next;
    Node(int d){
        val = d;
        next = NULL;
    }
};
class LinkedListStack {
private:
    Node* topIndex;
    int size;

public:
    LinkedListStack() {
      topIndex =  NULL;
      size=0;
    }
    
    void push(int x) {
       Node* newNode = new Node(x);
       newNode->next = topIndex;
       topIndex = newNode;

       size++;
    }
    
    int pop() {
      if(topIndex==NULL){
        return -1;
      }
      int value =  topIndex->val;
      Node* temp = topIndex;
      topIndex = topIndex->next;
      delete temp;
      size--;

      return value;
    }
    
    int top() {
    if(topIndex==NULL){
        return -1;
    }
    return topIndex->val;
    }
    
    bool isEmpty() {
      return size == 0;
    }
};
```

---


### 📊 Complexity  
- **Push:** O(1)  
- **Pop:** O(1)  
- **Top:** O(1)  
- **isEmpty:** O(1)  
- **Space Complexity:** O(n) (linked list nodes)  

---


# 6️⃣ Queue Implementation using Linked List

**Difficulty:** 🟢 Easy  
**Tags:** Queue, Linked List, Data Structures  

---

### 🧩 Problem Statement  
Implement a queue using a singly linked list with the following operations:  
1. **push(x):** Insert element `x` at the rear of the queue.  
2. **pop():** Remove and return the front element.  
3. **peek():** Return the front element without removing it.  
4. **isEmpty():** Check if the queue is empty.  

---

### 💡 Approach  
1. Each node contains:  
   - `val` → data value.  
   - `next` → pointer to the next node.  
2. Maintain two pointers:  
   - `start` → points to the front of the queue.  
   - `end` → points to the rear of the queue.  
3. **Push(x):**  
   - Create a new node.  
   - If queue is empty → set both `start` and `end` to the new node.  
   - Otherwise → link `end->next` to new node and update `end`.  
4. **Pop():**  
   - If queue empty → exit.  
   - Otherwise → store `start->val`, move `start` to `start->next`, delete old node, return value.  
5. **Peek():**  
   - Return `start->val` if queue not empty.  
6. **isEmpty():**  
   - Return true if `size == 0`.  

---

### 💻 Your Code (Unchanged)

```cpp
struct Node{
    int val;
    Node* next;
    Node(int d){
        val=d;
        next = NULL;
    }
};

class LinkedListQueue {
 private:
 Node* start;
 Node* end;
 int size;   
public:
    LinkedListQueue() {
      start = NULL;
      end= NULL;
      size=0;
    }
    
    void push(int x) {
       Node* temp = new Node(x);
       if(start==NULL){
       start = temp;
       end = temp;
       }
       else{
        end ->next = temp;
        end = temp;
       }
       size++;
    }
    
    int pop() {
      if(start==0){
        exit(1);
      }
      int element = start->val;
      Node* temp= start;
      start = start->next;
      delete temp;
      size--;

      return  element;
    }
    
    int peek() {
     return start->val;
    }
    
    bool isEmpty() {
       return size == 0;
    }
};
```

---


### 📊 Complexity  
- **Push:** O(1)  
- **Pop:** O(1)  
- **Peek:** O(1)  
- **isEmpty:** O(1)  
- **Space Complexity:** O(n) (linked list nodes)  

---

# 7️⃣ Valid Parentheses (Balanced Brackets)

**Difficulty:** 🟢 Easy  
**Tags:** Stack, String, Data Structures  

---

### 🧩 Problem Statement  
Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'`, determine if the input string is valid.  
A string is valid if:  
1. Open brackets are closed by the same type of brackets.  
2. Open brackets are closed in the correct order.  

---

### 💡 Approach (Stack Based)  
1. Traverse the string character by character.  
2. If the character is an **opening bracket** (`(`, `{`, `[`), push it onto the stack.  
3. If the character is a **closing bracket** (`)`, `}`, `]`):  
   - If the stack is empty → invalid.  
   - Otherwise, pop the top element and check if it matches the closing bracket using `isMatched()`.  
   - If not matched → invalid.  
4. After traversal, if the stack is empty → valid string.  
5. If stack not empty → invalid string.  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution {
public:
    bool isMatched(char open , char close){
        if((open =='(' && close ==')') || (open == '{' && close =='}') || (open =='[' && close ==']')){
            return true;
        }
        
        return false;
    } 
    bool isValid(string str) {
       stack<char> st;

       for(int i =0 ;i < str.length();i++){
           if(str[i]=='(' || str[i] =='[' ||str[i]=='{'){
            st.push(str[i]);
           }
           else{
            if(st.empty()) return false;

            char ch = st.top();
            st.pop();

            if(!isMatched(ch , str[i])) return false;
           }
       }

       return st.empty();
    }
};
```

---

### 📝 Dry Run Example  

**Input:**
```
str = "{[()]}"
```

**Step-by-step stack state:**

| Character | Action | Stack (top → bottom) |
|-----------|--------|-----------------------|
| `{`       | push   | [`{`]                 |
| `[`       | push   | [`[`, `{`]            |
| `(`       | push   | [`(`, `[`, `{`]       |
| `)`       | match with `(`, pop | [`[`, `{`] |
| `]`       | match with `[`, pop | [`{`]     |
| `}`       | match with `{`, pop | []        |

Stack empty → ✅ valid string.

---

### 📊 Complexity  
- **Time Complexity:** O(n) → each character processed once  
- **Space Complexity:** O(n) → stack stores opening brackets  

---

### 🔗 Practice Links  
- [LeetCode: Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)  
- [GeeksforGeeks: Balanced Parentheses](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)  
- [Coding Ninjas: Valid Parentheses](https://www.codingninjas.com/studio/problems/valid-parentheses_696191)  

---


# 8️⃣ Next Greater Element (NGE)

**Difficulty:** 🟡 Medium  
**Tags:** Stack, Monotonic Stack, Array  

---

### 🧩 Problem Statement  
Given an array of integers, for each element find the **next greater element** to its right.  
- If no greater element exists, return `-1` for that position.  

---

### 💡 Approaches  

#### 1. Brute Force (Commented in Code)  
- For each element, scan all elements to its right.  
- If a greater element is found, store it and break.  
- If none found, store `-1`.  
- **Time Complexity:** O(n²)  

#### 2. Optimized (Monotonic Stack)  
- Traverse the array from **right to left**.  
- Maintain a stack of potential next greater elements.  
- For each element:  
  - Pop elements from the stack until the top is strictly greater.  
  - If stack empty → answer is `-1`.  
  - Otherwise → stack’s top is the next greater element.  
- Push the current element onto the stack.  
- **Time Complexity:** O(n)  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
    //      int n = arr.size();
    //    vector<int> nge(n , -1);

    //    for(int i =0;i<n;i++){
    //     for(int j = i+1 ; j<n;j++){
    //         if(arr[j]>arr[i]){
    //             nge[i]= arr[j];
    //             break;
    //         }
    //     }
    //    }
    //    return nge;


    int n = arr.size();
    vector<int> ans(n);

    stack<int> st;

   // Start traversing from the back
    for(int i = n-1 ; i>=0 ;i--){
        /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
        while(!st.empty() && st.top() <= arr[i] ){
            st.pop();
        }
           /* If the greater element is not 
            found, stack will be empty */
        if(st.empty()) ans[i] = -1;
        // Else store the answer
        else{
            ans[i] = st.top();
        }
        /* Push the current element in the stack 
            maintaining the decreasing order */
        st.push(arr[i]);
    }

    return ans;
    }
};
```

---

### 📝 Dry Run Example  

**Input:**
```
arr = [4, 5, 2, 25]
```

**Step-by-step stack state (right → left):**

| i | arr[i] | Stack (top → bottom) | ans[i] |
|---|--------|-----------------------|--------|
| 3 | 25     | [] → push 25          | -1     |
| 2 | 2      | [25]                  | 25     |
| 1 | 5      | [25]                  | 25     |
| 0 | 4      | [25,5] → top=5        | 5      |

**Output:**
```
ans = [5, 25, 25, -1]
```

---

### 📊 Complexity  
- **Brute Force:** O(n²)  
- **Optimized Stack:** O(n)  
- **Space Complexity:** O(n) (stack + answer array)  

---

### 🔗 Practice Links  
- [GeeksforGeeks: Next Greater Element](https://www.geeksforgeeks.org/next-greater-element/)  
- [LeetCode: Next Greater Element Problems](https://leetcode.com/tag/stack/)  
- [Coding Ninjas: Next Greater Element](https://www.codingninjas.com/studio/problems/next-greater-element_1112581)  

---


# 9️⃣ Next Greater Element II (Circular Array)

**Difficulty:** 🟡 Medium  
**Tags:** Stack, Monotonic Stack, Array  

---

### 🧩 Problem Statement  
Given a circular array, for each element find the **next greater element** to its right.  
- If no greater element exists, return `-1`.  
- Circular means after the last element, we continue searching from the beginning.  

---

### 💡 Approach (Monotonic Stack with 2 Passes)  
1. Traverse the array **twice** (simulate circular behavior).  
   - Loop from `2*n - 1` down to `0`.  
2. Use a stack to maintain potential next greater elements.  
3. For each index `i`:  
   - Compute actual index as `ind = i % n`.  
   - Pop elements from stack until the top is strictly greater than `arr[ind]`.  
   - If `i < n` (first pass), store the answer:  
     - If stack empty → `-1`.  
     - Else → stack’s top is the next greater element.  
   - Push `arr[ind]` onto the stack.  
4. Return the answer array.  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

       // Start traversing from the back
        for(int i = 2*n - 1 ; i>= 0 ; i--){

            // Get the actual index !! important!!  
           int ind = i %n;
            while(!st.empty() && st.top()<= arr[ind]){
                st.pop();
            }
        // Store the answer for the second half
            if(i<n){
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }

            st.push(arr[ind]);
        }

        return ans;
    }
};
```

---

### 📝 Dry Run Example  

**Input:**
```
arr = [1, 2, 1]
```

**Step-by-step stack state (right → left, 2 passes):**

| i | ind | arr[ind] | Stack (top → bottom) | ans[ind] |
|---|-----|----------|-----------------------|----------|
| 5 | 2   | 1        | [] → push 1           |          |
| 4 | 1   | 2        | [1] → push 2          |          |
| 3 | 0   | 1        | [2,1] → push 1        |          |
| 2 | 2   | 1        | pop 1, top=2 → ans[2]=2 | 2        |
| 1 | 1   | 2        | pop 2, stack empty → ans[1]=-1 | -1 |
| 0 | 0   | 1        | top=2 → ans[0]=2      | 2        |

**Output:**
```
ans = [2, -1, 2]
```

---

### 📊 Complexity  
- **Time Complexity:** O(n) → each element pushed/popped at most once  
- **Space Complexity:** O(n) → stack + answer array  

---

### 🔗 Practice Links  
- [LeetCode: Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)  
- [GeeksforGeeks: Next Greater Element (Circular Array)](https://www.geeksforgeeks.org/next-greater-element-in-circular-array/)  
- [Coding Ninjas: Next Greater Element II](https://www.codingninjas.com/studio/problems/next-greater-element-ii_1112582)  

---

# 🔟 Asteroid Collision (Stack Simulation)

**Difficulty:** 🟡 Medium  
**Tags:** Stack, Simulation, Array  

---

### 🧩 Problem Statement  
We are given an array `asteroids` of integers representing asteroids moving in a row:  
- Each asteroid’s absolute value represents its size.  
- The sign represents its direction:  
  - Positive → moving right.  
  - Negative → moving left.  
- When two asteroids moving in opposite directions collide:  
  - The smaller one explodes.  
  - If equal size → both explode.  
- Return the state of asteroids after all collisions.  

---

### 💡 Approach (Stack Simulation)  
1. Use a vector `st` as a stack to simulate asteroid movement.  
2. Traverse each asteroid:  
   - If asteroid is **positive (moving right)** → push onto stack.  
   - If asteroid is **negative (moving left)**:  
     - While stack not empty and top asteroid is positive and smaller than current → pop (right asteroid explodes).  
     - If stack not empty and top asteroid equals current in size → pop (both explode).  
     - If stack empty or top asteroid is negative → push current asteroid (no collision).  
3. Continue until all asteroids are processed.  
4. Return the stack as the final state.  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution{
public:
    vector<int> asteroidCollision(vector<int> &asteroids){
        int n = asteroids.size();
        vector<int> st;

        for(int i =0; i <n;i++){
            if(asteroids[i]>0){
                st.push_back(asteroids[i]);
            }
            else{
                while(!st.empty() && st.back() >0 && st.back() < abs(asteroids[i])){
                    st.pop_back();
                }

                if(!st.empty() && st.back() == abs(asteroids[i])){
                    st.pop_back();
                }

                else if(st.empty() || st.back()<0){
                    st.push_back(asteroids[i]);
                }
            }
        }

        return st;
    }
};
```

---

### 📝 Dry Run Example  

**Input:**
```
asteroids = [5, 10, -5]
```

**Step-by-step stack state:**

| Asteroid | Action | Stack |
|----------|--------|-------|
| 5        | push   | [5]   |
| 10       | push   | [5,10]|
| -5       | collide with 10 → 10 survives | [5,10] |

**Output:**
```
[5,10]
```

---

**Another Example:**
```
asteroids = [8, -8]
```

- 8 (push → [8])  
- -8 (collides with 8, both equal → both explode → [])  

**Output:**
```
[]
```

---

### 📊 Complexity  
- **Time Complexity:** O(n) → each asteroid processed once, each popped at most once  
- **Space Complexity:** O(n) → stack stores surviving asteroids  

---

### 🔗 Practice Links  
- [LeetCode: Asteroid Collision](https://leetcode.com/problems/asteroid-collision/)  
- [GeeksforGeeks: Asteroid Collision Problem](https://www.geeksforgeeks.org/asteroid-collision-problem/)  
- [Coding Ninjas: Asteroid Collision](https://www.codingninjas.com/studio/problems/asteroid-collision_1468365)  

---

# 1️⃣1️⃣ Sum of Subarray Minimums

**Difficulty:** 🔴 Hard  
**Tags:** Stack, Monotonic Stack, Dynamic Programming  

---

### 🧩 Problem Statement  
Given an array of integers `arr`, return the sum of the minimum value of every subarray of `arr`.  
Since the answer can be very large, return it modulo `1e9+7`.

---

### 💡 Approaches  

#### 1. Brute Force (Commented in Code)  
- For each subarray, compute the minimum and add it to the sum.  
- **Time Complexity:** O(n²)  
- **Space Complexity:** O(1)  
- Works but too slow for large arrays.  

#### 2. Optimized (Monotonic Stack)  
- Each element contributes as the **minimum** in certain subarrays.  
- For each element `arr[i]`:  
  - Find the **previous smaller element** (left boundary).  
  - Find the **next smaller element** (right boundary).  
  - Compute how many subarrays include `arr[i]` as the minimum:  
    - `left = i - prevsmallest[i]`  
    - `right = nextsmallest[i] - i`  
    - Contribution = `arr[i] * left * right`  
- Add contributions for all elements.  
- **Time Complexity:** O(n)  
- **Space Complexity:** O(n)  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    //     BRUTE FORCE 
    //    int n = arr.size();
    //    int mod = 1e9 + 7
    //     long long sum=0;
        
    //     for(int i =0 ; i<n ; i++){
    //         int mini = arr[i];
            
    //         for(int j = i; j<n ; j++){
    //                mini = min(mini , arr[j]);
    //                sum = (sum + mini)%mod ;
    //         }
            
    //     }
    //     return sum;
        
        int n = arr.size();
        int mod = 1e9 + 7;   // bada number overflow se bachne ke liye

        stack<int> st;       // index store karne ke liye stack
        vector<int> prevsmallest(n), nextsmallest(n);

        // ---------- Previous Smaller Element (Left side) ----------
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if(st.empty())
                prevsmallest[i] = -1;
            else
                prevsmallest[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // ---------- Next Smaller Element (Right side) ----------
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(st.empty())
                nextsmallest[i] = n;
            else
                nextsmallest[i] = st.top();
            st.push(i);
        }

        // ---------- Sum calculate karna ----------
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - prevsmallest[i];
            long long right = nextsmallest[i] - i;
            sum = (sum + arr[i] * left * right) % mod;
        }

        return sum;
    }
};
```

---

### 📝 Dry Run Example  

**Input:**
```
arr = [3, 1, 2, 4]
```

**Subarrays and minimums:**
- [3] → 3  
- [3,1] → 1  
- [3,1,2] → 1  
- [3,1,2,4] → 1  
- [1] → 1  
- [1,2] → 1  
- [1,2,4] → 1  
- [2] → 2  
- [2,4] → 2  
- [4] → 4  

**Sum = 17**

---

### 📊 Complexity  
- **Brute Force:** O(n²)  
- **Optimized Stack:** O(n)  
- **Space Complexity:** O(n)  

---

### 🔗 Practice Links  
- [LeetCode: Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/)  
- [GeeksforGeeks: Sum of Subarray Minimums](https://www.geeksforgeeks.org/sum-of-subarray-minimums/)  
- [Coding Ninjas: Sum of Subarray Minimums](https://www.codingninjas.com/studio/problems/sum-of-subarray-minimums_1468366)  

---

# 1️⃣2️⃣ Sum of Subarray Ranges

**Difficulty:** 🟡 Medium  
**Tags:** Array, Brute Force, Stack (optimized version exists)  

---

### 🧩 Problem Statement  
Given an integer array `nums`, return the **sum of ranges** of all subarrays of `nums`.  
- The range of a subarray = `max(subarray) - min(subarray)`.  
- We need to compute this for every subarray and sum them up.  

---

### 💡 Approach (Brute Force)  
1. Iterate over all possible subarrays using two loops:  
   - Outer loop → starting index `i`.  
   - Inner loop → ending index `j`.  
2. For each subarray `nums[i...j]`:  
   - Track the **largest** and **smallest** values.  
   - Add `(largest - smallest)` to the total sum.  
3. Return the final sum.  

⚠️ This brute force approach works but is **O(n²)**, which is too slow for large arrays.  
👉 Optimized solution uses **monotonic stacks** to separately calculate contributions of each element as max and min in O(n).

---

### 💻 Your Code (Unchanged)

```cpp
class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
      int n = nums.size();

      long long sum =0;

      for(int i = 0 ; i<n ; i++){
        int largest = nums[i];
        int smallest = nums[i];

        for(int j = i ; j<n ; j++){
            largest = max(largest , nums[j]);
            smallest = min(smallest , nums[j]);

            sum = sum  + (largest-smallest);
        }
      }

      return sum;
    }
};
```

---

### 📝 Dry Run Example  

**Input:**
```
nums = [1,2,3]
```

**Subarrays and ranges:**
- [1] → max=1, min=1 → range=0  
- [1,2] → max=2, min=1 → range=1  
- [1,2,3] → max=3, min=1 → range=2  
- [2] → range=0  
- [2,3] → max=3, min=2 → range=1  
- [3] → range=0  

**Sum = 0+1+2+0+1+0 = 4**

---

### 📊 Complexity  
- **Brute Force:** O(n²)  
- **Optimized Stack Approach:** O(n)  
- **Space Complexity:** O(1) for brute force, O(n) for stack approach  

---

### 🔗 Practice Links  
- [LeetCode: Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)  
- [GeeksforGeeks: Sum of Subarray Ranges](https://www.geeksforgeeks.org/sum-of-subarray-ranges/)  
- [Coding Ninjas: Subarray Ranges](https://www.codingninjas.com/studio/problems/sum-of-subarray-ranges_1468367)  

---

# 1️⃣3️⃣ Next Greater Element I

**Difficulty:** 🟢 Easy  
**Tags:** Stack, Monotonic Stack, Hashmap  

---

### 🧩 Problem Statement  
You are given two arrays:  
- `nums1` (subset of `nums2`)  
- `nums2` (unique elements)  

For each element in `nums1`, find the **next greater element** in `nums2`.  
- The next greater element of `x` in `nums2` is the first greater element to the right of `x`.  
- If no greater element exists, return `-1`.  

---

### 💡 Approach (Stack + Hashmap)  
1. Traverse `nums2` from **right to left**.  
2. Use a stack to maintain potential next greater elements.  
3. For each element in `nums2`:  
   - Pop elements from stack until the top is strictly greater.  
   - If stack empty → next greater = `-1`.  
   - Otherwise → stack’s top is the next greater.  
   - Store result in a hashmap `mp[element] = nextGreater`.  
   - Push current element onto stack.  
4. Finally, for each element in `nums1`, lookup its answer in the hashmap.  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        stack<int> st;
        unordered_map<int , int>mp ;

        for(int i = n2-1 ; i>=0 ;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[i]]= -1;
            }
            else{
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }
        int n1 = nums1.size();  
        vector<int> ans(n1);
        for(int i = 0 ; i<n1;i++){
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};
```

---

### 📝 Dry Run Example  

**Input:**
```
nums1 = [4,1,2]
nums2 = [1,3,4,2]
```

**Step-by-step stack state (right → left):**

| i | nums2[i] | Stack (top → bottom) | mp[nums2[i]] |
|---|----------|-----------------------|--------------|
| 3 | 2        | [] → push 2           | -1           |
| 2 | 4        | [2] → push 4          | -1           |
| 1 | 3        | [4,2] → top=4         | 4            |
| 0 | 1        | [3,4,2] → top=3       | 3            |

**Hashmap:**  
```
{1:3, 3:4, 4:-1, 2:-1}
```

**Answer for nums1:**  
```
[4:-1, 1:3, 2:-1] → [-1, 3, -1]
```

---

### 📊 Complexity  
- **Time Complexity:** O(n1 + n2)  
- **Space Complexity:** O(n2) (stack + hashmap)  

---

### 🔗 Practice Links  
- [LeetCode: Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)  
- [GeeksforGeeks: Next Greater Element I](https://www.geeksforgeeks.org/next-greater-element/)  
- [Coding Ninjas: Next Greater Element I](https://www.codingninjas.com/studio/problems/next-greater-element-i_1112580)  

---


# 1️⃣4️⃣ Maximum Subarray (Kadane’s Algorithm)

**Difficulty:** 🟢 Easy  
**Tags:** Array, Dynamic Programming, Greedy  

---

### 🧩 Problem Statement  
Given an integer array `nums`, find the **subarray with the largest sum** and return its sum.  
- Subarray must be contiguous.  

---

### 💡 Approach (Kadane’s Algorithm)  
1. Initialize:  
   - `maxsum = nums[0]` → global maximum.  
   - `currsum = 0` → current running sum.  
2. Traverse each element in `nums`:  
   - Update `currsum = max(num, currsum + num)`  
     - Either extend the current subarray or start fresh from current element.  
   - Update `maxsum = max(maxsum, currsum)`  
     - Track the best sum seen so far.  
3. Return `maxsum` at the end.  

👉 Kadane’s Algorithm works because it greedily decides whether to continue the current subarray or start a new one at each step.

---

### 💻 Your Code (Unchanged)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize maxSum with the first element of the array
        int maxsum = nums[0];
        int currsum = 0;

        for(int num : nums){
           // Either add current number to existing sum or start fresh with num
            currsum = max(num , currsum + num );
            // Update global maximum if currentSum is better
            maxsum = max(maxsum , currsum);
        }

        return maxsum;
    }
};
```

---

### 📝 Dry Run Example  

**Input:**
```
nums = [-2,1,-3,4,-1,2,1,-5,4]
```

**Step-by-step:**
- Start: maxsum = -2, currsum = 0  
- num = -2 → currsum = -2, maxsum = -2  
- num = 1 → currsum = 1, maxsum = 1  
- num = -3 → currsum = -2, maxsum = 1  
- num = 4 → currsum = 4, maxsum = 4  
- num = -1 → currsum = 3, maxsum = 4  
- num = 2 → currsum = 5, maxsum = 5  
- num = 1 → currsum = 6, maxsum = 6  
- num = -5 → currsum = 1, maxsum = 6  
- num = 4 → currsum = 5, maxsum = 6  

**Output:**
```
6
```
(Subarray `[4,-1,2,1]` has sum = 6)

---

### 📊 Complexity  
- **Time Complexity:** O(n) → single pass through array  
- **Space Complexity:** O(1) → constant extra space  

---

### 🔗 Practice Links  
- [LeetCode: Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)  
- [GeeksforGeeks: Largest Sum Contiguous Subarray](https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/)  
- [Coding Ninjas: Maximum Subarray](https://www.codingninjas.com/studio/problems/maximum-subarray_1468368)  

---

# 15.  Remove K Digits

**Difficulty:** 🟡 Medium  
**Tags:** Stack, Greedy, String  

---

### 🧩 Problem Statement  
Given a string `nums` representing a non‑negative integer and an integer `k`, remove `k` digits from the number so that the new number is the **smallest possible**.  

Return the result as a string (without leading zeros).  

---

### 💡 Approach (Monotonic Stack)  
1. Use a stack to maintain digits in **increasing order**.  
2. Traverse each digit in `nums`:  
   - While stack not empty, `k > 0`, and top digit > current digit → pop (remove larger digit).  
   - Push current digit.  
3. If `k > 0` after traversal, remove remaining digits from stack.  
4. Build result string from stack.  
5. Trim leading zeros.  
6. Reverse the string (since stack pops in reverse order).  
7. If result empty → return `"0"`.  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution {
public:
    string removeKdigits(string nums, int k) {
          stack<char> st;

          for(int i = 0; i<nums.size(); i++){
            while(!st.empty() && k >0 && st.top() > nums[i]){
                st.pop();
                k--;
            }
            st.push(nums[i]);
          }

          while(!st.empty() && k >0){
            st.pop();
            k--;
          }

          if(st.empty()) return "0";

          string res = "";

          while(!st.empty()){
            res.push_back(st.top());
            st.pop();
          }
         // trimming zeroes at the back
          while(res.size() >0 && res.back() == '0'){
            res.pop_back();
          }
          // reverse number
          reverse(res.begin() , res.end());

          if(res.empty()) return "0";

          return res;
    }
};
```

---

### 📝 Input & Output Example  

**Input:**  
```
nums = "1432219", k = 3
```

**Step-by-step:**  
- Remove digits greedily → smallest number = `"1219"`  

**Output:**  
```
"1219"
```

---

### 📊 Complexity  
- **Time Complexity:** O(n) → each digit pushed/popped at most once  
- **Space Complexity:** O(n) → stack + result string  

---

### 🔗 Practice Links  
- LeetCode: Remove K Digits [(leetcode.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fleetcode.com%2Fproblems%2Fremove-k-digits%2F")  
- GeeksforGeeks: Remove K Digits [(geeksforgeeks.org in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.geeksforgeeks.org%2Fremove-k-digits%2F")  
- Coding Ninjas: Remove K Digits [(codingninjas.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.codingninjas.com%2Fstudio%2Fproblems%2Fremove-k-digits_1468364")  

---

# 16 Min Stack

**Difficulty:** 🟡 Medium  
**Tags:** Stack, Design, Data Structure  

---

### 🧩 Problem Statement  
Design a stack that supports the following operations in **O(1)** time:  
- `push(x)` → Push element `x` onto stack.  
- `pop()` → Remove the top element.  
- `top()` → Get the top element.  
- `getMin()` → Retrieve the minimum element in the stack.  

---

### 💡 Approach (Stack of Pairs)  
- Each stack entry stores a **pair**:  
  - `{value, currentMin}`  
- When pushing:  
  - If stack empty → push `{value, value}`.  
  - Else → push `{value, min(value, st.top().second)}`.  
- When popping → remove top pair.  
- `top()` → return `st.top().first`.  
- `getMin()` → return `st.top().second`.  

This ensures that at every level of the stack, we know the minimum up to that point.

---

### 💻 Your Code (Unchanged)

```cpp
class MinStack {
  private:
  stack <pair<int, int>> st;

public:
    MinStack() {
   
    }

  void push(int value) {
     if(st.empty()){
        st.push({value , value});
     }
    else{
      st.push({value ,min(value , st.top().second)});
    }
  }

  void pop() {
    if(!st.empty()){
      st.pop();
    }
  }

  int top() {
     return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};
```

---

### 📝 Input & Output Example  

**Input:**  
```
MinStack minStack;
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   // returns -3
minStack.pop();
minStack.top();      // returns 0
minStack.getMin();   // returns -2
```

**Output:**  
```
-3
0
-2
```

---

### 📊 Complexity  
- **Time Complexity:** O(1) for all operations (push, pop, top, getMin)  
- **Space Complexity:** O(n) → stack stores all elements with their min values  

---

### 🔗 Practice Links  
- [LeetCode: Min Stack](https://leetcode.com/problems/min-stack/)  
- GeeksforGeeks: Design a Min Stack [(geeksforgeeks.org in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.geeksforgeeks.org%2Fdesign-and-implement-special-stack-data-structure%2F")  
- Coding Ninjas: Min Stack [(codingninjas.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.codingninjas.com%2Fstudio%2Fproblems%2Fmin-stack_1468362")  

---


# 17 Sliding Window Maximum

**Difficulty:** 🔴 Hard  
**Tags:** Monotonic Queue, Deque, Sliding Window  

---

### 🧩 Problem Statement  
Given an array `arr[]` of size `n` and an integer `k`, return the maximum value in every contiguous subarray (window) of size `k`.

---

### 💡 Approach (Monotonic Deque)  
1. Use a **deque** to store indices of elements in decreasing order of values.  
2. For each index `i`:  
   - Remove indices from the **front** if they are out of the current window (`<= i-k`).  
   - Remove indices from the **back** while the current element is greater than or equal to the element at those indices (maintains decreasing order).  
   - Push current index into deque.  
   - If `i >= k-1`, the front of deque is the maximum for the current window.  
3. Collect results into `ans`.  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k) {
        int n = arr.size();

        vector<int> ans;
        deque<int> dq;

        for(int i =0;i<n ; i++){
            if(!dq.empty() && dq.front() <= (i-k)){
                dq.pop_front();
            }

            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= (k-1)){
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans;
    }
};
```

---

### 📝 Input & Output Example  

**Input:**  
```
arr = [1,3,-1,-3,5,3,6,7], k = 3
```

**Step-by-step windows:**  
- [1,3,-1] → max = 3  
- [3,-1,-3] → max = 3  
- [-1,-3,5] → max = 5  
- [-3,5,3] → max = 5  
- [5,3,6] → max = 6  
- [3,6,7] → max = 7  

**Output:**  
```
[3,3,5,5,6,7]
```

---

### 📊 Complexity  
- **Time Complexity:** O(n) → each element pushed/popped at most once  
- **Space Complexity:** O(k) → deque stores indices of current window  

---

### 🔗 Practice Links  
- LeetCode: Sliding Window Maximum [(leetcode.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fleetcode.com%2Fproblems%2Fsliding-window-maximum%2F")  
- GeeksforGeeks: Sliding Window Maximum [(geeksforgeeks.org in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.geeksforgeeks.org%2Fsliding-window-maximum-maximum-of-all-subarrays-of-size-k%2F")  
- Coding Ninjas: Sliding Window Maximum [(codingninjas.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.codingninjas.com%2Fstudio%2Fproblems%2Fsliding-window-maximum_1468361")  

---

# 18 Trapping Rain Water

**Difficulty:** 🔴 Hard  
**Tags:** Array, Prefix/Suffix, Two-Pointer  

---

### 🧩 Problem Statement  
Given `n` non‑negative integers representing an elevation map where the width of each bar is 1, compute how much water can be trapped after raining.

---

### 💡 Approach (Prefix & Suffix Max Arrays)  
1. Create two arrays:  
   - `lmax[i]` → maximum height to the **left** of index `i`.  
   - `rmax[i]` → maximum height to the **right** of index `i`.  
2. Traverse the array:  
   - Fill `lmax` from left to right.  
   - Fill `rmax` from right to left.  
3. For each index `i`:  
   - Water trapped = `min(lmax[i], rmax[i]) - height[i]`.  
   - Add to total answer.  
4. Return the total trapped water.  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution
{
public:
    int trap(vector<int> &height){
        int n = height.size();
        vector<int> lmax(n ,0);
        vector<int> rmax(n ,0);

        lmax[0] =  height[0];
        rmax[n-1] =  height[n-1];

        for(int i = 1 ; i<n ; i++){
           lmax[i] = max(lmax[i-1] , height[i]);
        }

        for(int i= n-2 ; i >=0 ;i--){
            rmax[i] = max(rmax[i+1] , height[i]);
        }

        int ans = 0;

        for(int i = 0; i <n ;  i++){
            ans += min(lmax[i], rmax[i])- height[i];
        }

        return ans;
    }
};
```

---

### 📝 Input & Output Example  

**Input:**  
```
height = [0,1,0,2,1,0,1,3,2,1,2,1]
```

**Step-by-step water trapped:**  
- At index 2 → min(1,2) - 0 = 1  
- At index 5 → min(2,3) - 0 = 2  
- At index 6 → min(2,3) - 1 = 1  
- At index 8 → min(3,2) - 2 = 0  
- At index 9 → min(3,2) - 1 = 1  
- At index 10 → min(3,2) - 2 = 0  

**Total = 6 units of water**

**Output:**  
```
6
```

---

### 📊 Complexity  
- **Time Complexity:** O(n) → three traversals of the array  
- **Space Complexity:** O(n) → extra arrays `lmax` and `rmax`  

👉 Optimized two‑pointer solution reduces space to O(1).

---

### 🔗 Practice Links  
- LeetCode: Trapping Rain Water [(leetcode.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fleetcode.com%2Fproblems%2Ftrapping-rain-water%2F")  
- GeeksforGeeks: Trapping Rain Water [(geeksforgeeks.org in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.geeksforgeeks.org%2Ftrapping-rain-water%2F")  
- Coding Ninjas: Trapping Rain Water [(codingninjas.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.codingninjas.com%2Fstudio%2Fproblems%2Ftrapping-rain-water_1468360")  

---

# 19 Largest Rectangle in Histogram

**Difficulty:** 🔴 Hard  
**Tags:** Stack, Monotonic Stack, Histogram  

---

### 🧩 Problem Statement  
Given an array `heights[]` representing the heights of bars in a histogram, find the area of the **largest rectangle** that can be formed inside the histogram.

---

### 💡 Approach (Left & Right Smaller Elements)  
1. For each bar, find the **nearest smaller element to the left** (`left[i]`).  
2. For each bar, find the **nearest smaller element to the right** (`right[i]`).  
3. The width of the rectangle at index `i` = `right[i] - left[i] - 1`.  
4. Area at index `i` = `heights[i] * width`.  
5. Take the maximum over all indices.  

👉 This uses **monotonic stack** to compute left and right smaller efficiently.

---

### 💻 Your Code (Unchanged)

```cpp
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights) {
     
     int n = heights.size();
     vector<int> left(n , 0);
     vector<int> right(n , 0);
     stack<int> st;

     // right smaller element
     for(int i = n-1 ; i >= 0; i--){
        while(st.size() > 0 && heights[st.top()] >= heights[i]){
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
     }
     
     while(!st.empty()){
        st.pop();
     }
     
     // left smaller element
     for(int i = 0 ; i <n ; i++){
        while(st.size() > 0 && heights[st.top()] >= heights[i]){
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
     }

     int ans = 0;
     for(int i =0 ; i <n ; i++){
        int width =  right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans , currArea);
     }

     return ans;
    }
};
```

---

### 📝 Input & Output Example  

**Input:**  
```
heights = [2,1,5,6,2,3]
```

**Step-by-step:**  
- For bar at index 2 (height=5):  
  - left smaller = index 1 (height=1)  
  - right smaller = index 4 (height=2)  
  - width = 4 - 1 - 1 = 2  
  - area = 5 × 2 = 10  

- For bar at index 3 (height=6):  
  - left smaller = index 1  
  - right smaller = index 4  
  - width = 4 - 1 - 1 = 2  
  - area = 6 × 2 = 12  

**Maximum area = 12**

**Output:**  
```
12
```

---

### 📊 Complexity  
- **Time Complexity:** O(n) → each element pushed/popped at most once  
- **Space Complexity:** O(n) → arrays `left`, `right`, and stack  

---

### 🔗 Practice Links  
- LeetCode: Largest Rectangle in Histogram [(leetcode.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fleetcode.com%2Fproblems%2Flargest-rectangle-in-histogram%2F")  
- GeeksforGeeks: Largest Rectangle in Histogram [(geeksforgeeks.org in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.geeksforgeeks.org%2Flargest-rectangle-in-histogram%2F")  
- Coding Ninjas: Largest Rectangle in Histogram [(codingninjas.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.codingninjas.com%2Fstudio%2Fproblems%2Flargest-rectangle-in-histogram_1468365")  

---



# 20 Maximal Rectangle in a Binary Matrix (Maximum Rectangle)

**Difficulty:** 🔴 Hard  
**Tags:** Matrix, Histogram, Monotonic Stack  

---

### 🧩 Problem Statement  
Given a binary matrix filled with `0`s and `1`s, find the area of the **largest rectangle containing only 1s**.

---

### 💡 Approach (Histogram Extension)  
1. Treat each row of the matrix as the **base of a histogram**.  
2. Maintain an array `heights[]` of size `m` (columns):  
   - If `matrix[i][j] == 1` → increment `heights[j]`.  
   - If `matrix[i][j] == 0` → reset `heights[j] = 0`.  
3. For each row, compute the **largest rectangle area in histogram** using monotonic stack (left & right smaller elements).  
4. Keep track of the maximum area across all rows.  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution
{
private:
    
    int largestRectangleArea(vector<int> & heights){

        int n = heights.size();

       vector<int> left(n , 0);
       vector<int> right(n ,0);
       stack<int> st;

       // right smallest element
       for(int i = n-1 ; i >= 0 ; i--){
         while(st.size() >0 && heights[st.top()] >= heights[i]){
            st.pop();
         }
         right[i] = st.empty() ? n : st.top();
         st.push(i);
       }
        while(!st.empty()){
            st.pop();
        }
        // left smallest element
         for(int i = 0 ; i < n ; i++){
         while(st.size() >0 && heights[st.top()] >= heights[i]){
            st.pop();
         }
         left[i] = st.empty() ? -1 : st.top();
         st.push(i);
       }

       int ans = 0;

       for(int i =0 ; i<n ; i++){
        int width = right[i] - left[i] -1;
        int currSum = heights[i] * width;

         ans = max(ans , currSum);
       }

       return ans;
    }   

public:
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
       
       int n = matrix.size();
       int m = matrix[0].size();

       vector<int> heights(m , 0);
       int maxArea = 0;

       for(int i = 0; i<n ; i++ ){
        for(int j = 0 ; j<m ; j++){
            if(matrix[i][j] ==0 ) 
               heights[j] =0;
            else
            heights[j]++;
        }

        maxArea = max(maxArea , largestRectangleArea(heights));
       }
       return maxArea;
    }
};
```

---

### 📝 Input & Output Example  

**Input Matrix:**  
```
matrix = [
  [1,0,1,0,0],
  [1,0,1,1,1],
  [1,1,1,1,1],
  [1,0,0,1,0]
]
```

**Step-by-step:**  
- Row 0 → heights = [1,0,1,0,0] → max area = 1  
- Row 1 → heights = [2,0,2,1,1] → max area = 3  
- Row 2 → heights = [3,1,3,2,2] → max area = 6  
- Row 3 → heights = [4,0,0,3,0] → max area = 4  

**Output:**  
```
6
```

---

### 📊 Complexity  
- **Time Complexity:** O(n × m) → each row processed with histogram logic  
- **Space Complexity:** O(m) → heights array + stack  

---

### 🔗 Practice Links  
- LeetCode: Maximal Rectangle [(leetcode.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fleetcode.com%2Fproblems%2Fmaximal-rectangle%2F")  
- GeeksforGeeks: Maximal Rectangle in Binary Matrix [(geeksforgeeks.org in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.geeksforgeeks.org%2Fmaximum-size-rectangle-binary-sub-matrix-1s%2F")  
- Coding Ninjas: Maximal Rectangle [(codingninjas.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.codingninjas.com%2Fstudio%2Fproblems%2Fmaximal-rectangle_1468366")  

---


# 2️⃣1️⃣ Stock Span Problem

**Difficulty:** 🟡 Medium  
**Tags:** Stack, Monotonic Stack, Array  

---

### 🧩 Problem Statement  
Given an array `arr[]` of size `n` representing the price of stocks for `n` days, the **stock span** for a day is defined as the maximum number of consecutive days just before that day (including the current day) for which the price of the stock is less than or equal to its price on the current day.  

Return an array `span[]` where `span[i]` is the stock span for day `i`.

---

### 💡 Approach (Monotonic Stack)  
1. Use a stack to store **indices** of days.  
2. For each day `i`:  
   - Pop from stack while the top’s price ≤ current price.  
   - If stack empty → span[i] = i+1 (all previous days are smaller).  
   - Else → span[i] = i - st.top() (distance from last greater element).  
3. Push current index onto stack.  
4. Return the span array.  

---

### 💻 Your Code (Unchanged)

```cpp
class Solution
{
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
       
       stack<int> st;
       vector<int> span(n);

       for(int i = 0 ;i <n; i++){
        while(st.size() >0 && arr[st.top()] <= arr[i] ){
            st.pop();
        }
        
        // if greater element is not found then return current original index 
        if(st.empty()){
            span[i] =  i+1;
        }
        else{
            span[i] = i - st.top(); // i - previousHigh
        }

        st.push(i);
       }

       return span;
    }
};
```

---

### 📝 Input & Output Example  

**Input:**  
```
arr = [100, 80, 60, 70, 60, 75, 85], n = 7
```

**Step-by-step spans:**  
- Day 0 → 100 → span = 1  
- Day 1 → 80 → span = 1  
- Day 2 → 60 → span = 1  
- Day 3 → 70 → span = 2 (70 ≥ 60)  
- Day 4 → 60 → span = 1  
- Day 5 → 75 → span = 4 (75 ≥ 60,70,60)  
- Day 6 → 85 → span = 6 (85 ≥ 75,60,70,60,80)  

**Output:**  
```
[1, 1, 1, 2, 1, 4, 6]
```

---

### 📊 Complexity  
- **Time Complexity:** O(n) → each element pushed/popped at most once  
- **Space Complexity:** O(n) → stack + span array  

---

### 🔗 Practice Links  
- [LeetCode Discuss: Stock Span Variants](https://leetcode.com/tag/stack/)  
- GeeksforGeeks: Stock Span Problem [(geeksforgeeks.org in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.geeksforgeeks.org%2Fthe-stock-span-problem%2F")  
- Coding Ninjas: Stock Span Problem [(codingninjas.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.codingninjas.com%2Fstudio%2Fproblems%2Fstock-span-problem_1112582")  

---


# 22 Celebrity Problem

**Difficulty:** 🟡 Medium  
**Tags:** Matrix, Two-Pointer, Simulation  

---

### 🧩 Problem Statement  
In a party of `n` people, a **celebrity** is defined as:  
1. Everyone knows the celebrity.  
2. The celebrity knows no one.  

Given a matrix `M` of size `n × n` where:  
- `M[i][j] = 1` → person `i` knows person `j`.  
- `M[i][j] = 0` → person `i` does not know person `j`.  

Find the celebrity’s index or return `-1` if no celebrity exists.

---

### 💡 Approach (Two-Pointer Elimination + Verification)  
1. Start with two pointers: `top = 0`, `down = n-1`.  
2. While `top < down`:  
   - If `top` knows `down` → `top` cannot be celebrity → move `top++`.  
   - Else if `down` knows `top` → `down` cannot be celebrity → move `down--`.  
   - Else → both eliminated → move both.  
3. After loop, candidate = `top`.  
4. Verify candidate:  
   - Candidate should not know anyone (`M[top][i] == 0`).  
   - Everyone should know candidate (`M[i][top] == 1`).  
5. If all checks pass → return candidate index, else return `-1`.

---

### 💻 Your Code (Unchanged)

```cpp
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();

        // top and down pointer 
        int top = 0;
        int down = n-1; 
        
        // Traverse for all the people
        while(top < down){
            if(M[top][down] == 1 ){
                top = top+1;
            }
            else if(M[down][top] == 1){
                down = down -1;
            }
            else{
              top ++;
              down --;
            }
        }

        if(top > down ) return -1;

        for(int i = 0; i < n ; i++){
            if(i == top) continue; // skip self check
            if(M[top][i] == 1 || M[i][top] == 0){
                return -1;
            }
        }

        return top;
    }
};
```

---

### 📝 Input & Output Example  

**Input Matrix:**  
```
M = [
  [0,1,1],
  [0,0,1],
  [0,0,0]
]
```

**Explanation:**  
- Person 0 knows 1 and 2 → not celebrity.  
- Person 1 knows 2 → not celebrity.  
- Person 2 knows no one, and everyone knows 2 → celebrity.  

**Output:**  
```
2
```

---

### 📊 Complexity  
- **Time Complexity:** O(n) → elimination + verification  
- **Space Complexity:** O(1) → only pointers used  

---

### 🔗 Practice Links  
- [LeetCode Discuss: Celebrity Problem](https://leetcode.com/tag/stack/)  
- GeeksforGeeks: Celebrity Problem (geeksforgeeks.org in Bing) [(bing.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.bing.com%2Fsearch%3Fq%3D%2522https%253A%252F%252Fwww.geeksforgeeks.org%252Fthe-celebrity-problem%252F%2522")  
- Coding Ninjas: Celebrity Problem (codingninjas.com in Bing) [(bing.com in Bing)](https://www.bing.com/search?q="https%3A%2F%2Fwww.bing.com%2Fsearch%3Fq%3D%2522https%253A%252F%252Fwww.codingninjas.com%252Fstudio%252Fproblems%252Fthe-celebrity-problem_1112620%2522")  

---
