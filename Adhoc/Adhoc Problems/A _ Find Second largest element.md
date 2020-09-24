# Find Second largest element

Given an array of integers, our task is to write a program that efficiently 
finds the second largest element present in the array

Input : arr[] = {12, 35, 1, 10, 34, 1}

Output : The second largest element is 34.
    
Input : arr[] = {10, 5, 10}

Output : The second largest element is 5.
    
Input : arr[] = {10, 10, 10}

Output : -1.
    
```cpp
int main()
{
    int n,x,mx1=INT_MIN,mx2=INT_MIN;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(x>mx1)
        {
            mx2 = mx1;
            mx1 = x;
        }
        else if(x>mx2&&x!=mx1)
            mx2 = x;
    }
    cout<<(mx2==INT_MIN)?-1:mx2;
    return 0;
}
```
Complexity : O(n)