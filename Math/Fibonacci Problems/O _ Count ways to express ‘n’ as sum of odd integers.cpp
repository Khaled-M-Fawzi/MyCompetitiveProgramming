/*

count ways to express ‘n’ as sum of odd integers
Given an positive integer n. Count total number of ways to express ‘n’ as sum of odd positive integers.

Input: 4
Output: 3

Explanation
There are only three ways to write 4
as sum of odd integers:
1. 1 + 3
2. 3 + 1
3. 1 + 1 + 1 + 1

Input: 5
Output: 5
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Simple approach is to find recursive nature of problem. The number ‘n’ can be written as 
sum of odd integers from either (n-1)th number or (n-2)th number. Let the total number
of ways to write ‘n’ be ways(n). The value of ‘ways(n)’ can be written by recursive formula as follows:

ways(n) = ways(n-1) + ways(n-2)
The above expression is actually the expression for Fibonacci numbers
Therefore problem is reduced to find the nth fibonnaci number.

ways(1) = fib(1) = 1
ways(2) = fib(2) = 1
ways(3) = fib(2) = 2
ways(4) = fib(4) = 3

Complexity : O(Logn)

*/
