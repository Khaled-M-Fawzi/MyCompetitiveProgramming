# Divide large number represented as string

Given a large number (represented as string) which has to divided by another number (represented as int data type)
The large number can be very large which does not even fit in long long in C++. The task is to find division of these numbers.

Input : number  = 12313413534672234, divisor = 754
        
Output : 16330787181262

```cpp
string longDivision(string number, int divisor) 
{ 
    string ans; 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
    while(idx < number.size()) 
    { 
        ans += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    if (ans.length() == 0) 
        return "0"; 
    return ans; 
} 
```