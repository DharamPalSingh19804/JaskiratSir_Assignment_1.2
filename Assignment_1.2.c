/*
<---------------------------------Problem Statement--------------------------------------------->
You are required to write a C/C++ program to perform the following tasks:
1. Generate 50 random integers
2. Determine the highest base of each of randomly generated 50 integers using
the formula: Highest base of an integer = max(all the digits in an
integer) + 1. For example, the highest base of 456 = max(4,5,6)
= 6+1 = 7.
Your program should adhere to the following requirements:
• The program should generate 50 random integers where the integer should
exactly have 10 digits with last place digit should be at least 5. That is,
your number can be 5294967296 but it can not be 4294967296.
• The program should also print a nice message for each of the 50 Random
Integers, saying that ”The Highest Base of a 5294967296 is 10.”
*/


#include <stdio.h>         // these libraries provide functions for input/output operations, memory allocation, and time-related functions
#include <stdlib.h>
#include <time.h>          // generate different for different times

unsigned long long generateRandomNumber(unsigned long long min, unsigned long long max)              // generating 50 unsigned random integer between min and max (inclusive)
{
    return ((unsigned long long)rand() % (max - min + 1)) + min;                                     // no issues we if remove it 
}


int findHighestDigit(unsigned long long number)               // now here we are creating a function to find the highest digit in a number
{
    int maxDigit = 0;                                        //  initializing a variable(see for maximum digit)
    while (number > 0) {                                     // extracting each digit one by one , 
        int digit = number % 10;
        if (digit > maxDigit) {                              // current digit ko maxdigit jo aya hai usse compare krega then agr ha ya na toh uske according 10 se phit divide kr dega
            maxDigit = digit;
        }
        number /= 10;
    }
    return maxDigit;
}

int main()
 {                                                           // now here we are seeding the random number generator with the current time
    
    srand(time(0));

    for (int j = 0; j < 50; j++)
    {
                                                            //generating the first digit (between 6 and 9) as asked in the question
        int firstDigit = generateRandomNumber(6, 9);

        
        unsigned long long base = 0;                          //// generating the remaining 9 digits randomly (between 0 and 9)
        for (int i = 0; i < 9; i++)
        {
            base = base * 10 + generateRandomNumber(0, 9);
        }

      
        unsigned long long randomNumber = (unsigned long long)firstDigit * 1000000000ULL + base;     // now here we will combine both to get the 10-digit unsignd random integer

        printf("Random 10-digit integer %d: %llu\n", j + 1, randomNumber);
        printf("The Highest Base of a %llu is %d.\n", randomNumber, findHighestDigit(randomNumber) + 1);
    }

    return 0;
}
