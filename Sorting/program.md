# Sorting Algorithms in C++

## Table of Contents

1. [Bubble Sort](#bubble-sort)
2. [Insertion Sort](#insertion-sort)
3. [Merge Sort](#merge-sort)
4. [Quick Sort](#quick-sort)
5. [Radix Sort](#radix-sort)
6. [Selection Sort](#selection-sort)
7. [Shell Sort](#shell-sort)
8. [Practice Platforms](#practice-platforms)

---

## Bubble Sort

```cpp
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int n;
    cout << "enter n :" << endl;
    cin >> n;
    int arr[n];
    cout << "enter element:" << endl;
    for(int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr, n);
    cout << "sorted array:" << endl;
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
```

### Algorithm Explanation (Bubble Sort in Words)

* Begin with the first element of the array.
* Compare each element with the next element.
* If the current element is greater than the next, swap them.
* Continue this process for all elements in the array for the first pass; this will place the largest element at the last position.
* Ignore the last element (already sorted) and repeat the comparison process for the remaining elements.
* Continue until a full pass occurs without any swaps, indicating that the array is fully sorted.

### Pseudocode

```
BubbleSort(A, n)
1. for i ← 0 to n-1
2.     swapped ← false
3.     for j ← 0 to n-i-2
4.         if A[j] > A[j+1]
5.             swap(A[j], A[j+1])
6.             swapped ← true
7.     if swapped = false
8.         break
```

### Example

Array: `[7, 4, 1, 5, 3]` → Sorted: `[1, 3, 4, 5, 7]`

### Time Complexity

* Best Case: O(n)
* Worst Case: O(n²)
* Average Case: O(n²)

---

## Insertion Sort

```cpp
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    insertionSort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
```

### Algorithm Explanation (Insertion Sort in Words)

* Begin with the first element, assuming it is sorted.
* Take the next element (key) from the unsorted part of the array.
* Compare the key with the elements in the sorted part of the array.
* Shift all elements that are greater than the key one position to the right.
* Insert the key into its correct position.
* Repeat the process until all elements are sorted.

### Time Complexity

* Best Case: O(n)
* Worst Case: O(n²)
* Average Case: O(n²)

---

## Merge Sort

```cpp
#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;
    int length1 = mid-s+1, length2 = e-mid;
    int *first = new int[length1];
    int *second = new int[length2];

    for(int i=0, k=s; i<length1; i++, k++) first[i]=arr[k];
    for(int i=0, k=mid+1; i<length2; i++, k++) second[i]=arr[k];

    int i=0, j=0, k=s;
    while(i<length1 && j<length2){
        if(first[i]<second[j]) arr[k++]=first[i++];
        else arr[k++]=second[j++];
    }
    while(i<length1) arr[k++]=first[i++];
    while(j<length2) arr[k++]=second[j++];
}

void mergeSort(int *arr, int s, int e){
    if(s>=e) return;
    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}

int main(){
    int arr[5] = {2,5,1,6,9};
    mergeSort(arr, 0, 4);
    for(int i=0; i<5; i++) cout<<arr[i]<<" ";
}
```

---

## Quick Sort

```cpp
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++) if(arr[i]<=pivot) count++;
    int pivotIndex = s+count;
    swap(arr[pivotIndex], arr[s]);

    int i=s, j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<pivotIndex && j>pivotIndex) swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s>=e) return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int arr[5] = {34,2,11,3,5};
    quickSort(arr, 0, 4);
    for(int i=0; i<5; i++) cout<<arr[i]<<" ";
}
```

### Algorithm Explanation (Quick Sort in Words)

* Select the first element as pivot.
* Count the number of elements less than or equal to pivot.
* Place pivot at its correct position.
* Reorder elements around pivot so smaller are left, larger are right.
* Recursively sort left and right subarrays.
* Stop recursion when subarray size ≤ 1.

### Complexity

* Best/Average: O(n log n)
* Worst: O(n²)
* Space: O(log n) recursion stack

---

## Radix Sort

```cpp
#include <iostream>
using namespace std;

int getMax(int arr[], int n){
    int mx=arr[0];
    for(int i=1; i<n; i++) if(arr[i]>mx) mx=arr[i];
    return mx;
}

void countingSort(int arr[], int n, int exp){
    int output[n], count[10]={0};
    for(int i=0; i<n; i++) count[(arr[i]/exp)%10]++;
    for(int i=1; i<10; i++) count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++) arr[i]=output[i];
}

void radixSort(int arr[], int n){
    int m = getMax(arr, n);
    for(int exp=1; m/exp>0; exp*=10) countingSort(arr, n, exp);
}

int main(){
    int arr[] = {170,45,75,90,802,24,2,66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
```

---

## Selection Sort

```cpp
#include<bits/stdc++.h>
using namespace std;

void selection_sort(int array[], int n){
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i+1;j<=n-1;j++)
            if(array[j]<array[mini]) mini=j;
        swap(array[i], array[mini]);
    }
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++) cin >> array[i];
    selection_sort(array,n);
    for(int i=0;i<n;i++) cout<<array[i]<<" ";
}
```

### Algorithm Explanation (Selection Sort in Words)

* Start with first element and assume it is the smallest.
* Compare with remaining elements and find the actual smallest.
* Swap the smallest element with the first element.
* Move to next element and repeat until array is sorted.

---

## Shell Sort

```cpp
#include <iostream>
using namespace std;

void shellSort(int arr[], int n){
    for(int gap=n/2; gap>0; gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i], j;
            for(j=i;j>=gap && arr[j-gap]>temp;j-=gap) arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    }
}

int main(){
    int arr[]={12,34,54,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    shellSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
```

### Algorithm Explanation (Shell Sort in Words)

* Start with a large gap, reduce gap gradually.
* Perform insertion sort on elements separated by gap.
* Reduce gap until it becomes 1 (final insertion sort).
* Array becomes sorted after final pass.

---
