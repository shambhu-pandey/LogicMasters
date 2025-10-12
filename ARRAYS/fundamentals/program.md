# 🚀 DSA Problem Set

Welcome to the **DSA Problem Set**!
This collection contains common problems with solutions in **C++**.
Each problem includes **examples, explanation, solution, and complexity analysis**.

---

## 📑 Table of Contents

1. [🔍 Linear Search](#1--linear-search)
2. [🔝 Largest Element](#2--largest-element)
3. [🥈 Second Largest Element](#3--second-largest-element)
4. [1️⃣ Maximum Consecutive Ones](#4--maximum-consecutive-ones)
5. [⬅️ Left Rotate Array by One](#5--left-rotate-array-by-one)
6. [⬅️ Left Rotate Array k place](#6--left-rotate-array-k-place)]
7. [🔍 Binary Search](#1--Binary-search)
---

# 1. 🔍 Linear Search

**Difficulty:** 🟢 Easy
**Asked in:** TCS, Wipro, Infosys, Accenture
**Tags:** Array, Searching

### 👉 Problem Statement

Given an array of integers `nums` and an integer `target`, find the **smallest index (0-based indexing)** where the target appears in the array. If the target is not found in the array, return `-1`.

---

### ✅ Examples

**Example 1:**

```
Input: nums = [2, 3, 4, 5, 3], target = 3
Output: 1
Explanation: The first occurrence of 3 in nums is at index 1.
```

**Example 2:**

```
Input: nums = [2, -4, 4, 0, 10], target = 6
Output: -1
Explanation: The value 6 does not occur in the array.
```

**Example 3:**

```
Input: nums = [1, 3, 5, -4, 1], target = 1
Output: 0
```

---

### 💻 Solution (C++)

```cpp
class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return i;  // return first occurrence
        }
        return -1; // if not found
    }
};
```

---

### 📊 Complexity Analysis

* **Time Complexity:** O(n) → single pass through the array
* **Space Complexity:** O(1) → no extra space used

---

**Lecture Slides:** [View Slides](https://drive.google.com/file/d/1yR9Rh5ptmFDw0kPL_mcNH6L34wUdorCE/view)



# 2. 🔝 Largest Element

**Difficulty:** 🟢 Easy
**Asked in:** TCS, Infosys, Wipro, HCLTech, Tech Mahindra, Accenture
**Tags:** Array, Iteration

### 👉 Problem Statement

Given an array of integers `nums`, return the **value of the largest element** in the array.

---

### ✅ Examples

**Example 1:**

```
Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in the array is 6.
```

**Example 2:**

```
Input: nums = [3, 3, 0, 99, -40]
Output: 99
Explanation: The largest element in the array is 99.
```

**Example 3:**

```
Input: nums = [-10, -5, -3, -1]
Output: -1
Explanation: The largest element among negatives is -1.
```

---

### 💻 Solution (C++)

```cpp
class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largest = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > largest) largest = nums[i];  // update largest
        }
        return largest;
    }
};
```

---

### 📊 Complexity Analysis

* **Time Complexity:** O(n) → single pass through the array
* **Space Complexity:** O(1) → no extra space used

---

# 3. 🥈 Second Largest Element

**Difficulty:** 🟢 Easy
**Asked in:** Common Coding Interviews
**Tags:** Array, Iteration

### 👉 Problem Statement

Given an array of integers `nums`, return the **second-largest element** in the array. If the second-largest element does not exist, return `-1`.

---

### ✅ Examples

**Example 1:**

```
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation: The largest value in nums is 8, the second largest is 7.
```

**Example 2:**

```
Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation: No second-largest element exists.
```

---

### 💻 Solution (C++)

```cpp
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int largest = nums[0];
        int secondLargest = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > largest) largest = nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != largest && nums[i] > secondLargest) secondLargest = nums[i];
        }

        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }
};
```

---

### 📊 Complexity Analysis

* **Time Complexity:** O(n) → two passes through the array
* **Space Complexity:** O(1) → no extra space used

---

# 4. 1️⃣ Maximum Consecutive Ones

**Difficulty:** 🟢 Easy
**Asked in:** Common Coding Interviews
**Tags:** Array, Binary Array

### 👉 Problem Statement

Given a binary array `nums`, return the **maximum number of consecutive 1s** in the array.
A binary array is an array that contains only 0s and 1s.

---

### ✅ Examples

**Example 1:**

```
Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]
Output: 3
Explanation: The maximum consecutive 1s are from index 4 to index 6.
```

**Example 2:**

```
Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]
Output: 0
Explanation: No 1s are present in nums.
```

---

### 💻 Solution (C++)

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxi = max(maxi, count);
            } else {
                count = 0;
            }
        }
        return maxi;
    }
};
```

---

### 📊 Complexity Analysis

* **Time Complexity:** O(n) → single pass through the array
* **Space Complexity:** O(1) → no extra space used

---

# 5. ⬅️ Left Rotate Array by One

**Difficulty:** 🟢 Easy
**Asked in:** Common Coding Interviews
**Tags:** Array, Rotation

### 👉 Problem Statement

Given an integer array `nums`, rotate the array to the left by one.
**Note:** Modify the given array in-place.

---

### ✅ Examples

**Example 1:**

```
Input: nums = [1, 2, 3, 4, 5]
Output: [2, 3, 4, 5, 1]
Explanation: Rotating once to the left moves the first element to the end.
```

**Example 2:**

```
Input: nums = [-1, 0, 3, 6]
Output: [0, 3, 6, -1]
Explanation: Rotating once to the left moves the first element to the end.
```

---

### 💻 Solution (C++)

```cpp
class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
     
     int temp = nums[0];
     int n = nums.size();

     for(int i = 1 ; i<n ; i++){
        nums[i-1]=nums[i];
     }
     nums[n-1] = temp;
    }
};


//time complexity : O(N)
//space complexity : o(1) // because we are using extra space here temp
```

---

### 📊 Complexity Analysis

* **Time Complexity:** O(n) → single pass through the array
* **Space Complexity:** O(1) → no extra space used

---

# 6. ⬅️ Left Rotate Array by K Places

**Difficulty:** 🟢 Easy
**Tags:** Array, Rotation

### 🛠 Problem Statement

Given an integer array `nums` and a non-negative integer `k`, rotate the array to the **left by k steps**.

---

### ✅ Examples

**Example 1:**

```
Input: nums = [1, 2, 3, 4, 5, 6], k = 2
Output: [3, 4, 5, 6, 1, 2]
Explanation:
rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]
```

**Example 2:**

```
Input: nums = [3, 4, 1, 5, 3, -5], k = 8
Output: [1, 5, 3, -5, 3, 4]
Explanation:
rotate 1 step to the left: [4, 1, 5, 3, -5, 3]
rotate 2 steps to the left: [1, 5, 3, -5, 3, 4]
rotate 3 steps to the left: [5, 3, -5, 3, 4, 1]
rotate 4 steps to the left: [3, -5, 3, 4, 1, 5]
rotate 5 steps to the left: [-5, 3, 4, 1, 5, 3]
rotate 6 steps to the left: [3, 4, 1, 5, 3, -5]
rotate 7 steps to the left: [4, 1, 5, 3, -5, 3]
rotate 8 steps to the left: [1, 5, 3, -5, 3, 4]
```

---

### 💻 Solution (C++)

```cpp
class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // handle k greater than array size
        vector<int> temp;

        // Store first k elements in a temporary array
        for(int i = 0; i < k; i++){
            temp.push_back(nums[i]);
        }

        // Shift n-k elements of given array to the front
        for(int i = k; i < n; i++){
            nums[i - k] = nums[i];
        }

        // Copy back the k elements at the end
        for(int i = 0; i < k; i++){
            nums[n - k + i] = temp[i];
        }
    }
};
```

---

### 📊 Complexity Analysis

* **Time Complexity:** O(n) → two passes through the array
* **Space Complexity:** O(k) → temporary array of size k used


# binary search
---
```
#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[] ,int n , int key){
    
    for(int i = 0 ; i<n ; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
int n;
    cout<<"enter n:";
    cin>>n;

    int arr[n];
    for(int i = 0 ; i<n ;i++){
        cin>>arr[i];
    }
    
    int key;
    cout<<"eneter element you want to find:";
    cin>>key;

    int index = linearSearch(arr , n , key);
    cout<<"index of key is :"<<index;
}
```
