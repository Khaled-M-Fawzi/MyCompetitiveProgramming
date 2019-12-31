// for implementation O(N * L) Where n is number of words and L is maximum string length OR average
// for insert OR search O(L) Where L length of a word
#include <bits/stdc++.h>
#define ll long long
#define N 500000
using namespace std;
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}
int sz;
vector<int>en(N);
vector<vector<int>>node(N,vector<int>(27));
void insert(string s)
{
    int v=0;
    for(int i=0;i<s.size();i++)
    {
        int c=s[i]-'a';
        if(!node[v][c])
            node[v][c]=++sz;
        v=node[v][c];
    }
    en[v]++;
}
bool search(string s)
{
    int v=0;
    for(int i=0;i<s.size();i++)
    {
        int c=s[i]-'a';
        if(!node[v][c])
            return false;
        v=node[v][c];
    }
    return en[v]>0;
}
int main()
{
    fast();
    int n,m;
    cin>>n>>m;
    string x;
    while(n--)
    {
        cin>>x;
        insert(x);
    }
    while(m--)
    {
        cin>>x;
        cout<<(search(x)?"YES":"NO")<<'\n';
    }
    return 0;
}
