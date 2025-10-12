#include<bits/stdc++.h>
using namespace std;

int main(){

    int x = 10;
    int* ptr = &x;

    cout<<"the value of x :" <<x<<endl;
    cout<<"the address of x :"<<&x<<endl;
    

    cout<<"the value stored in ptr (the addrss of x) :"  <<ptr<<endl;
    cout<<"the value pointed to by the ptr :"<<*ptr<<endl;



    *ptr =20;
    cout<<"the new value of x after the modifaction :"<<x<<endl;
    return 0;
}