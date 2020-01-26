/*                                                                             _   _
The function |_ x _| rounds the number x down to an integer, and the function |  x  | rounds the number x up to an integer
                                _   _
For example  |_ 3/2 _| = 1 and | 3/2 | = 2 
                  

The functions min(x1, x2,..., xn) and max(x1, x2,..., xn) give the smallest and largest of values x1, x2,..., xn
For example min(1,2,3) = 1 and max(1,2,3) = 3

The factorial n! can be defined
      F(n) = n * n-1 * n-2 * ... * 3 * 2 * 1
or recursively
      0! = 1
      n! = n·(n−1)!
      
The Fibonacci numbers arise in many situations. They can be defined recursively as follows:
                             F(0) = 0
                             F(1) = 1
                             F(n) = F(n−1) + F(n−2)

The first Fibonacci numbers are   0,1,1,2,3,5,8,13,21,34,55,...
F(n) = [(1+sqrt(5))/2]^n / sqrt(5)
*/

int fib(int n) 
{ 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
}
// Complexity : O(1)
// Notice , we can use pow but we can't use Power bcause phi is double
// but if answer modulo mod , we use this code
vector<ll> f(10000);
ll fib(ll n)
{
    if(n<2)
    return n;
    if(n==2)
        return 1;
    if(f[n])
        return f[n];
    ll k = (n&1) ? (n+1)/2 : n/2 ;
    return f[n] =( (n&1) ? (fib(k)*fib(k) + fib(k-1)*fib(k-1)) : (2*fib(k-1)+fib(k))*fib(k) )%mod;

}
// Complexity : O(log(n))
