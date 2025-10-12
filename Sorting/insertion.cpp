#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[] , int n){
    for(int i = 0 ; i<n;i++){
        int j = i;
        while( j>0 && arr[j-1] > arr[j]){  // Compare current element with previous
            int temp = arr[j];             // Swap if current element is smaller
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;                           // Move left until correct position is found
        }
    }
}
 
int main(){
    int n ;

    cout<<"enter n :"<<endl;
    cin>>n;

    int arr[n];
    cout<<"enter element:"<<endl;
    for(int i = 0;i <n;i++){
        cin>>arr[i];
    }

    insertionSort(arr ,n);
    cout<<"sorted array:"<<endl;
    for(int i = 0 ; i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


// 🔹 Algorithm (Insertion Sort in Words)
// --------------------------------------
// Start with the first element (already sorted).
// Pick the next element (key) from unsorted part.
// Compare the key with elements in the sorted part.
// Shift all elements greater than the key one step to the right.
// Insert the key in its correct position.
// Repeat until all elements are sorted.


// 🔹 PSEUDOCODE with LINE-BY-LINE COMMENTS
// ----------------------------------------

// InsertionSort(A, n)              // A = array, n = size of array
// 1. for i ← 1 to n-1 do           // Iterate from 2nd element to last
// 2.     key ← A[i]                // Store the current element as key
// 3.     j ← i - 1                 // Start comparing with the left side
// 4.     while j ≥ 0 and A[j] > key do  // While left element is greater than key
// 5.         A[j+1] ← A[j]         // Shift element one position right
// 6.         j ← j - 1             // Move left
// 7.     end while
// 8.     A[j+1] ← key              // Insert key into correct position
// 9. end for


// 🔹 Example (Array: [7, 4, 5, 2])
// --------------------------------
// First element 7 → already sorted.
// Pick 4 → compare with 7 → shift 7 → insert 4 → [4, 7, 5, 2]
// Pick 5 → compare with 7 → shift 7 → insert 5 → [4, 5, 7, 2]
// Pick 2 → compare with 7, 5, 4 → shift all → insert 2 → [2, 4, 5, 7]

// ✅ Final sorted array = [2, 4, 5, 7]


// 🔹 Time Complexity
// -------------------
// Best Case (Already Sorted): O(n) → only comparisons, no shifts
// Worst Case (Reverse Sorted): O(n²) → every element shifted each time
// Average Case: O(n²)
