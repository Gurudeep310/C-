/*
You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has nn integers a1,a2,…,an: the array values.
Output
Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints
1≤n≤1000
1≤x,ai≤109 
Example
Input:
8 15
3 2 5 8 1 3 2 3
Output:
2 4 6 7
*/
#include<iostream>
using namespace std;

int main()
{
    int n, x, g, b, c, d;  
    cin>> n>> x;    
    int arr[n];    
    for(int i=0; i<n; i++)
    {
        cin >>arr[i];    
    }   
    for(int i=0; i<n; i++)
    {
        // Fix the first element and find other three
       for(int j=i+1; j<n; j++)
       {
           // Fix the second element and find other two
            for(int k=j+1; k<n; k++)
            {
                // Fix the third element and find the fourth
                for(int m=k+1; m<n; m++)
                {
                    // find the fourth
                    if(arr[i] + arr[j] + arr[k] + arr[m] == x)
                    {   
                        g = i;    
                        b = j;    
                        c = k;    
                        d = m;    
                    }
                }
            }
        }
    }
    cout<<b+1<<" "<<g+1<<" "<<c+1<<" "<<d+1; 
}