
# 1 🔢 Matrix Operations: Target Search, Row-wise and Column-wise Sum

**Difficulty:** 🟡 Medium  
**Tags:** Matrix, 2D Array, Iteration  

---

### 🧩 Problem Statement  
You are given a 2×2 matrix. Your tasks are:  
1. Input elements row-wise.  
2. Display the matrix.  
3. Search for a target element.  
4. Compute **row-wise sums**.  
5. Compute **column-wise sums**.  

---

### ✅ Example  
**Input:**
```
1 2
3 4
Target = 3
```

**Output:**
```
Matrix elements are:
1 2
3 4

Enter element you want to search: 3
Element found ✅

Row-wise sums:
Row 1 sum = 3
Row 2 sum = 7

Column-wise sums:
Column 1 sum = 4
Column 2 sum = 6
```

---

### 💻 Solution (C++)
```cpp
#include <iostream>
using namespace std;

// Function to check if target exists in matrix
int target_check(int arr[][2], int target, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == target) {
                return 1; // found
            }
        }
    }
    return 0; // not found
}

// Function to calculate row-wise sum
void rowWiseSum(int arr[][2], int n, int m) {
    cout << "Row-wise sums:" << endl;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
        cout << "Row " << i+1 << " sum = " << sum << endl;
    }
}

// Function to calculate column-wise sum
void colWiseSum(int arr[][2], int n, int m) {
    cout << "Column-wise sums:" << endl;
    for(int j = 0; j < m; j++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i][j];
        }
        cout << "Column " << j+1 << " sum = " << sum << endl;
    }
}

int main() {
    int arr[2][2];

    // Input elements row-wise
    cout << "Enter elements (row-wise):" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    // Display matrix
    cout << "\nMatrix elements are:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Search target
    int target;
    cout << "\nEnter element you want to search: ";
    cin >> target;

    if(target_check(arr, target, 2, 2)) {
        cout << "Element found ✅" << endl;
    } else {
        cout << "Not found ❌" << endl;
    }

    cout << endl;
    rowWiseSum(arr, 2, 2);
    colWiseSum(arr, 2, 2);

    return 0;
}
```

---


### 📊 Complexity  
- **Target search:** O(n × m)  
- **Row-wise sum:** O(n × m)  
- **Column-wise sum:** O(n × m)  
- **Space Complexity:** O(1) (fixed 2×2 matrix)  

---

