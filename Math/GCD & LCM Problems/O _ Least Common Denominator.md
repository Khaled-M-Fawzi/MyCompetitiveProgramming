# Least Common Denominator

The lowest Common Denominator(LCD) or Least Common Denominator is the Least Common Multiple of the denominators of a set of fractions.
 ```
 3   -> Numerator             2     3
---                          --- + ---
 4   -> Denominator           5     5
                               \   /
                         Common Denominator
```
Common denominator : when the denominators of two or more fractions are the same.
 
Least Common denominator is the smallest of all common denominators.
 
Why do we need LCD ?
 
It simplifies addition, subtraction and comparing fraction.
 
Common Denominator can be simply evaluated by multiplying the denominators. In this case, 3 * 6 = 18
 ```
 1     1     9     3
--- + --- = --- = ---
 3     6     18    6
 ```
But that may not always be least common denominator as in this case LCD = 6 and not 18. LCD is actually LCM of denominators.


LCD for fractions 1/3 and 4/7 is 21
 
Example Problem : Given two fractions, find their sum using least common dominator.
 
Input :  1/6  +  7/15    
 
Output : 19/30و Explanation : LCM of 6 and 15 is 30. So, 5/30  +  14/30 = 19/30.
  
```cpp
int lcm(int a, int b) 
{ 
    return (a * b) / __gcd(a, b); 
} 
void printSum(int num1, int den1, int num2, int den2) 
{ 
    int lcd = lcm(den1, den2); 
    num1 *= (lcd / den1);  
    num2 *= (lcd / den2);  
 
    int res_num = num1 + num2; 
    cout << res_num << "/" << lcd; 
} 
int main() 
{ 
    int num1 = 1, den1 = 6;  
    int num2 = 7, den2 = 15;  
    printSum(num1, den1, num2, den2); 
    return 0; 
} 
```