/*
Palindrome Numbers


A palindromic number is a number (such as 626) that remains the same when its digits are reversed.
Write a function that returns true if a given number is a palindrome, and false, if it is not.
Complete the given function, so that the code in main works and results in the expected output.

Sample Input:
13431

Sample Output:
13431 is a palindrome
*/
#include <iostream>
using namespace std;

int revDigit(int y){
    int rem,rev=0;
    while(y>0){
        rem=y%10;
        rev=rev*10+rem;
        y/=10;
        
    }return rev;
}

bool isPalindrome(int x) {
    //complete the function
    if(x==revDigit(x)){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    int n;
    cin >>n;
    
    if(isPalindrome(n)) {
        cout <<n<<" is a palindrome";
    }
    else {
        cout << n<<" is NOT a palindrome";
    }
    return 0;
}