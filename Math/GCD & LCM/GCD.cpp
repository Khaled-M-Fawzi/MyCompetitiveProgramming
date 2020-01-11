// GCD (Greatest Common Divisor) or HCF (Highest Common Factor)
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
