# 📑 Array Problem Set in C++

Welcome to the Array Problem Set!  
This collection includes common array problems solved in C++, with explanations, examples, solutions, and complexity analysis.  
It’s designed to be examiner-friendly and practice-ready.

---

## 🔗 Practice index

| # | Title | What | Complexity | Quick links |
|---|---|---|---|---|
| 1️⃣ | 🔝 Largest and Smallest Element | Max/Min | O(n) | [GFG / CN](#1-largest-and-smallest-element) |
| 2️⃣ | 📐 Scope in Array (Function Update) | Pass-by-ref | O(n) | [GFG](#2-scope-in-array-function-update) |
| 3️⃣ | ➕ Sum of Array Elements | Sum | O(n) | [GFG / CN](#3-sum-of-array-elements) |
| 4️⃣ | ⚡ Power of 2 Check | Presence | O(1) | [L: 231 / GFG / CN](#4-power-of-2-check) |
| 5️⃣ | 🔄 Reverse an Array | Reverse print | O(n) | [GFG / CN](#5-reverse-an-array) |
| 6️⃣ | 🔄 Swap Alternate Elements | Pair swap | O(n) | [GFG / CN](#6-swap-alternate-elements-in-array) |
| 7️⃣ | 🔎 Find Unique Element (XOR) | Single number | O(N) | [L: 136 / GFG / CN](#7-find-unique-element-in-array-xor) |
| 8️⃣ | 🔎 Unique Number of Occurrences | Frequency uniqueness | O(N) | [L: 1207 / GFG](#8-unique-number-of-occurrences) |
| 9️⃣ | 🔁 Find All Duplicates | Duplicates list | O(N) | [L: 442 / GFG](#9-find-all-duplicates-in-an-array) |
| 🔟 | 🔗 Array Intersection | Two pointers | O(N+M) | [L: 350 / GFG](#10-find-array-intersection) |
| 1️⃣1️⃣ | 🔗 Pair Sum | Two-sum pairs | O(n²) | [L: 167 / GFG / CN](#11-pair-sum) |
| 1️⃣2️⃣ | 🔗 Triplet Sum | Three-sum triplets | O(n³) / O(n²) | [L: 15 / GFG / CN](#12-triplet-sum) |
| 1️⃣3️⃣ | 🔄 Sort 0s, 1s, and 2s | Dutch National Flag | O(n) | [L: 75 / GFG / CN](#13-sort-0s-1s-and-2s) |

---

## 📋 Table of contents

1. 🔝 Largest and smallest element  
2. 📐 Scope in array (function update)  
3. ➕ Sum of array elements  
4. ⚡ Power of 2 check  
5. 🔄 Reverse an array  
6. 🔄 Swap alternate elements in array  
7. 🔎 Find unique element in array (XOR)  
8. 🔎 Unique number of occurrences  
9. 🔁 Find all duplicates in an array  
10. 🔗 Find array intersection  
11. 🔗 Pair Sum  
12. 🔗 Triplet Sum  
13. 🔄 Sort 0s, 1s, and 2s  

---


## 🔗 Practice links (all problems)

- GeeksforGeeks: https://www.geeksforgeeks.org/arrays-in-c-cpp/  
- LeetCode: https://leetcode.com/tag/array/  
- Coding Ninjas: https://www.codingninjas.com/studio/problems?topic=Arrays
---

# 1. 🔝 Largest and smallest element

**Difficulty:** 🟢 Easy  
**Tags:** Array, Iteration  

### 🧩 Problem Statement  
Find the largest and smallest element in a given array.

### ✅ Example
```
Input: arr = [4, 12, 8, 10]
Output: Largest = 12, Smallest = 4
```

### 💻 Solution (C++)
```cpp
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[4] = {4, 12, 8, 10};
    int n = sizeof(arr)/sizeof(int);

    int max = INT_MIN;
    int min = INT_MAX;

    for(int i = 0; i < n; i++){
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    cout << "Max is: " << max << endl;
    cout << "Min is: " << min << endl;
    return 0;
}
```

### 📊 Complexity Analysis  
- Time Complexity: O(n)  
- Space Complexity: O(1)

---

# 2. 📐 Scope in array (function update)

**Difficulty:** 🟢 Easy  
**Tags:** Array, Functions  

### 🧩 Problem Statement  
Demonstrate how arrays are passed by reference to functions in C++.

### ✅ Example
```
Input: arr = [1, 2, 3, 4], n = 4
Output: After update → [1, 2, 100, 4]
```

### 💻 Solution (C++)
```cpp
#include<iostream>
using namespace std;

void update_func(int arr[], int n){
    arr[2] = 100;
    cout << "After array update: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[100], n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "Original array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    update_func(arr, n);

    cout << "After function call: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
```

### 📊 Complexity Analysis  
- Time Complexity: O(n)  
- Space Complexity: O(1)

---

# 3. ➕ Sum of array elements

**Difficulty:** 🟢 Easy  
**Tags:** Array, Summation  

### 🧩 Problem Statement  
Find the sum of all elements in an array.

### ✅ Example
```
Input: arr = [1, 2, 3, 4, 5]
Output: Sum = 15
```

### 💻 Solution (C++)
```cpp
#include<iostream>
using namespace std;

void sumArray(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    cout << "Sum is: " << sum << endl;
}

int main(){
    int arr[100], n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sumArray(arr, n);
    return 0;
}
```

### 📊 Complexity Analysis  
- Time Complexity: O(n)  
- Space Complexity: O(1)

---

# 4. ⚡ Power of 2 check

**Difficulty:** 🟡 Medium  
**Tags:** Array, Math  

### 🧩 Problem Statement  
Check if a given number `N` is a power of 2 using precomputed array values.

### ✅ Example
```
Input: N = 16
Output: Element present (since 16 is a power of 2)
```

### 💻 Solution (C++)
```cpp
#include<iostream>
using namespace std;

int main(){
    int arr[30];
    int n;
    cin >> n;

    for(int i = 0; i < 30; i++){
        arr[i] = 2 << i; // powers of 2
    }

    bool found = false;
    for(int i = 0; i < 30; i++){
        if(arr[i] == n){
            found = true;
            break;
        }
    }

    if(found) cout << "Element present" << endl;
    else cout << "Not found" << endl;

    return 0;
}
```

### 📊 Complexity Analysis  
- Time Complexity: O(30) ≈ O(1)  
- Space Complexity: O(30) ≈ O(1)

---

# 5. 🔄 Reverse an array

**Difficulty:** 🟢 Easy  
**Tags:** Array, Iteration  

### 🧩 Problem Statement  
Print the elements of an array in reverse order.

### ✅ Example
```
Input: arr = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
```

### 💻 Solution (C++)
```cpp
#include<iostream>
using namespace std;

int main(){
    int arr[100], n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "Reverse order: ";
    for(int i = n-1; i >= 0; i--){
        cout << arr[i] << " ";
    }
    return 0;
}
```

### 📊 Complexity Analysis  
- Time Complexity: O(n)  
- Space Complexity: O(1)

---

![alt text](image-1.png)

# 6. 🔄 Swap alternate elements in array

**Difficulty:** 🟢 Easy  
**Tags:** Array, Iteration, Swapping  

---

### 🧩 Problem Statement  
Given an array of integers, swap every pair of alternate elements.  
- For even-sized arrays, all elements are swapped in pairs.  
- For odd-sized arrays, the last element remains unchanged.

---

### ✅ Examples

**Example 1 (Even length):**
```
Input: arr = [1, 2, 3, 4, 5, 6, 7, 8]
Output: [2, 1, 4, 3, 6, 5, 8, 7]
```

**Example 2 (Odd length):**
```
Input: arr = [5, 6, 7, 8, 9]
Output: [6, 5, 8, 7, 9]
```

---

### 💻 Solution (C++)

```cpp
#include <iostream>
using namespace std;

void printarray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void swapalternate(int arr[], int size) {
    for(int i = 0; i < size; i += 2) {
        if(i + 1 < size) {
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int even[8] = {1,2,3,4,5,6,7,8};
    int odd[5] = {5,6,7,8,9};

    swapalternate(even, 8);
    cout << "Even array after swap: ";
    printarray(even, 8);

    swapalternate(odd, 5);
    cout << "Odd array after swap: ";
    printarray(odd, 5);

    return 0;
}
```

---

### 📊 Complexity Analysis  
- **Time Complexity:** O(n) → single pass through the array  
- **Space Complexity:** O(1) → in-place swapping  

---

### 🔗 Practice Links  
- [GeeksforGeeks: Swap alternate elements](https://www.geeksforgeeks.org/swap-elements-in-an-array/)  
- [CodeStudio: Swap alternate elements](https://www.codingninjas.com/studio/problems/swap-alternate-elements_1234567)  

---

Got it, Shambhu! Here’s a short and clean Markdown version of the Unique Element in Array problem using XOR:

# 7. 🔎 Find unique element in array (XOR)

```markdown
# 🔎 Find Unique Element in Array

**Problem:**  
Given an array of size `N = 2M + 1` where `M` numbers appear twice and one number appears once, find the unique element.

---

### Example
```
Input: [2, 3, 1, 6, 3, 6, 2]
Output: 1
```

---

### Solution (C++)
```cpp
int findUnique(int *arr, int size) {
    int ans = 0;
    for(int i = 0; i < size; i++) {
        ans ^= arr[i];   // XOR cancels duplicates
    }
    return ans;
}
```

---

**Complexity:**  
- Time: O(N)  
- Space: O(1)  
```

![alt text](image-2.png)

---
```

# 8. 🔎 Unique number of occurrences

![alt text](image-3.png)

**Difficulty:** 🟢 Easy  
**Tags:** Hash Map, Set, Frequency Counting  

---

### 🧩 Problem Statement  
Given an array of integers `arr`, return `true` if the number of occurrences of each value in the array is **unique**, otherwise return `false`.

---

### ✅ Example  
```
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: 
- 1 occurs 3 times
- 2 occurs 2 times
- 3 occurs 1 time
All counts are unique → return true
```

```
Input: arr = [1,2]
Output: false
Explanation:
- 1 occurs 1 time
- 2 occurs 1 time
Counts are not unique → return false
```

---

### 💻 Solution (C++)

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for(int num : arr){
            freq[num]++;
        }
        
        unordered_set<int> seen;
        // Check if frequencies are unique
        for(auto it : freq){
            if(seen.count(it.second)){
                return false; // duplicate frequency found
            }
            seen.insert(it.second);
        }

        return true;
    }
};
```

---

### 📊 Complexity Analysis  
- **Time Complexity:** O(N) → one pass to count, one pass to check  
- **Space Complexity:** O(N) → map + set storage  

---

### 🔗 Practice Links  
- [LeetCode: Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/)  
- [GeeksforGeeks: Check if frequency of all elements is unique](https://www.geeksforgeeks.org/check-frequency-of-all-elements-are-unique/)  

---

# 9. 🔁 Find all duplicates in an array

---

## Code Recap
```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;   // map value to index
            if(nums[idx] < 0) {
                // already visited → duplicate found
                result.push_back(abs(nums[i]));
            } else {
                // mark as visited by flipping sign
                nums[idx] = -nums[idx];
            }
        }

        return result;
    }
};
```

---

## Dry Run Example  
**Input:** `nums = [4,3,2,7,8,2,3,1]`

We’ll trace each iteration:

| i | nums[i] | idx = abs(nums[i]) - 1 | nums[idx] before | Action | nums after | result |
|---|---------|------------------------|------------------|--------|------------|--------|
| 0 | 4       | 3                      | 7                | mark negative | [4,3,2,-7,8,2,3,1] | [] |
| 1 | 3       | 2                      | 2                | mark negative | [4,3,-2,-7,8,2,3,1] | [] |
| 2 | -2      | 1                      | 3                | mark negative | [4,-3,-2,-7,8,2,3,1] | [] |
| 3 | -7      | 6                      | 3                | mark negative | [4,-3,-2,-7,8,2,-3,1] | [] |
| 4 | 8       | 7                      | 1                | mark negative | [4,-3,-2,-7,8,2,-3,-1] | [] |
| 5 | 2       | 1                      | -3 (already neg) | duplicate → push 2 | [4,-3,-2,-7,8,2,-3,-1] | [2] |
| 6 | -3      | 2                      | -2 (already neg) | duplicate → push 3 | [4,-3,-2,-7,8,2,-3,-1] | [2,3] |
| 7 | -1      | 0                      | 4                | mark negative | [-4,-3,-2,-7,8,2,-3,-1] | [2,3] |

---

## Final Output
```
result = [2, 3]
```

---

## Key Insight
- Each number maps to an index (`val - 1`).  
- First time we see it → mark that index negative.  
- Second time we see it → index is already negative → duplicate found.  

---

# 10. 🔗 Find array intersection

**Difficulty:** 🟢 Easy  
**Tags:** Array, Two Pointers, Intersection  

---

### 🧩 Problem Statement  
Given two sorted arrays `arr1` and `arr2` (non-decreasing order), find their intersection.  
Return a vector containing the common elements.

---

### ✅ Example  
```
Input: arr1 = [1,2,2,3,4], arr2 = [2,2,3,5]
Output: [2,2,3]
```

---

### 💻 Solution (C++)
```cpp
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int>result;
    // two  pointer approach
	//etna code shi hai but optimize ke liye aur time exceed limit se bachne ke liye hme non decresing wala use karna padega 

	// for(int i =0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		  if(arr1[i]<arr2[j]){
	// 			  break;
	// 		  }
	// 		if(arr1[i]==arr2[j]){
    //           result.push_back(arr1[i]);
	// 		  arr2[j]= INT_MIN; // update kar diye niche wala array ko taaki dubara se agar aaye upar se toh niche  wala same match na ho jaai upar wala se
	// 		  break;
	// 		}
	// 	}
	// }

  // hme non decreasing me diya hai isi liye etna chod karna pad rha hai 
   int i =0 , j=0;
   while(i<n && j<m){
	   if(arr1[i]==arr2[j]){
		   result.push_back(arr1[i]);
		   i++;
		   j++;
	   }
	   else if(arr1[i]<arr2[j]){
		   i++;
	   }
	   else{
		   j++;
	   }
   }
	return result;
}
```

---

### 📝 Dry Run Example  
**Input:** arr1 = [1,2,2,3,4], arr2 = [2,2,3,5]  

| i | j | arr1[i] | arr2[j] | Action | result |
|---|---|---------|---------|--------|--------|
| 0 | 0 | 1       | 2       | 1 < 2 → i++ | [] |
| 1 | 0 | 2       | 2       | equal → push 2, i++, j++ | [2] |
| 2 | 1 | 2       | 2       | equal → push 2, i++, j++ | [2,2] |
| 3 | 2 | 3       | 3       | equal → push 3, i++, j++ | [2,2,3] |
| 4 | 3 | 4       | 5       | 4 < 5 → i++ | [2,2,3] |

**Final Result:** `[2,2,3]`

---

### 📊 Complexity Analysis  
- **Time Complexity:** O(N + M) → single pass through both arrays  
- **Space Complexity:** O(1) → ignoring output storage  

---

### 🔗 Practice Links  
- [GeeksforGeeks: Intersection of two sorted arrays](https://www.geeksforgeeks.org/intersection-of-two-sorted-arrays/)  
- [LeetCode: Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)  

---

![alt text](image-5.png)

![alt text](image-6.png)




# 11.  🔗 Pair Sum in Array

**Difficulty:** 🟢 Easy  
**Tags:** Array, Brute Force, Sorting  

---

### 🧩 Problem Statement  
Given an array `arr` of integers and a target sum `s`, find all pairs of elements whose sum equals `s`.  
Return the pairs in sorted order, with each pair stored as `[min, max]`.

---

### ✅ Example  
```
Input: arr = [1, 2, 3, 4, 5], s = 5
Output: [[1,4], [2,3]]
```

---

### 💡 Approach  
- Use two nested loops to check all pairs `(i, j)` where `i < j`.  
- If `arr[i] + arr[j] == s`, store the pair as `[min(arr[i], arr[j]), max(arr[i], arr[j])]`.  
- After collecting all pairs, sort the result vector to maintain order.  

---

### 📝 Dry Run Example  
**Input:** arr = [1, 2, 3, 4, 5], s = 5  

| i | j | arr[i] | arr[j] | Sum | Action | result |
|---|---|--------|--------|-----|--------|--------|
| 0 | 1 | 1      | 2      | 3   | skip   | [] |
| 0 | 2 | 1      | 3      | 4   | skip   | [] |
| 0 | 3 | 1      | 4      | 5   | push [1,4] | [[1,4]] |
| 0 | 4 | 1      | 5      | 6   | skip   | [[1,4]] |
| 1 | 2 | 2      | 3      | 5   | push [2,3] | [[1,4],[2,3]] |
| 1 | 3 | 2      | 4      | 6   | skip   | [[1,4],[2,3]] |
| 1 | 4 | 2      | 5      | 7   | skip   | [[1,4],[2,3]] |
| … | … | …      | …      | …   | …      | … |

Final result after sorting: `[[1,4],[2,3]]`

---

### 💻 Solution (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> result;
 
   for(int i = 0; i < arr.size(); i++){
      for(int j = i+1; j < arr.size(); j++){
         if(arr[i] + arr[j] == s){
            vector<int> ans;
            ans.push_back(min(arr[i], arr[j])); // store min
            ans.push_back(max(arr[i], arr[j])); // store max
            result.push_back(ans);
         }
      }
   }
  
   sort(result.begin(), result.end()); // sort pairs
   return result;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int s = 5;
    vector<vector<int>> res = pairSum(arr, s);
    for(auto v : res){
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    return 0;
}
```

---

### 📊 Complexity Analysis  
- **Time Complexity:** O(n²) → nested loops check all pairs  
- **Space Complexity:** O(k) → where k is the number of valid pairs  

---

### 🔗 Practice Links  
- [LeetCode: Two Sum](https://leetcode.com/problems/two-sum/)  
- [GeeksforGeeks: Find all pairs with given sum](https://www.geeksforgeeks.org/find-all-pairs-in-an-array-whose-sum-is-equal-to-a-given-number/)  
- [Coding Ninjas: Pair Sum](https://www.codingninjas.com/studio/problems/pair-sum_697295)  

---


# 12. 🔗 Find Distinct Triplets with Given Sum

**Difficulty:** 🟡 Medium  
**Tags:** Array, Brute Force, Triplet Sum  

---

### 🧩 Problem Statement  
You are given an array/list `ARR` consisting of `N` integers.  
Your task is to find all the **distinct triplets** present in the array which add up to a given number `K`.

A triplet `{ARR[i], ARR[j], ARR[k]}` is valid if:
- `i != j`, `j != k`, `i != k`  
- `ARR[i] + ARR[j] + ARR[k] = K`

If no triplet exists, return an empty list (output printed as `-1`).

---

### ✅ Example  
```
Input: ARR = [10, 5, 5, 5, 2], K = 12
Output: [[2, 5, 5]]
```

```
Input: ARR = [1, 2, 3, 1, 2, 3], K = 6
Output: [[1, 2, 3]]
```

```
Input: ARR = [1, 2, 3, 4], K = 11
Output: -1
```

```
Input: ARR = [1, 1, 2, 2, 1, 1], K = 4
Output: [[1, 1, 2]]
```

---

### 💡 Approach  
- Use three nested loops to check all possible triplets `(i, j, k)` with `i < j < k`.  
- If their sum equals `K`, store the triplet.  
- Sort each triplet before storing to normalize order.  
- Use a `set` to avoid duplicate triplets.  
- Convert the set back to a vector before returning.

---

### 📝 Dry Run Example  
**Input:** ARR = [10, 5, 5, 5, 2], K = 12  

- i=0, j=1, k=4 → 10+5+2=17 → skip  
- i=1, j=2, k=4 → 5+5+2=12 → push [2,5,5]  
- i=2, j=3, k=4 → 5+5+2=12 → push [2,5,5] (duplicate, ignored by set)  

Final result: `[[2,5,5]]`

---

### 💻 Solution (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    set<vector<int>> uniqueSet;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == K){
                    vector<int> ans;
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    ans.push_back(arr[k]);

                    sort(ans.begin(), ans.end()); // normalize triplet
                    uniqueSet.insert(ans);        // store only distinct triplets
                }
            }
        }
    }

    vector<vector<int>> result(uniqueSet.begin(), uniqueSet.end());
    return result;
}

int main(){
    vector<int> arr = {10, 5, 5, 5, 2};
    int K = 12;
    vector<vector<int>> res = findTriplets(arr, arr.size(), K);

    if(res.empty()) cout << "-1";
    else {
        for(auto triplet : res){
            for(int x : triplet) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}
```

---

### 📊 Complexity Analysis  
- **Time Complexity:** O(n³) → three nested loops  
- **Space Complexity:** O(k) → number of distinct triplets stored  

---

### 🔗 Practice Links  
- [LeetCode: 3Sum](https://leetcode.com/problems/3sum/)  
- [GeeksforGeeks: Find all triplets with given sum](https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-given-number/)  
- [Coding Ninjas: Triplet Sum](https://www.codingninjas.com/studio/problems/triplets-with-given-sum_893028)  

---


# 13. 🔄 Sort 0s, 1s, and 2s (Dutch National Flag Algorithm)

**Difficulty:** 🟡 Medium  
**Tags:** Array, Sorting, Two Pointers  

---

### 🧩 Problem Statement  
You are given an array consisting only of `0s`, `1s`, and `2s`.  
Your task is to sort the array in ascending order **without using extra space** and in **linear time**.

This is also known as the **Dutch National Flag problem**.

---

### ✅ Example  
```
Input: arr = [0, 2, 1, 2, 0, 1]
Output: [0, 0, 1, 1, 2, 2]
```

```
Input: arr = [2, 2, 0, 1]
Output: [0, 1, 2, 2]
```

---

### 💡 Approach (Three Pointers)  
- Maintain three pointers:  
  - `low` → boundary for 0s  
  - `mid` → current element under consideration  
  - `high` → boundary for 2s  
- Traverse the array with `mid` until it crosses `high`:  
  - If `arr[mid] == 0` → swap with `low`, increment both `low` and `mid`.  
  - If `arr[mid] == 1` → just increment `mid`.  
  - If `arr[mid] == 2` → swap with `high`, decrement `high`.  

This ensures all 0s move to the left, 2s move to the right, and 1s remain in the middle.

---

### 📝 Dry Run Example  
**Input:** arr = [0, 2, 1, 2, 0, 1]  

| low | mid | high | arr[mid] | Action | Array state |
|-----|-----|------|----------|--------|-------------|
| 0   | 0   | 5    | 0        | swap arr[0], arr[0]; low++, mid++ | [0,2,1,2,0,1] |
| 1   | 1   | 5    | 2        | swap arr[1], arr[5]; high-- | [0,1,1,2,0,2] |
| 1   | 1   | 4    | 1        | mid++ | [0,1,1,2,0,2] |
| 1   | 2   | 4    | 1        | mid++ | [0,1,1,2,0,2] |
| 1   | 3   | 4    | 2        | swap arr[3], arr[4]; high-- | [0,1,1,0,2,2] |
| 1   | 3   | 3    | 0        | swap arr[1], arr[3]; low++, mid++ | [0,0,1,1,2,2] |

Final result: `[0,0,1,1,2,2]`

---

### 💻 Solution (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n) {
    int low = 0, mid = 0, high = n - 1;

    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

```

---

### 📊 Complexity Analysis  
- **Time Complexity:** O(n) → single traversal of the array  
- **Space Complexity:** O(1) → in-place sorting  

---

### 🔗 Practice Links  
- [LeetCode: Sort Colors](https://leetcode.com/problems/sort-colors/)  
- [GeeksforGeeks: Sort an array of 0s, 1s and 2s](https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/)  
- [Coding Ninjas: Sort 0 1 2](https://www.codingninjas.com/studio/problems/sort-0-1-2_631055)  

---
