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


// #include<iostream>
// using namespace std;

// void counting(int n){
//     // base condition
//     if(n==0){
//         return ;
//     }

//     counting(n-1);
//     cout<<n<<endl;
// }

// int main(){
//     int n;
//     cin>>n;

//     cout<<endl;
//     counting(n);
// }


// src and destination 

// #include<iostream>
// using namespace std;

// void reachHome(int src , int dest){

//     cout<<"source :"<<src <<"destination :"<<dest<<endl;
//     //base case
//     if(src==dest){
//         cout<<"reached home";
//         return ;
//     }  
  
//      //processing
//     src++;

//     reachHome(src , dest);
// }

// int main(){

//     int src = 1;
//     int dest = 10;

//     reachHome(src , dest);
// }



//fibonacci number 

// class Solution {
// public:
//     int fib(int n) {
//         //base case
//         if(n==0){
//             return 0;
//         }
//         if(n==1){
//             return 1;
//         }

//         int ans = fib(n-1)+ fib(n-2);
//         return ans;
//     }
// };



// say digit to words

// #include<iostream>
// using namespace std;

// void sayDigitToWords(int n , string arr[]){
//     //base case
//     if(n==0){
//         return;
//     }
    
//     int digit = n%10;
//     n = n/10;

//     sayDigitToWords(n , arr);

//     cout<<arr[digit]<<" ";

// }


// int main(){

//     int n;
//     cin>>n;

//     string arr[10] = {"zero","one","two","three" ,"four","five" ,
//                       "six" ,"seven" , "eight" , "nine"};

//    sayDigitToWords(n , arr);

// }




// IsSorted 

// class Solution {
//   public:
//     bool isSorted(vector<int>& arr) {

//         int n = arr.size();
        
//         //by for loop
//         // for(int i = 1 ; i<=n-1;i++){
//         //     if(arr[i-1]>arr[i]){
//         //         return 0;            }
//         // }
//         // return 1;
        
//         // by recursion 
//         //base case
//         if(n==0|| n==1){
//             return true;
//         }
        
//         //processing;
//         if(arr[0]>arr[1]){
//             return false;
//         }
//           // create a smaller vector from index 1 to end
//           vector<int> remaining(arr.begin()+1 , arr.end());
          
//           bool ans = isSorted(remaining);
//           return ans;
//     }
    
// };



// sum of n number 


// #include <iostream>
// using namespace std;

// int recursiveSum(int n){
//     if(n==0){
//         return 0;
//     }
//    return n + recursiveSum(n-1);
// }

// int main()
// {
//     int n = 5;
// //   for(int i = 1; i <=n;i++){
// //       sum+=i;
// //   }
// //   cout<<"sum"<<sum;
// //     return 0;

// int sum = recursiveSum(n);
// cout<<"sum"<<sum;
// }



//binary search 


// int solve(vector<int> &nums, int s , int e , int k){
//     if(s>e){
//         return -1 ;
//     }

//     int mid= s+(e-s)/2;

//     if(nums[mid]==k){
//         return mid;
//     }
//     if(nums[mid]<k){
//         return solve(nums , mid+1, e , k);
//     }
//     else{
//         return solve(nums , s, mid-1 , k);
//     }
// }

// int search(vector<int> &nums, int target) {
//     int n = nums.size();
//     int s = 0;
//     int e = n-1;
//     int ans = solve(nums , s , e , target);
// }


//lineear search

// #include<iostream>
// using namespace std;

// bool linearSearch(int arr[],int size ,int k){

//     if(size==0){
//         return false;
//     }
//     if(arr[0]==k){
//         return true;
//     }else{
//         bool remaining = linearSearch(arr+1 , size-1 , k);
//         return remaining;
//     }
// }

// int main(){
//     int arr[5] = {1,2,3,4,5};
//     int n = 5;
//     int k= 44;

//     int ans = linearSearch(arr , n ,  k);

//     if(ans){
//         cout<<"element found"<<endl;
//     }
//     else{
//         cout<<"element not found"<<endl;
//     }
// }




// reverse the string code studio website 

// #include <bits/stdc++.h> 
// void reverse(string& str ,int i ,int j){
// 	//base case
// 	if(i>j){
// 		return;
// 	}

// 	swap(str[i],str[j]);
//     i++;
// 	j--;

//     //recursive call
// 	reverse(str, i,j);

// }
// string reverseString(string str)
// {
// 	reverse(str , 0, str.length()-1);  // string ,i  and j two pointer
// 	return str;
// }



// Check If Binary Representation of a Number is Palindrome (code studio website)

// #include <bits/stdc++.h> 
// bool checkPalindrome(long long N)
// {

// 	// create empty string to store binary representation
// 	string binary = "";
	
// 	while(N>0){
//        binary +=(N%2==0)?'0':'1';
// 	   N= N/2;
// 	}
// 	string reverseBinary = binary;
// 	//reverse the copied string
// 	reverse(reverseBinary.begin() ,reverseBinary.end());
	
// 	return binary ==reverseBinary;
// }


//check palindrome 

// #include<iostream>
// using namespace std;

