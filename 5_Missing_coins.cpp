/*
[PW S1 P3] Missing coins sum
Tags:	pw1
You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?
Input
The first input line has an integer n: the number of coins.
The second line has n integers  x1,x2,…,xn: the value of each coin.
Output
Print one integer: the smallest coin sum.
Input:
5
2 9 1 2 7
Output: 6
*/
#include<iostream>
using namespace std;

int main(){
    int n;    
    cin>>n;    
    int arr[n];   
    for(int i=0; i<n; i++){
        cin>>arr[i];    
    }
    
    int res = 1;
    // Traverse the array and increment 'res' if arr[i] is smaller than or equal to 'res'.
    for(int i=0; i<n && arr[i]<=res; i++)
    {
        res = res + arr[i];    
    }
    cout<<res;    

}