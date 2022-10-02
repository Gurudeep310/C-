/*
[PW S2 P3] To Crush a number!
Take number such as 3467. 
To 'crush' it, you just have to subtract from it the sum of its digits. Which yields 3467 - (3 + 4 + 6 + 7) = 3447.
You can crush it again: 3447 - (3 + 4 + 4 + 7) = 3429.
You can crush it again and again until if no longer is a positive integers. 
Write C++ program that takes a number n as an input and returns the number of crushes it takes before the number is no longer positive. 
Example 1
Input:
57
Output:
6
Explantion: Self evident.  57 -> 45 -> 36 -> 27 -> 18 -> 9 -> 0 
*/
#include<iostream>
#include<cstdio>
using namespace std;

class ProblemSolution{
    public:
       int solution(int N);
};

int fun(int N, int count) 
{
    int sum = 0;
    if(N<=0)    
        return count;                       // Returning number of iterations taken to reach 0
    else 
    {
        int number = N;
        while(number > 0)                    // Splitting a number to a digit
        { 
            int digit = number % 10;
            number = number / 10;
            sum = sum + digit;              // Summing up all the digits
        }
        N = N - sum;                      // Subtracting sum og digits from number
        number = N; 
        count = count + 1;               // Updating count
        return fun(N,count);             // Calling the fn again as N > 0
    }
}

int ProblemSolution :: solution(int N)
{
    int count = 0;
    int k = fun(N,count);                  // calling function fun
    return k;                        
}

int main()
{
    int N;
    cin >> N;
    ProblemSolution problemSolution;
    cout << problemSolution.solution(N);
}