/*
The Fibonacci sequence is defined by the recurrence relation:
F1 = 1 and F2 = 1
Fn = Fn−1 + Fn−2, for n > 2
Hence the first 12 terms will be:
F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.
What is the index of the first term in the Fibonacci sequence to contain N digits?
Example 1:
Input:
3
    where: N = 3 is the number of digits
Output:
12
    Explanation: F12 = 144 and it is the first term in the sequence to contain 3 digits.
Example 2:
25
Output:
17
*/
#include<iostream>
using namespace std;
int countDigit(long long n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}
int fib(int n)
{
    int a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for(i = 2; i <= n; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}
int main()
{
    int n;
    cin>>n;
    int count = 0;
    for(int i = n;countDigit(fib(i))!=n;i++)
    {
        count++;
    }
    cout<<count+n;
}
