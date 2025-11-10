// build  graph 
// basically we need vertex and edges to build graph and we are using dynamic array to store vertex neighbour
// so first we need to add list header file 


#include<iostream>
#include<list>
#include<bits/stdc++.h>
#include<list>
using namespace std;

class Graph{
    int V; // vertex
    list<int> *l ; // int *arr (dynamic array we created like this)
   
public:
    Graph(int V){
        this->V  = V;
        l = new list<int> [V]; // arr = new int[V]
    }

    void addEdge(int u , int v){
        l[u].push_back(v);  // means ek vertex ka neighbour dusre ke saath connected so push
        l[v].push_back(u); // dusra wala connected hai usko bhi push 
    }

    void printAdjList(){
        for(int i =0; i<V;i++){
            cout<<i<<": ";
           for(int neigh :l[i]){
            cout<<neigh<<" ";
           }
           cout<<endl;
        }
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.printAdjList();

    return 0;
}

