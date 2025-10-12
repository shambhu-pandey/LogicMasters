#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[] ,int n , int key){
    
    for(int i = 0 ; i<n ; i++){
        if(arr[i]==key){
            return i;
        }
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

    int index = linearSearch(arr , n , key);
    cout<<"index of key is :"<<index;
}