/*

Modular multiplicative inverse
Given two integers ‘a’ and ‘m’, find modular multiplicative inverse of ‘a’ under modulo ‘m’.

The modular multiplicative inverse is an integer ‘x’ such that.
 a * x ≡ 1 (mod m) 
The value of x should be in {0, 1, 2, … m-1}, i.e., in the range of integer modulo m.
The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).

Input:  a = 3, m = 11
Output: 4
Since (4*3) mod 11 = 1, 4 is modulo inverse of 3
One might think, 15 also as a valid output as "(15*3) mod 11" 
is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not valid

Input:  a = 10, m = 17
Output: 12
Since (10*12) mod 17 = 1, 12 is modulo inverse of 10

Method 1 (Naive)
A Naive method is to try all numbers from 1 to m
For every number x, check if (a*x)%m is 1 
Time Complexity of this method is O(m)

Method 2 (Works when m and a are coprime)
The idea is to use Extended Euclidean algorithms that takes two integers ‘a’ and ‘b’
finds their gcd and also find ‘x’ and ‘y’ such that

 ax + by = gcd(a, b) 
To find multiplicative inverse of ‘a’ under ‘m’, we put b = m in above formula
Since we know that a and m are relatively prime, we can put value of gcd as 1.

 ax + my = 1 
If we take modulo m on both sides, we get

ax + my ≡ 1 (mod m)
We can remove the second term on left side as ‘my (mod m)’ would always be 0 for an integer y.

 ax  ≡ 1 (mod m) 
So the ‘x’ that we can find using Extended Euclid Algorithm is multiplicative inverse of ‘a’

*/
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    int x1, y1;  
    int g = gcdExtended(b%a, a, &x1, &y1);   
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return g; 
}
void modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcd(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        int res = (x%m + m) % m; 
     // Notice that we modify x. The resulting x from the extended Euclidean algorithm may be negative
     // so x % m might also be negative and we first have to add m to make it positive
        cout << "Modular multiplicative inverse is " << res; 
    } 
} 
int main() 
{ 
    int a = 3, m = 11; 
    modInverse(a, m); 
    return 0; 
} 
// Time Complexity of this method is O(log min(a,m))





/***************************** Modular multiplicative inverse from 1 to n *****************************

Give a positive integer n, find modular multiplicative inverse of all integer from 1 to n with respect to a prime number
The modular multiplicative inverse of a is an integer ‘x’ such that.
 a x ≡ 1 (mod prime) 
Input : n = 10, prime = 17
Output : 1 9 6 13 7 3 5 15 2 12
Explanation :
For 1, modular inverse is 1 as (1 * 1)%17 is 1
For 2, modular inverse is 9 as (2 * 9)%17 is 1
For 3, modular inverse is 6 as (3 * 6)%17 is 1
....... 
Input : n = 5, prime = 7
Output : 1 4 5 2 3

The problem is the following: we want to compute the modular inverse for every number in the range [1,n].
Applying the algorithms described in the previous sections, we can obtain a solution with complexity O(nlogn).
Here we present a better algorithm with complexity O(n). However for this specific algorithm we require that the modulus m is prime.
We denote by inv[i] the modular inverse of i. Then for i>1 the following equation is valid:

inv[i]= −⌊m/i⌋⋅inv[m mod i] mod m

Thus the implementation is very simple:
*/
void modularInverse(int n, int prime) 
{ 
    int inv[n+1];
    inv[1] = 1;
 
    for(int i=2 ; i<=n ; ++i)
        inv[i] = (m - (m/i) * inv[m%i] % m) % m;
 
    for (int i = 1; i <= n; i++)  
        cout << inv[i] << ' ';     
} 
/*
Proof
We have:
m mod i = m − ⌊m/i⌋ ⋅ i
Taking both sides modulo m yields:
m mod i ≡ − ⌊m/i⌋ ⋅ i  (mod m)
Multiply both sides by i^−1 ⋅ (m mod i)^−1 yields
(m mod i) ⋅ i^−1 ⋅ (m mod i)^−1 ≡ − ⌊m/i⌋ ⋅ i ⋅ i^−1 ⋅ (m mod i)^−1 (mod m)
which simplifies to:
i^−1 ≡ −⌊m/i⌋⋅(m mod i)^−1 (mod m)
