/*

Multiply Large Numbers represented as Strings
Given two numbers as strings. The numbers may be very large (may not fit in long long int)
the task is to find product of these two numbers.

Input : num1 = 4154  
        num2 = 51454
Output : 213739916 

Input :  num1 = 654154154151454545415415454  
         num2 = 63516561563156316545145146514654 
Output : 41549622603955309777243716069997997007620439937711509062916

The idea is based on school mathematics multiplication

We start from last digit of second number multiply it with first number
Then we multiply second last digit of second number with first number, and so on
We add all these multiplications. While adding, we put i-th multiplication shifted

The approach used in below solution is to keep only one array for result
We traverse all digits first and second numbers in a loop and add the result at appropriate position.

*/


string multiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
    vector<int> result(len1 + len2, 0); 
    int i_n1 = 0;  
    int i_n2 = 0;  
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
        i_n2 = 0;       
        for (int j=len2-1; j>=0; j--) 
        { 
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
    if (i == -1) 
    return "0"; 
    
    string s = ""; 
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 
int main() 
{ 
    string str1 = "1235421415454545454545454544"; 
    string str2 = "1714546546546545454544548544544545"; 
      
    if((str1.at(0) == '-' || str2.at(0) == '-') &&  
        (str1.at(0) != '-' || str2.at(0) != '-' )) 
        cout<<"-"; 
  
  
    if(str1.at(0) == '-' && str2.at(0)!='-') 
        { 
            str1 = str1.substr(1); 
        } 
        else if(str1.at(0) != '-' && str2.at(0) == '-') 
        { 
            str2 = str2.substr(1); 
        } 
        else if(str1.at(0) == '-' && str2.at(0) == '-') 
        { 
            str1 = str1.substr(1); 
            str2 = str2.substr(1); 
        } 
    cout << multiply(str1, str2); 
    return 0; 
} 
// Time Complexity: O(m*n), where m and n are length of two number that need to be multiplied
