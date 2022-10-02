/*
[PW S2 P2] Super Primes!
2 is not a super prime.
3 is not a super prime. 
but 5 is a super prime number!
Why? 
Consider the list of all the prime numbers AllPrimes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29 ...] 
If you observe the indecies of these numbers, it can be seen that
index of 2 is 0 -- 0 is not a prime number
index of 3 is 1 -- 1 is not a prime number
index of 5 is 2 -- 2 is a prime number!
Therefore super primes are numbers in AllPrimes that have prime index. 
Write a C++ program that takes an integer n as input and outputs the sum of the first n super primes. 
Note: The program needs more than just a couple of for loops if you want it to work for large input values of n. Keep this in mind if you want to write a perfect program.
Example 1:
Input:
5
Output:
81
Explanation: 
Allprimes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 ... ]
The first 5 super primes are evidently [5, 7, 13, 19, 37] and there sum is 81.
Example 2:
Input:
100
Output:
160312
*/
#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n; 
    int number = 5,count = 0;
    int factors_count;
    int index = 1;
    int sum = 0;
    while(count <= n-1)          // Iterating till i get 5 super primes
    {
        int i;
        factors_count = 0;
        for(i = 2; i < number; i++)    // Calculating if a number is a prime or not
        {
            if(number % i == 0)
            {
                factors_count  = factors_count + 1;         // Checking if factors exist for that number
            }
        }
        if(factors_count == 0)        // If its prime then check if the index of that prime number is a prime
        {
            int index_factors_count = 0;
            index = index + 1;
            for(int j = 2; j < index; j++)              // Checkng if index is a prime number or not 
            {
                if(index % j == 0)
                {
                    index_factors_count = index_factors_count + 1; 
                }
            }
            if(index_factors_count == 0)              // If its super prime
            {
                count = count + 1;                   
                sum = sum + number;                  // Then add the number to sum
            }
        }
        number = number + 1;
    }
    cout << sum;
}