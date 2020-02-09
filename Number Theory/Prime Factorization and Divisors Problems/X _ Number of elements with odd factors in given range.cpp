/*
Number of elements with odd factors in given range
Given a range [n,m], find the number of elements that have odd number of factors in the given range (n and m inclusive).

Examples :

Input  : n = 5, m = 100
Output : 8
The numbers with odd factors are 9, 16, 25, 
36, 49, 64, 81 and 100

Input  : n = 8, m = 65
Output : 6

Input  : n = 10, m = 23500
Output : 150


*/

int countOddSquares(int n, int m) 
{ 
   return (int)pow(m,0.5) - (int)pow(n-1,0.5); 
} 
int main() 
{ 
    int n = 5, m = 100; 
    cout << "Count is " << countOddSquares(n, m);  // 8
    return 0; 
} 

// Time Complexity : O(1)
