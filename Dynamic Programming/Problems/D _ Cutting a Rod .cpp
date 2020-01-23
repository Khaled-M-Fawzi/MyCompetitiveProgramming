/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n
Determine the maximum value obtainable by cutting up the rod and selling the pieces

For example, if length of the rod is 8 and the values of different pieces are given as following, 
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

*/


/*
<< Memoization Method – Top Down Dynamic Programming >>
Complexity : O(nn)
Considering the above implementation, following is recursion tree for a Rod of length 4
cR() ---> cutRod() 

                             cR(4)
                  /        /      \      \    
                 /        /        \      \ 
             cR(3)       cR(2)     cR(1)   cR(0)
            /            /            \
           /            /              \  
 cR(2) cR(1) cR(0)    cR(1) cR(0)    cR(0)
  /         \          \
 /           \          \   
 cR(1) cR(0)  cR(0)      cR(0)
   /
  /
CR(0)
*/
int dp[10001];
vector<int>price;
int cut(int n)
{
    if(n<=0)
        return 0;
    int m = INT_MIN;
    if(dp[n])return dp[n];
    for(int i=0;i<n;i++)
        m = max(m,price[i]+cut(n-(i+1)));
    return dp[n] = m;
}
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        price = vector<int>(n+1);
        for(int i=0;i<n;i++)
            cin>>price[i];
        cout<<cut(n)<<'\n';

    }
    return 0;
}
// << Tabulation Method – Bottom Up Dynamic Programming >>
// Complexity : O(nn)
using namespace std;
vector<int>price;
int cut(int n)
{
    int dp[n+1];dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int m = INT_MIN;
        for(int j=0;j<i;j++)
        m = max(m,price[j]+dp[i-(j+1)]);
        dp[i]=m;
    }
    return dp[n];
}
int main()
{
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        price = vector<int>(n+1);
        for(int i=0;i<n;i++)
            cin>>price[i];
        cout<<cut(n)<<'\n';
    }
    return 0;
}
