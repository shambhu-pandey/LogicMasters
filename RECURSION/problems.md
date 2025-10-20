# 🧠 Recursion & Backtracking Problem Set

Welcome to the **Recursion and Backtracking Problem Set**! 💡
This collection features **common problems solved using Recursion and Backtracking in C++**.
Each problem includes **problem statement, examples, your solution code, complexity analysis, and practice links**.

---

## 📑 Table of Contents

1. [🧮 Factorial Using Recursion](#1-❗-factorial-calculation)  
2. [🔢 Print Counting](#2-🔢-print-counting-1-to-n)  
3. [🏠 Source to Destination Path](#3-🏠-source-to-destination-path)  
4. [🔁 Fibonacci Number](#4-fibonacci-number)  
5. [🔤 Say Digit to Words](#5-🗣️-say-digit-to-words)  
6. [📈 Check Array Sorted](#6-✅-check-array-sorted-recursive)  
7. [➕ Sum of N Numbers](#7-➕-sum-of-n-numbers-recursive)  
8. [🔍 Binary Search (Recursive)](#8-🔎-binary-search-recursive)  
9. [🔍 Linear Search (Recursive)](#9-🔎-linear-search-recursive)  
10. [🔄 Reverse String](#10-↩️-reverse-string)  
11. [💾 Binary Palindrome Check](#12-🔟-binary-palindrome-check)  
12. [🔁 String Palindrome Check](#11-🔤-check-palindrome-string)  
13. [📱 Phone Digit Combinations](#13-☎️-letter-combinations-of-a-phone-number)  
14. [📚 Subsets](#14-🧩-subsets-of-an-array)  
15. [📚 Subsequences](#15-🔢-subsequences-of-a-string)  
16. [🔀 Permutations](#16-🔄-permutations-of-an-array)  
17. [🐀 Rat in Maze Problems](#17-🐀-rat-in-a-maze)  
18. [🪜 Stairs Problem](#18-🪜-count-ways-to-reach-the-n-th-stairs)

---

## 1. ❗ Factorial Calculation

**Difficulty:** 🟢 Easy
**Tags:** Basic Recursion, Math
**Practice Link:** [GFG](https://www.geeksforgeeks.org/recursive-program-to-find-factorial-of-a-number/) | [LeetCode Similar](https://leetcode.com/problems/factorial-trailing-zeroes/) | [CodingNinjas](https://www.codingninjas.com/codestudio/problems/factorial_920459)

### Problem Statement

Calculate the factorial of a non-negative integer `n` using recursion.

### Examples

**Input:** `n = 5`
**Output:** `120`
**Explanation:** `5! = 5 * 4 * 3 * 2 * 1 = 120`

### 💻 Solution (C++)

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// int main() {
//     int n;
//     cin >> n;
//     cout << factorial(n);
// }
```

### 📊 Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(n) (recursion stack)

---

## 2. 🔢 Print Counting (1 to N)

**Difficulty:** 🟢 Easy
**Tags:** Basic Recursion, Head Recursion
**Practice Link:** [GFG](https://www.geeksforgeeks.org/print-numbers-1-n-using-recursion/) | [LeetCode Similar](https://leetcode.com/problems/count-and-say/) | [CodeStudio](https://www.codingninjas.com/studio/problems/print-numbers_625159)

### Problem Statement

Given an integer `n`, print numbers from 1 to `n` in increasing order using recursion.

### Examples

**Input:** `n = 4`
**Output:**

```
1
2
3
4
```

### 💻 Solution (C++)

```cpp
#include<iostream>
using namespace std;

void counting(int n) {
    if(n == 0) return;
    counting(n - 1);
    cout << n << endl;
}

// int main() {
//     int n;
//     cin >> n;
//     counting(n);
// }
```

### 📊 Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(n)

---

## 3. 🏠 Source to Destination Path

**Difficulty:** 🟢 Easy
**Tags:** Basic Recursion
**Practice Link:** [GFG](https://www.geeksforgeeks.org/count-ways-reach-nth-stair/) | [LeetCode Similar](https://leetcode.com/problems/climbing-stairs/)

### Problem Statement

Simulate the path from `src` to `dest` by moving one step at a time (`src++`) using recursion until the destination is reached.

### Examples

**Input:** `src = 1, dest = 3`
**Output:**

```
source :1 destination :3
source :2 destination :3
reached home
```

### 💻 Solution (C++)

```cpp
#include<iostream>
using namespace std;

void reachHome(int src , int dest){
    cout << "source :" << src << " destination :" << dest << endl;
    if(src == dest){
        cout << "reached home";
        return;
    }
    reachHome(src + 1 , dest);
}

// int main() {
//     reachHome(1, 3);
// }
```

### 📊 Complexity Analysis

* **Time Complexity:** O(dest - src)
* **Space Complexity:** O(dest - src)

---

## 4. Fibonacci Number

**Difficulty:** 🟢 Easy
**Tags:** Recursion, Math
**Practice Link:** [GFG](https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/) | [LeetCode](https://leetcode.com/problems/fibonacci-number/) | [HackerRank](https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem)

### Problem Statement

Return the n-th Fibonacci number, defined by `F(n) = F(n-1) + F(n-2)`, with `F(0)=0` and `F(1)=1`.

### Examples

**Input:** `n = 4`
**Output:** `3`

### 💻 Solution (C++)

```cpp
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fib(n-1) + fib(n-2);
    }
};
```

### 📊 Complexity Analysis

* **Time Complexity:** O(2^n)
* **Space Complexity:** O(n)

---

## 5. 🗣️ Say Digit to Words

**Difficulty:** 🟢 Easy
**Tags:** Recursion, Number Processing
**Practice Link:** [GFG](https://www.geeksforgeeks.org/print-digits-number-words-using-recursion/)

### Problem Statement

Given a number n, print its digits in words (e.g., 412 prints "four one two").

### Examples

**Input:** `n = 412`
**Output:** `four one two`

### 💻 Solution (C++)

```cpp
#include<iostream>
#include<string>
using namespace std;

void sayDigitToWords(int n , string arr[]){
    if(n == 0) return;
    int digit = n % 10;
    n = n / 10;
    sayDigitToWords(n , arr);
    cout << arr[digit] << " ";
}

// int main(){
//     int n;
//     cin>>n;
//     string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
//     sayDigitToWords(n , arr);
// }
```

### 📊 Complexity Analysis

* **Time Complexity:** O(log10 n)
* **Space Complexity:** O(log10 n)

---


## 6. ✅ Check Array Sorted (Recursive)

**Difficulty:** 🟢 Easy
**Tags:** Recursion, Array
**Practice Link:** [GFG: Check if array is sorted](https://www.geeksforgeeks.org/check-array-sorted-recursive/)

### Problem Statement

Determine if an array `arr` is sorted in non-decreasing order using recursion.

### Examples

**Example 1:**

```
Input: arr = [2, 4, 6, 9]
Output: true
```

### Solution (C++)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    bool isSorted(vector<int>& arr) {
        int n = arr.size();
        if (n == 0 || n == 1) return true;
        if (arr[0] > arr[1]) return false;
        vector<int> remaining(arr.begin() + 1, arr.end());
        return isSorted(remaining);
    }
};
```

### Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(n^2) (due to vector copying)

---

## 7. ➕ Sum of N Numbers (Recursive)

**Difficulty:** 🟢 Easy
**Tags:** Basic Recursion, Math
**Practice Link:** [GFG: Sum of N numbers](https://www.geeksforgeeks.org/sum-natural-numbers-using-recursion/)

### Problem Statement

Calculate the sum of all integers from 1 to n using recursion.

### Examples

**Example 1:**

```
Input: n = 5
Output: 15
```

### Solution (C++)

```cpp
#include <iostream>
using namespace std;

int recursiveSum(int n){
    if(n == 0) return 0;
    return n + recursiveSum(n-1);
}
```

### Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(n)

---

## 8. 🔎 Binary Search (Recursive)

**Difficulty:** 🟢 Easy
**Tags:** Recursion, Searching
**Practice Link:** [LeetCode: Binary Search](https://leetcode.com/problems/binary-search/)

### Problem Statement

Find the index of target in a sorted array using recursive binary search.

### Examples

**Example 1:**

```
Input: nums = [2, 5, 8, 12, 16], target = 12
Output: 3
```

### Solution (C++)

```cpp
#include <vector>
using namespace std;

int solve(vector<int>& nums, int s, int e, int k){
    if(s > e) return -1;
    int mid = s + (e - s)/2;
    if(nums[mid] == k) return mid;
    if(nums[mid] < k) return solve(nums, mid + 1, e, k);
    return solve(nums, s, mid - 1, k);
}

int search(vector<int>& nums, int target){
    return solve(nums, 0, nums.size()-1, target);
}
```

### Complexity Analysis

* **Time Complexity:** O(log n)
* **Space Complexity:** O(log n)

---

## 9. 🔎 Linear Search (Recursive)

**Difficulty:** 🟢 Easy
**Tags:** Recursion, Searching
**Practice Link:** [GFG: Linear Search](https://www.geeksforgeeks.org/linear-search/)

### Problem Statement

Determine if element k is present in array arr using recursive linear search.

### Examples

**Example 1:**

```
Input: arr = [1, 2, 3, 4, 5], k = 4
Output: element found
```

### Solution (C++)

```cpp
#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int k){
    if(size == 0) return false;
    if(arr[0] == k) return true;
    return linearSearch(arr + 1, size - 1, k);
}
```

### Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(n)

---

## 10. ↩️ Reverse String

**Difficulty:** 🟢 Easy
**Tags:** Recursion, String, Two Pointers
**Practice Link:** [CodeStudio: Reverse String](https://www.codingninjas.com/studio/problems/reverse-the-string_823073)

### Problem Statement

Reverse the string str in-place using recursion and the two-pointer approach.

### Examples

**Example 1:**

```
Input: str = "hello"
Output: "olleh"
```

### Solution (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

void reverse(string& str, int i, int j){
    if(i > j) return;
    swap(str[i], str[j]);
    reverse(str, i+1, j-1);
}

string reverseString(string str){
    reverse(str, 0, str.length()-1);
    return str;
}
```

### Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(n)

---


## 11. 🔤 Check Palindrome (String)

**Difficulty:** 🟢 Easy
**Tags:** Recursion, String, Two Pointers
**Practice Link:** [CodeStudio](https://www.codingninjas.com/studio/problems/check-palindrome_630484)

### Problem Statement

Determine if a string `str` is a palindrome using recursion.

### Example

**Input:** `str = "madam"`
**Output:** `its palindrome`

### 💻 Solution (C++)

```cpp
#include<iostream>
using namespace std;

bool palindrome(string str , int i ,int j){
    if(i > j) return true;
    if(str[i] != str[j]) return false;
    return palindrome(str ,i + 1 , j - 1);
}

// int main(){
//     string str;
//     cin>>str;
//     bool ans = palindrome(str, 0 , str.length()-1);
//     if(ans) cout<<"its palindrome";
//     else cout<<"its not a palindrome";
// }
```

### Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)` (Recursion stack depth)

---

## 12. 🔟 Binary Palindrome Check

**Difficulty:** 🟢 Easy
**Tags:** Bit Manipulation, String, Palindrome
**Practice Link:** [CodeStudio](https://www.codingninjas.com/studio/problems/check-if-binary-representation-is-palindrome_630507)

### Problem Statement

Check if the binary representation of a number `N` is a palindrome.

### Example

**Input:** `N = 9` (Binary: `1001`)
**Output:** `true`

### 💻 Solution (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(long long N){
    string binary = "";
    while(N > 0){
        binary += (N % 2 == 0) ? '0' : '1';
        N /= 2;
    }
    string reverseBinary = binary;
    reverse(reverseBinary.begin(), reverseBinary.end());
    return binary == reverseBinary;
}
```

### Complexity Analysis

* **Time Complexity:** `O(log N)`
* **Space Complexity:** `O(log N)`

---

## 13. ☎️ Letter Combinations of a Phone Number

**Difficulty:** 🟡 Medium
**Tags:** Recursion, Backtracking, String
**Practice Link:** [LeetCode](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

### Problem Statement

Given a string of digits (2-9), return all possible letter combinations they can represent.

### Example

**Input:** `digits = "23"`
**Output:** `["ad","ae","af","bd","be","bf","cd","ce","cf"]`

### 💻 Solution (C++)

```cpp
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    void solve(string digits, int index, string output, vector<string>& ans, string mapping[]){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string values = mapping[number];
        for(int i = 0; i < values.length(); i++){
            output.push_back(values[i]);
            solve(digits, index + 1, output, ans, mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits){
        vector<string> ans;
        if(digits.empty()) return ans;
        string mapping[10] = {"","", "abc", "def" , "ghi", "jkl","mno","pqrs","tuv", "wxyz"};
        solve(digits, 0, "", ans, mapping);
        return ans;
    }
};
```

### Complexity Analysis

* **Time Complexity:** `O(4^n * n)`
* **Space Complexity:** `O(n)`

---

## 14. 🧩 Subsets of an Array

**Difficulty:** 🟡 Medium
**Tags:** Recursion, Backtracking, Combinatorics
**Practice Link:** [LeetCode](https://leetcode.com/problems/subsets/)

### Problem Statement

Given an array `nums` of unique elements, return all possible subsets (power set).

### Example

**Input:** `nums = [1, 2, 3]`
**Output:** `[[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]`

### 💻 Solution (C++)

```cpp
#include <vector>
using namespace std;

class Solution {
private:
    void solve(vector<int> nums, int index, vector<int> output, vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        solve(nums, index+1, output, ans);
        output.push_back(nums[index]);
        solve(nums, index+1, output, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        solve(nums, 0, {}, ans);
        return ans;
    }
};
```

### Complexity Analysis

* **Time Complexity:** `O(2^n * n)`
* **Space Complexity:** `O(n)`


# 🧠 Recursion and Backtracking Problem Set

Welcome to the **Recursion and Backtracking Problem Set**! 💡
This collection features common problems solved using **Recursion and Backtracking in C++**.
Each problem includes **problem statement, examples, your solution code, and complexity analysis**.

---


## 15. 🔢 Subsequences of a String

**Difficulty:** 🟡 Medium
**Tags:** Recursion, Backtracking, String
**Practice Link:** [CodeStudio: Subsequences of String](https://www.codingninjas.com/studio/problems/subsequences-of-string_981246)

### Problem Statement

Find all non-empty subsequences of a given string `str`.

### Examples

**Input:** `str = "ab"`
**Output:** `["a", "b", "ab"]`

### 💻 Solution (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(string str, int index, string output, vector<string>& ans){
    if(index >= str.size()){
        if(output.length() > 0){
            ans.push_back(output);
        }
        return;
    }
    // Exclude current character
    solve(str, index + 1, output, ans);
    // Include current character
    output.push_back(str[index]);
    solve(str, index + 1, output, ans);
}

vector<string> subsequences(string str){
    vector<string> ans;
    solve(str, 0, "", ans);
    return ans;
}
```

### Complexity Analysis

* **Time Complexity:** O(2^n * n)
* **Space Complexity:** O(n) (recursion stack depth)

---

## 16. 🔄 Permutations of an Array

**Difficulty:** 🟡 Medium
**Tags:** Recursion, Backtracking, Array
**Practice Link:** [LeetCode: 46. Permutations](https://leetcode.com/problems/permutations/)

### Problem Statement

Return all possible permutations of an array `nums` of distinct integers.

### Examples

**Input:** `nums = [1, 2, 3]`
**Output:** `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`

### 💻 Solution (C++)

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void solve(vector<int> nums, int index, vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j = index; j < nums.size(); j++){
            swap(nums[index], nums[j]);
            solve(nums, index + 1, ans);
            swap(nums[index], nums[j]); // backtrack
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};
```

### Complexity Analysis

* **Time Complexity:** O(n! * n)
* **Space Complexity:** O(n) (recursion stack depth)

---

## 17. 🐀 Rat in a Maze

**Difficulty:** 🔴 Hard
**Tags:** Recursion, Backtracking, Grid Traversal
**Practice Link:** [GFG: Rat in a Maze Problem](https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/)

### Problem Statement

Find all possible paths for a rat to move from `(0,0)` to `(N-1,N-1)` in a maze (matrix with 1s as open paths). Moves allowed: Down, Up, Right, Left.

### Examples

**Input:** `maze = [[1,0],[1,1]]`
**Output:** `["DR"]`

### 💻 Solution (C++)

```cpp
class Solution {
private:
    // Function to check whether the current cell (x, y) is safe to move into
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& maze) {
        // Conditions:
        // 1️⃣ x and y should be inside the maze boundary
        // 2️⃣ The cell should not be visited already
        // 3️⃣ The cell value in maze should be 1 (means open path)
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }

    // Recursive function to find all possible paths

    void solve(vector<vector<int>>& maze, int n, vector<string>& ans,
               int x, int y, vector<vector<int>> visited, string path) {

        // ✅ Base case: if we reach the destination (bottom-right cell)
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);  // Store the path found
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // The rat can move in 4 directions: Down (D), Up (U), Right (R), Left (L)

        // ↓ Move Down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('D');                          // Add 'D' to path
            solve(maze, n, ans, newx, newy, visited, path); // Recurse for next cell
            path.pop_back();                              // Backtrack - remove last move
        }

        // ↑ Move Up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('U');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // → Move Right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('R');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // ← Move Left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('L');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // ⚡ Unmark the current cell before returning (backtrack)
        visited[x][y] = 0;
    }

public:
    // Main function that initializes everything and returns all paths
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();          // Size of the maze
        vector<string> ans;           // To store all possible paths

        // If the starting cell (0,0) is blocked, return no path
        if (maze[0][0] == 0) {
            return ans;
        }

        int srcx = 0;                 // Starting cell row
        int srcy = 0;                 // Starting cell column

        // Initialize visited matrix with all 0s
        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path = "";             // To store the current path string

        // Start solving from source (0,0)
        solve(maze, n, ans, srcx, srcy, visited, path);

        // Sort all paths lexicographically (optional but common in problems)
        sort(ans.begin(), ans.end());

        return ans;
    }
};


```

### Complexity Analysis

* **Time Complexity:** O(4^(N*N))
* **Space Complexity:** O(N*N) (recursion stack depth + visited matrix)


---

## 18. 🪜 Count Ways to Reach the N-th Stairs

**Difficulty:** 🟡 Medium  
**Tags:** Recursion, Dynamic Programming  

---

### 🧩 Problem Statement

You are given a staircase with `N` steps. You start at the 0th step and want to reach the Nth step.  
At each move, you can climb either 1 or 2 steps.  
Return the number of distinct ways to reach the Nth step.

⚠️ Since the number of ways can be very large, return the answer modulo `1000000007`.

---

### 📥 Input

- An integer `N` representing the number of stairs.

### 📤 Output

- An integer representing the number of distinct ways to reach the Nth stair.

---

### ✅ Example

- Input: N = 3 Output: 3

- Explanation: Ways to reach step 3: 1 → 1 → 1 1 → 2 2 → 1 Total = 3 ways

--- 

---

### 💻 Solution (C++)

```cpp
#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    if (nStairs < 0) return 0;
    if (nStairs == 0) return 1;

    // Recursive relation: f(n) = f(n-1) + f(n-2)
    int ans = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
    return ans;
}
```