### 🔗 Practice Links  
- [GeeksforGeeks: Matrix problems](https://www.geeksforgeeks.org/matrix/)  
- [LeetCode: Matrix problems](https://leetcode.com/tag/matrix/)  
- [Coding Ninjas: Matrix problems](https://www.codingninjas.com/studio/problems?topic=Matrix)  

---


# 2. 🔢 Matrix Row-wise Sum and Maximum Row

**Difficulty:** 🟡 Medium  
**Tags:** Matrix, 2D Array, Iteration  

---

### 🧩 Problem Statement  
You are given a 2×2 matrix. Your tasks are:  
1. Input elements row-wise.  
2. Display the matrix.  
3. Compute **row-wise sums**.  
4. Find the **row with the maximum sum** and return its index.

---

### ✅ Example  
**Input:**
```
1 2
3 4
```

**Output:**
```
Matrix elements are:
1 2
3 4

Row sums:
3
7
maximum sum is : 7
max is at index 1
```

---

### 💻 Solution (C++)
```cpp
#include <iostream>
#include <climits>
using namespace std;

// Function to calculate row-wise sum and find row with maximum sum
int rowWiseSum(int arr[][2], int n, int m) {
    int maxi = INT_MIN;   // store maximum sum
    int rowIndex = 0;     // store row index of maximum sum

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
        cout << "Row " << i+1 << " sum = " << sum << endl;

        if(sum > maxi) {
            maxi = sum;
            rowIndex = i;
        }
    }

    cout << "Maximum sum is: " << maxi << endl;
    return rowIndex;
}

int main() {
    int arr[2][2];

    // Input elements row-wise
    cout << "Enter elements (row-wise):" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    // Display matrix
    cout << "\nMatrix elements are:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    int ans = rowWiseSum(arr, 2, 2);
    cout << "Max sum is at row index " << ans << endl;

    return 0;
}
```

---


### 📊 Complexity  
- **Row-wise sum:** O(n × m)  
- **Finding maximum row:** O(n) (done while computing sums)  
- **Space Complexity:** O(1)  

---

### 🔗 Practice Links  
- [GeeksforGeeks: Row with maximum sum](https://www.geeksforgeeks.org/find-row-with-maximum-sum/)  
- [Coding Ninjas: Matrix problems](https://www.codingninjas.com/studio/problems?topic=Matrix)  

---



# 3.🔢 Matrix Operations: Sum, Multiplication, Division, Transpose

**Difficulty:** 🟡 Medium  
**Tags:** Matrix, 2D Array, Iteration  

---

### 🧩 Problem Statement  
You are given two 2×2 matrices. Your tasks are:  
1. Input both matrices row‑wise.  
2. Display the matrices.  
3. Compute **matrix sum** (element‑wise addition).  
4. Compute **matrix multiplication (element‑wise)**.  
5. Compute **matrix division (element‑wise)**.  
6. Compute the **transpose** of the first matrix.

---

### ✅ Example  
**Input:**
```
Matrix 1:
1 2
3 4

Matrix 2:
5 6
7 8
```

### 💻 Solution (C++)
```cpp
#include <iostream>
using namespace std;

// Function to compute matrix sum (element-wise)
void matrixsum(int arr1[][2], int arr2[][2], int n, int m) {
    int result[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    cout << "sum is:" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to compute matrix multiplication (element-wise)
void matrixmul(int arr1[][2], int arr2[][2], int n, int m) {
    int result[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            result[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
    cout << "mul is:" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to compute matrix division (element-wise)
void matrixdiv(int arr1[][2], int arr2[][2], int n, int m) {
    int result[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            result[i][j] = arr1[i][j] / arr2[i][j]; // integer division
        }
    }
    cout << "div is:" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to compute transpose of a matrix
void transpose(int arr1[][2], int n, int m) {
    cout << "transpose is:" << endl;
    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr1[2][2], arr2[2][2];

    cout << "Enter elements for matrix 1 (row-wise):" << endl;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter elements for matrix 2 (row-wise):" << endl;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            cin >> arr2[i][j];
        }
    }

    cout << "\nMatrix 1:" << endl;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatrix 2:" << endl;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    matrixsum(arr1, arr2, 2, 2);
    matrixmul(arr1, arr2, 2, 2);
    matrixdiv(arr1, arr2, 2, 2);
    transpose(arr1, 2, 2);

    return 0;
}
```




---

### 📊 Complexity  
- **Matrix sum:** O(n × m)  
- **Matrix multiplication (element-wise):** O(n × m)  
- **Matrix division (element-wise):** O(n × m)  
- **Transpose:** O(n × m)  
- **Space Complexity:** O(n × m) for result matrix  

---

### 🔗 Practice Links  
- [GeeksforGeeks: Matrix problems](https://www.geeksforgeeks.org/matrix/)  
- [LeetCode: Matrix problems](https://leetcode.com/tag/matrix/)  
- [Coding Ninjas: Matrix problems](https://www.codingninjas.com/studio/problems?topic=Matrix)  

---


![alt text](image-11.png)

# 🌊 Wave Print of a Matrix

**Difficulty:** 🟡 Medium  
**Tags:** Matrix, 2D Array, Traversal  

---

### 🧩 Problem Statement  
Given a 2D matrix of size `nRows × mCols`, print its elements in **wave form**:  
- Traverse column by column.  
- If the column index is **even**, print from **top to bottom**.  
- If the column index is **odd**, print from **bottom to top**.  

Return the wave traversal as a vector.

---

### ✅ Example  
**Input:**
```
Matrix:
1  2  3
4  5  6
7  8  9
```

**Output (Wave Print):**
```
1 4 7 8 5 2 3 6 9
```

---

### 💡 Approach  
1. Initialize an empty vector `ans`.  
2. Traverse each column `col` from `0` to `mCols-1`.  
3. If `col` is even → traverse rows top to bottom.  
4. If `col` is odd → traverse rows bottom to top.  
5. Push elements into `ans`.  
6. Return `ans`.

---

### 💻 Solution (C++)
```cpp
#include <bits/stdc++.h> 
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> ans;

    for(int col = 0; col < mCols; col++) {
        if(col % 2 == 0) {
            // Even column → Top to Bottom
            for(int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        } else {
            // Odd column → Bottom to Top
            for(int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}
```

---

### 📝 Dry Run Example  
**Matrix:**
```
1 2 3
4 5 6
7 8 9
```

- Column 0 (even): `1,4,7`  
- Column 1 (odd): `8,5,2`  
- Column 2 (even): `3,6,9`  

**Wave Print:** `1 4 7 8 5 2 3 6 9`

---

### 📊 Complexity  
- **Time Complexity:** O(nRows × mCols) → each element visited once  
- **Space Complexity:** O(nRows × mCols) → result vector  

---

### 🔗 Practice Links  
- [GeeksforGeeks: Wave Print of a Matrix](https://www.geeksforgeeks.org/print-matrix-in-wave-form/)  
- [Coding Ninjas: Wave Print](https://www.codingninjas.com/studio/problems/print-like-a-wave_893268)  

---
