
// #include<iostream>
// using namespace std;

// LAREGEST AND SMALLEST ELEMENT 

// int main(){
//     int arr[4] = {4, 12, 8, 10};

//     int n =sizeof(arr)/sizeof(int);
//     cout<<"size of n :"<<n;
    
//     cout<<"printing element";
//     for(int i =0;i<n;i++){
//          cout<<arr[i]<<" ";
//     }

//     int max=INT_MIN;
//     int min= INT_MAX;

//     for(int i = 0;i<n;i++){
//     if(arr[i]>max){
//         max=arr[i];
//     }
//     cout<<"\n";
//     if(arr[i]<min){
//         min = arr[i];
//     }
//     }

//     cout<<"max is :"<<max;
//     cout<<"min is :"<<min;
//     return 0;

// }
 





// SCOPE IN ARRAY

// void update_func(int arr[] , int n){

//     arr[2]= 100;
//     cout<<"after array update";
//     for(int i =0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<"finished array update";
// }

// int main(){
//     int arr[100];
//     int n ;
//     cout<<"enter size : "<<"\n";
//     cin>>n;

//     cout<<"enter element :";
//     for(int i =0;i<n;i++){
//      cin>>arr[i];
//     }
//     cout<<"\n";

//     cout<<"array element are :";
//     for(int i =0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }

//     update_func(arr,n);


//      cout<<"after the function call element  are :";
//     for(int i =0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }




//sum of element 


// void update_func(int arr[] , int n){

//    int sum =0;
//    cout<<"array sum are :";
//     for(int i =0;i<n;i++){
//         sum = sum + arr[i];
//     }
// cout<<"sum is :"<<sum;
// }

// int main(){
//     int arr[100];
//     int n ;
//     cout<<"enter size : "<<"\n";
//     cin>>n;

//     cout<<"enter element :";
//     for(int i =0;i<n;i++){
//      cin>>arr[i];
//     }
//     cout<<"\n";

//     cout<<"array element are :";
//     for(int i =0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }

//     update_func(arr,n);


// }





//power of 2 or not


// int main() {
//     int arr[100];
//     int n;

//     // --- Input Phase ---
//     cout << "Enter an integer N: " << "\n";
//     cin >> n;

//     // --- Initialization Phase ---
//     // Corrected the index from arr[100] to arr[i]
//     for (int i = 0; i < 30; i++) {
//         arr[i] = 2<< i;
//     }

//     // --- Display Phase ---
//     cout << "First 30 array elements are: ";
//     for (int i = 0; i < 30; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << "\n"; // Add a newline for formatting

//     bool found = false;

//     for(int i =0;i<30;i++){
//         if(arr[i]==n){
//             found = true;
//             break;
//         }
       
//     }
    
//     if(found){
//         cout<<"element present:";
//     }
//     else{
//         cout<<"not found :"; 
//     }
//     return 0;
// }


//Reverse an array

// int main(){
//     int arr[100];
    
//     int n;
//     cout<<"enter no of element:";
//     cin>>n;

//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     cout<<"print in reverse order :";
//     for(int i = n-1 ; i>=0;i--){
//         cout<<arr[i]<<" ";
//     }

//     return 0;
// }

//swap alternate 

// void printarray(int array[], int n ){
//     for(int i=0;i<n;i++){
//         cout<<array[i]<<" ";
//     }
// }

// void swapalternate(int arr[] ,int size){
//     for(int i =0;i<size;i=i+2){
//         if(i+1<size){
//             swap(arr[i], arr[i+1]);
//         }
//     }
// }



// void swapalternate(int arr[] ,int size){
//     for(int i =0;i<size;i=i+2){
//         if(i+1<size){
//             int temp= arr[i+1];
//             arr[i+1]= arr[i];
//             arr[i]=temp;
//         }
//     }
// }

// // swap alternate
// int main(){

//     int even[8]= {1,2,3,4,5,6,7,8};
//     int odd[5]= {5,6,7,8,9};

//     swapalternate(even , 8);
//     printarray(even, 8);

//     cout<<endl;

//     swapalternate(odd , 8);
//     printarray(odd, 5);
//     return 0;
// } 



#include<iostream>
using namespace std;


    int target_check(int arr[][2] , int target , int n , int m){
      for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
     
    }
    return 0;
}

int main(){

    int arr[2][2];

    cout<<"enter element and that will store in row wise  :"<<endl;
    for(int i =0;i<2;i++){
        for(int j =0;j<2;j++){
            cin>>arr[i][j];
        }
    }

    // cout<<"enter element and that will store in column wise  :"<<endl;
    // for(int j =0;j<2;j++){
    //     for(int i=0;i<2;i++){
    //         cin>>arr[i][j];
    //     }
    // }

    cout<<"array element are :"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<arr[i][j]<<" ";
        }
    }

    int target;
    cout<<"\n enter element you want to search :";
    cin>>target;

    if(target_check(arr , target , 2,2)){
        cout<<"element found";
    }
    else{
        cout<<"not found";
    }
    


    cout<<"row wise sum :"<<endl;
    
    return 0;

}
