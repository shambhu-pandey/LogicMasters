#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[] , int n){

    for(int i = 0 ; i<n-1;i++){
        for(int j = 0; j<n-i-1;j++){
          if(arr[j]>arr[j+1]){
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j]= temp;
          }
        }
    }
}

int main(){
    int n;
    cout<<"enter  n :"<<endl;
    cin>>n;
     
    int arr[n];
    cout<<"enter element:"<<endl;
    for(int i = 0 ;i <n ; i++){
        cin>>arr[i];
    }

    bubbleSort(arr , n);
    cout<<"sorted array:"<<endl;
    for(int i = 0 ; i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


// 🔹 Algorithm (Bubble Sort in Words)
// -----------------------------------
// Start the algorithm.

// Input the size of the array (n).

// Ask the user: “Enter the number of elements.”

// Store the value in n.

// Input the array elements.

// Create an array of size n.

// Ask the user to enter n elements one by one.

// Store them into the array.
// Start with the first element of the array.
// Compare the current element with the next element.
// If the current element is greater than the next element, swap them.
// Move to the next element and repeat the comparison until the end of the array.
// After the first pass, the largest element will be placed at the last position.
// Repeat the same process for the remaining unsorted part of the array (ignoring the last sorted element each time).
// Continue until no swaps are needed, which means the array is sorted.


// 🔹 PSEUDOCODE with LINE-BY-LINE COMMENTS
// ----------------------------------------

// BubbleSort(A, n)              // A = array, n = size of array

// 1. for i ← 0 to n-1 do        // Outer loop → runs n times, each pass pushes largest element to the end
// 2.     swapped ← false        // Boolean flag to check if any swap happens in this pass
// 3.     for j ← 0 to n-i-2 do  // Inner loop → compares adjacent elements up to unsorted part
// 4.         if A[j] > A[j+1]   // Condition: if current element is bigger than next
// 5.             swap(A[j], A[j+1]) // Swap them (bubble larger element to the right)
// 6.             swapped ← true // Mark that a swap occurred
// 7.         end if
// 8.     end for                // Inner loop completed (one pass finished)
// 9.     if swapped = false     // If no swaps in this pass
// 10.        break              // Stop early → array is already sorted
// 11. end for                   // Outer loop ends


// 🔹 Example (Array = [7, 4, 1, 5, 3])
// ------------------------------------
// Pass 1: Compare and swap → [4, 1, 5, 3, 7] → Largest element 7 moves to last
// Pass 2: Compare and swap → [1, 4, 3, 5, 7] → 5 in correct place
// Pass 3: Compare and swap → [1, 3, 4, 5, 7] → 4 in correct place
// Pass 4: No swaps → Stop

// ✅ Final Sorted Array = [1, 3, 4, 5, 7]


// 🔹 Time Complexity
// -------------------
// Best Case (Already Sorted Array): O(n) → only one pass
// Worst Case (Reversed Array): O(n²) → maximum swaps
// Average Case: O(n²) → about half the elements need swapping each pass