// bool palindrome(string str , int i ,int j){
// 	if(i>j){
// 		return true;  // agar i> j hp gya means saare character equal equal aa rhe hai so return true 
// 	}

// 	if(str[i]!=str[j]){
// 		return false;
// 	}
// 	else{
// 		return palindrome(str ,i+1  , j-1);
// 	}
// }
// int main(){
// 	string str;
// 	cin>>str;    // for integer value check convert intger value into string and pass same logic follow string str = to_string(num)

// int ans = palindrome(str, 0 , str.length()-1);

// if(ans){
// 	cout<<"its palindrome";
// }
// else{
// 	cout<<"its not a palindrome";
// }

// }



// letter combinations of a phone number leetcode problem 17

class Solution {
    private:
    void solve(string digits, int index ,string output ,vector<string>&ans , string mapping[]){
        if(index>=digits.length()){
           ans.push_back(output);
           return;
        }
    
        //include
        int number = digits[index]-'0';  // character dega toh usko int me convert karne ke liye minus 0 string kar denge toh jo bhi charcter me string diya rhega usko integer me convert kar deta hau 
        string values = mapping[number];  // jo bhi values aya uske corresponding values ko mapping kra de rhe hai 

        for(int i =0; i<values.length(); i++){  // loop chala diye pure mapping tak like agar 2 hai toh a, b, c tak 
            output.push_back(values[i]); // phir a ko le liye 
            
            solve(digits , index+1 , output , ans , mapping); // a ke saath waale ke liye jaise 3 hai toh def means ad , ae , phir af ,
            //backtrack
            output.pop_back();   // ab a waale ko hta de rhe taaki agla baar b ke saath corresponding element map kre like bd , be , bf
        }
       
        
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output ="";
        int index =0;
        string mapping[10] = {"","", "abc", "def" , "ghi", "jkl","mno","pqrs","tuv", "wxyz"};
        solve(digits , index, output , ans ,mapping);
        return ans;
    }
};




// subsets leetcode 78
class Solution {

 void    solve(vector<int> nums , int index,vector<int> output, vector<vector<int>> &ans){
        //base case
        if(index>=nums.size()){
            ans.push_back(output); //last tak pahuch gye hai means ab store kra lenge ans waale array me 
            return;
        }

        //exclude
        solve(nums ,index+1,output ,ans); // index ko aage badha rhe hai

        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums,index+1 , output , ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> output;
        int index =0;
        solve(nums , index , output , ans);
        return ans;
    }
};


// subsequences 

#include <bits/stdc++.h> 
using namespace std;

void solve(string str , int index , string output , vector<string>& ans){
	if(index>=str.size()){
		if(output.length()>0){
		ans.push_back(output);
		}
		return;
	}

	// exclude
	solve(str , index+1 , output , ans);

	//include
	char element = str[index];
	output.push_back(element);
	solve(str , index+1 ,output , ans);
}
vector<string> subsequences(string str){
	
    vector<string> ans;
	string output;
	int index =0;
	solve(str , index , output , ans);
	return ans;
}




//permutations leetcode 46

class Solution {
    private:
    void solve(vector<int> nums , int index , vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j = index ; j<nums.size();j++){
            swap(nums[index] , nums[j]);   
            solve(nums , index+1 , ans);

            //backtrack
            swap(nums[index] , nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index =0;
        
        solve(nums , index , ans);
        return ans;
    }
};



// rat in maze problem 
class Solution {
private:
    // Function to check whether the current cell (x, y) is safe to move into
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& maze) {
        // Conditions:
        // 1️⃣ x and y should be inside the maze boundary
        // 2️⃣ The cell should not be visited already
        // 3️⃣ The cell value in maze should be 1 (means open path)
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }

    // Recursive function to find all possible paths
    void solve(vector<vector<int>>& maze, int n, vector<string>& ans,
               int x, int y, vector<vector<int>> visited, string path) {

        // ✅ Base case: if we reach the destination (bottom-right cell)
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);  // Store the path found
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // The rat can move in 4 directions: Down (D), Up (U), Right (R), Left (L)

        // ↓ Move Down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('D');                          // Add 'D' to path
            solve(maze, n, ans, newx, newy, visited, path); // Recurse for next cell
            path.pop_back();                              // Backtrack - remove last move
        }

        // ↑ Move Up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('U');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // → Move Right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('R');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // ← Move Left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('L');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // ⚡ Unmark the current cell before returning (backtrack)
        visited[x][y] = 0;
    }

public:
    // Main function that initializes everything and returns all paths
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();          // Size of the maze
        vector<string> ans;           // To store all possible paths

        // If the starting cell (0,0) is blocked, return no path
        if (maze[0][0] == 0) {
            return ans;
        }

        int srcx = 0;                 // Starting cell row
        int srcy = 0;                 // Starting cell column

        // Initialize visited matrix with all 0s
        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path = "";             // To store the current path string

        // Start solving from source (0,0)
        solve(maze, n, ans, srcx, srcy, visited, path);

        // Sort all paths lexicographically (optional but common in problems)
        sort(ans.begin(), ans.end());

        return ans;
    }
};
