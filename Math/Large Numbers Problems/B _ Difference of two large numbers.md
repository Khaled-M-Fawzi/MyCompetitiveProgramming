# Difference of two large numbers

Given two numbers as strings. The numbers may be very large (may not fit in long long int)
the task is to find difference of these two numbers.

Input : str1 = "11443333311111111100", str2 =  "1144422222221111"
        
Output : 11442188888888889989


This is simple based on school mathematics. We traverse both strings from end, one by one subtract digits.
1) Reverse both strings.
2) Keep subtracting digits one by one from 0’th index (in reversed strings) to end of smaller string,
append the diff if it’s positive to end of result. If difference(diff) is negative then add 10 
and keep track of carry as 1 if it’s positive then carry is 0.
3) Finally reverse the result.
```cpp
bool islarger(string str1,string str2)
{
    int n1=str1.length();
    int n2=str2.length();
        
    // if str1 = 003234 it will be 3234
    int i=0;
    while(i<n1-1&&str1[i]=='0')i++;
    a=a.substr(i);
        
    // if str2 = 000 it will be 0
    i=0;
    while(i<n2-1&&str2[i]=='0')i++;
    b=b.substr(i);
        
    // resize length of a and b
    n1=a.length();
    n2=b.length();
        
    if(n1<n2)
        return false;
    if(n1>n2)
        return true;
    for(int i=0;i<n1;i++)
    if(str1[i]<str2[i])
        return false;
    else if(str1[i]>str2[i])
        return true;
    return false;
    
}
string findDiff(string str1,string str2)
{
    if(islarger(str1,str2))
        swap(str1,str2);
        
    int n1=str1.length();
    int n2=str2.length();
    
    string str;
    int carry = 0;
    
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    
    for(int i=0;i<n1;i++)
    {
        int sub = (str2[i]-'0') - (str1[i]-'0') - carry;
        if(sub<0)
        {
            sub+=10;
            carry=1;
        }
        else 
            carry=0;
        str.push_back(sub+'0');
    }
    for(int i=n1;i<n2;i++)
    {
        int sub = (str2[i]-'0') - carry;
        if(sub<0)
        {
            sub+=10;
            carry=1;
        }
        else
            carry=0;
        str.push_back(sub+'0');
    }
    reverse(str.begin(),str.end());
    return str;

}
```
Time complexity : O(n1 + n2)