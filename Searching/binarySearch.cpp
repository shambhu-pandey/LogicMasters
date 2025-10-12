#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[] , int size , int key){

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;

    //jab tak start chota ho ya equal hai end tak taab tak while loop chalege
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
       
        //agar key bda ho gya mid se toh right side wala part me khojenge toh ab start = mid+1 ho jaayega
        if(key>arr[mid]){
            start=mid+1;
        }
        
        //agar key bda nhi hua mid se toh left part me jaayega so end of left part ka end = mid-1 
        else{
            end = mid-1;
        }
       
        //upar start , end update ho gya toh mid ko phir se update toh karna hi padega 
        mid=start + (end-start)/2;

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

    int index = binarySearch(arr , n , key);
    cout<<"index of key is :"<<index;
}



// =================== Algorithm (Binary Search) ===================
//
// 1. Start
// 2. Read the size of array `n` from the user
// 3. Read `n` sorted elements into an array
// 4. Read the element `key` to be searched
// 5. Initialize start = 0, end = n-1
// 6. While start <= end
//      a. Find mid = (start + end) / 2
//      b. If arr[mid] == key → return mid (key found)
//      c. If key > arr[mid] → search in right half (start = mid + 1)
//      d. Else → search in left half (end = mid - 1)
// 7. If not found, return -1
// 8. Display result
// 9. End
// ================================================================