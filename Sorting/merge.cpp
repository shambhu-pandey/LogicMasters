#include<bits/stdc++.h>
using namespace std;

void merge( int *arr , int s , int e){

    int mid = (s+e)/2;
    
    // 2 array bna lete hai usme copy kar ke daal denge element 

    //pahla array ka length
    int length1 = mid-s+1;
    
    //dusra array ka length
    int length2 = e- mid;

     // pahle array bna liye 
     int *first = new int[length1];
     //dusra array bna liye 
     int *second = new int[length2];

     //ab mujhe value copy kar ke rkhni hai dono array me upar wala array se

     // copy values 1st array me 
     int k = s; 
     for(int i = 0 ; i<length1;i++){
        first[i]= arr[k++];
     }
     
     // copy values second array me 
     k= mid+1;
    for(int i =0;i <length2;i++){
        second[i]= arr[k++];
    }
      
    //ab merge kar denge 
     // merge 2 sorted array wala concept lag jaayega 

     //index create kar liye 
     int i = 0 ; int j= 0;  // i = index1 , j = index2
     int mainArrayIndex = s;

     while(i<length1 && j<length2){
          if(first[i]<second[j]){
            arr[mainArrayIndex++]= first[i++];
          }
          else{
            arr[mainArrayIndex++] = second[j++];
          }
     }
        // agar maan lijiye 1st wala array me kuch bach gya toh agar length jyada hoga 2nd wala array se toh ho sakta hai ki bach jaai
        while(i<length1){
            arr[mainArrayIndex++]= first[i++];
        }
        while(j<length2){
             arr[mainArrayIndex++]=second[j++];
        }

}

void mergeSort(int *arr , int s , int e){

    //base case
    if(s>=e){
        return;
    }

    int mid = (s+e)/2;
        //left part sort karna hai
    mergeSort(arr , s , mid);

    //right part sort karna hai
    mergeSort(arr , mid+1 , e);

    //Merge 
    merge(arr , s , e);
}


int main(){

    int n = 5;
    int arr[5];

    cout<<"enter element :"<<endl;
     for(int i = 0 ; i<5;i++){
        cin>>arr[i];
     }

    mergeSort(arr , 0 , n-1);
    
    cout<<"\n sorting element are :"<<endl ;
    for(int i = 0 ; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}