#include <bits/stdc++.h>
using namespace std;

// Partition function
int partition(int arr[], int s, int e) {
    int pivot = arr[s];      // Choose the first element as pivot
    int count = 0;

    // Count how many elements are <= pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place pivot at its correct position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    // Reorder elements around pivot
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

// QuickSort function
void quickSort(int arr[], int s, int e) {
    // Base case
    if (s >= e) {
        return;
    }

    // Partition index
    int p = partition(arr, s, e);

    // Sort left part
    quickSort(arr, s, p - 1);

    // Sort right part
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[5] = {34, 2, 11, 3, 5};
    int n = 5;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


// ============ Algorithm (Quick Sort) ============
//
// 1. Read input size `n` from user.
// 2. Read `n` elements into array.
// 3. Call QuickSort function with array, start index = 0, end index = n-1.
// 4. In QuickSort:
//      a. Pick a pivot element (first element).
//      b. Count elements <= pivot.
//      c. Place pivot in its correct sorted position.
//      d. Rearrange: smaller on left, larger on right.
//      e. Recursively QuickSort left and right subarrays.
//      f. Stop when subarray size <= 1 (already sorted).
// 5. Print the final sorted array.
// ================================================


/* ========================================================
   🔹 Pseudocode (with Comments)
   --------------------------------------------------------
   QuickSort(A, start, end)
   1. if start >= end: return              // Base case
   2. pivotIndex = Partition(A, start, end) // Place pivot correctly
   3. QuickSort(A, start, pivotIndex - 1)   // Sort left part
   4. QuickSort(A, pivotIndex + 1, end)     // Sort right part

   Partition(A, start, end)
   1. pivot = A[start]                     // Select pivot
   2. count = number of elements <= pivot
   3. pivotIndex = start + count
   4. swap(A[pivotIndex], A[start])        // Place pivot correctly
   5. i = start, j = end
   6. while i < pivotIndex and j > pivotIndex:
   7.     while A[i] <= pivot: i++
   8.     while A[j] > pivot: j--
   9.     if i < pivotIndex and j > pivotIndex:
              swap(A[i], A[j])             // Fix misplaced elements
   10. return pivotIndex
   ======================================================== */


/* ========================================================
   🔹 Example (Array: [34, 2, 11, 3, 5])
   --------------------------------------------------------
   Step 1: Pivot = 34 → place correctly → [2, 11, 3, 5, 34]
   Step 2: Sort left side [2, 11, 3, 5]
           Pivot = 2 → place correctly → [2, 11, 3, 5]
   Step 3: Sort right side [11, 3, 5]
           Pivot = 11 → place correctly → [3, 5, 11]
   Step 4: Final Sorted Array = [2, 3, 5, 11, 34]
   ======================================================== */


/* ========================================================
   🔹 Complexity Analysis
   --------------------------------------------------------
   Best Case (Balanced partitions): O(n log n)
   Average Case: O(n log n)
   Worst Case (Already sorted array, poor pivot choice): O(n²)

   Space Complexity: O(log n)  // due to recursion stack
   In-place? YES (no extra array required)
   ======================================================== */
