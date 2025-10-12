#include<bits/stdc++.h>
using namespace std;

void selection_sort(int array[], int n) {
    for(int i = 0; i <= n-2; i++) {          // Loop through unsorted part
        int mini = i;                        // Assume current index is minimum
        for(int j = i+1; j <= n-1; j++) {    // Check remaining unsorted elements
            if(array[j] < array[mini]) {     // If smaller element found
                mini = j;                    // Update index of minimum element
            }
        }
        // Swap the found minimum element with the first element of unsorted part
        int temp = array[i];
        array[i] = array[mini];
        array[mini] = temp;
    }
}

int main() {
    int n;

    cout << "Enter number of elements: " << endl;
    cin >> n;
    
    int array[n];

    cout << "Enter array elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    selection_sort(array, n);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    return 0;
}


// 🔹 Selection Sort Algorithm (Step by Step in Words)
// ---------------------------------------------------
// Start with the first element of the array.
// Assume this element is the smallest.
// Compare it with every other element in the unsorted part.
// If a smaller element is found, update the minimum index.
// Swap the first element with this smallest element.
// The first element is now sorted.
// Repeat the process for the second element, third element, and so on.
// Stop when only one element remains (it will already be sorted).


// 🔹 PSEUDOCODE with Line-by-Line Comments
// ----------------------------------------
// SelectionSort(A, n)              // A = array, n = size of array
// 1. for i ← 0 to n-2 do           // Iterate through unsorted array
// 2.     minIndex ← i              // Assume current element is the smallest
// 3.     for j ← i+1 to n-1 do     // Check remaining unsorted part
// 4.         if A[j] < A[minIndex] // If smaller element found
// 5.             minIndex ← j      // Update minimum index
// 6.     end for
// 7.     swap(A[i], A[minIndex])   // Swap current element with found minimum
// 8. end for


// 🔹 Example (Array: [29, 10, 14, 37, 13])
// ----------------------------------------
// Pass 1: Smallest is 10 → swap with 29 → [10, 29, 14, 37, 13]
// Pass 2: Smallest is 13 → swap with 29 → [10, 13, 14, 37, 29]
// Pass 3: Smallest is 14 → already in place → [10, 13, 14, 37, 29]
// Pass 4: Smallest is 29 → swap with 37 → [10, 13, 14, 29, 37]

// ✅ Final Sorted Array = [10, 13, 14, 29, 37]


// 🔹 Time Complexity
// -------------------
// Best Case: O(n²)   → Still needs to check all elements
// Worst Case: O(n²)  → Still compares all pairs
// Average Case: O(n²)
// Space Complexity: O(1) → In-place sorting
