```cpp
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
int maxSubArraySum(int a[], int size) 
{ 
    int ans = INT_MIN, r = 0; 
    for (int i = 0; i < size; i++) 
    { 
        r = r + a[i]; 
        if (ans < r) ans = r; 
        if (r < 0) r = 0; 
    } 
    return ans; 
}
//  OR
int maxSubArraySum(int a[], int size) 
{ 
   int ans = a[0], r = a[0]; 
   for (int i = 1; i < size ; i++) 
   { 
       r = max( a[i] , r + a[i] ); 
       ans = max( ans , r );
   } 
   return ans; 
} 
// Time Complexity : O(n)
//To print the subarray with the maximum sum, we maintain indices whenever we get the maximum sum
int maxSubArraySum(int a[], int size) 
{ 
    int ans = INT_MIN , r = 0, sat =0, en = 0, s=0; 

    for (int i=0; i< size; i++ ) 
    { 
        r += a[i]; 

        if (ans < r) 
        { 
            ans = r; 
            sat = s; 
            en = i; 
        } 

        if (r < 0) 
        { 
            r = 0; 
            s = i + 1; 
        } 
    } 
    cout << "Maximum contiguous sum is "<< ans << endl; 
    cout << "Starting index "<< sat <<"  :   Ending index "<< en << endl; 
}
```
