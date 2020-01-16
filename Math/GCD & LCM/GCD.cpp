// GCD (Greatest Common Divisor) or HCF (Highest Common Factor)
/*
GCD of two numbers is the largest number that divides both of them . A simple way to find GCD is to factorize both numbers 
and multiply common factors
36 = 2 * 2 * 3 * 3
60 = 2 * 2 * 3 * 5

gcd = Multiplication of common factors
    = 2 * 2 * 3
    = 12

we express the 2 numbers in form of : m = qn + r 
find gcd of 190 , 34
190 = 5 (34) + 20
34 = 1 (20) + 14
20 = 1 (14) + 6
14 = 2 (6) + 2
6 = 3 (2) + 0
2 is GCD of 190 , 34
we have another way to find gcd of 2 numbers called successive difference
a          b          a-b         b-a
144       166                     22
144       22          122
122       22          100
100       22          78
78        22          56
56        22          34
34        22          12
12        22                      10
12        10          2
2         10                      8
2         8                       6
2         6                       4
2         4                       2
2         2
gcd is 2 because a == b

Below is a recursive function to evaluate gcd using Euclidean’s algorithm

O(log min(a,b))
*/
#include <bits/stdc++.h>
#define ll long long
#define N 50000000
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a,b;cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}
