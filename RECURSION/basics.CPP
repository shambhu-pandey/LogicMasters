// print factorial using recursion

// #include <iostream>
// using namespace std;

// int factorial(int n)
// {
//     // base condition

//     if (n == 0)
//     {
//         return 1;
//     }

//     int smallest = factorial(n - 1);
//     int biggest = n * smallest;

//     return biggest;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int ans = factorial(n);
//     cout << "ans :" << ans;
// }



// print counting 

#include<iostream>
using namespace std;

void counting(int n){
    // base condition
    if(n==0){
        return ;
    }

    counting(n-1);
    cout<<n<<endl;;
}

int main(){
    int n;
    cin>>n;

    cout<<endl;
    counting(n);
}