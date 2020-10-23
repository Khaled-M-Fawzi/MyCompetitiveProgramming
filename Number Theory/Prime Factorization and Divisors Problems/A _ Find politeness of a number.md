# Find politeness of a number

Given an integer n. Find politeness of number n

Politeness of a number is defined as the number of ways it can be expressed as the sum of consecutive integers

Input: n = 15
    
Output: 3
    
Explanation : There are only three ways to express

15 = 1 + 2 + 3 + 4 + 5
    
15 = 4 + 5 + 6
    
15 = 7 + 8
    
Hence answer is 3

**Naive approach** is to run a loop one inside another and find the sum of every consecutive integers up to n
Time complexity of this approach will be O(n^2) which will not be sufficient for large value of n

**Efficient approach** is to use two pointers. time complexity : O(n)

**More Efficient approach** is to use factorization. We factorize the number n and count the number of odd factors

Total number of odd factors - 1 is equal to politeness of the number.

In general if a number can be represented as a^p * b^q * c^r … where a, b, c, … are prime factors of n
If a = 2 (even) then discard it and count total number of odd factors which can be written 
as [(q + 1) * (r + 1) * …] – 1 (Here 1 is subtracted because single term in representation is not allowed)

Illustration : For n = 90, decomposition of prime factors will be as follows:-
    
=> 90 = 2 * 3^2 * 5^1. The power of odd prime factors 3, 5 are 2 and 1 respectively

Apply above formula as: (2 + 1) * (1 + 1) -1 = 5. Hence 5 will be the answer.
    
We can crosscheck it All odd factors are 3, 5, 9, 15 and 45

```cpp
int countOddPrimeFactors(int n) 
{ 
    int result = 1; 
    while (n % 2 == 0) 
        n /= 2; 
    for (int i = 3; i * i <= n; i += 2)
    { 
        int divCount = 0; 
        while (n % i == 0)
        { 
            n /= i; 
            ++divCount; 
        } 
  
        result *= divCount + 1; 
    } 
    if (n > 2) 
        result *= 2; 
  
    return result; 
} 
  
int politness(int n) 
{ 
    return countOddPrimeFactors(n) - 1; 
} 
int main() 
{ 
    int n = 90; 
    cout << "Politness of " << n << " = "<< politness(n) << "\n"; 
  
    n = 15; 
    cout << "Politness of " << n << " = "<< politness(n) << "\n"; 
    return 0; 
} 
```
Time complexity: O(sqrt(n))


In general if a number can be represented as a^p * b^q * c^r … where a, b, c, … are prime factors of n

count total number of factors = [(p + 1) * (q + 1) * (r + 1) * …] 