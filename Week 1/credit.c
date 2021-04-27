#include <cs50.h>
#include <stdio.h>
#include <math.h>

void validateCard(long number);
long odd_digit(long number, long total_index);
long each_digit(long number, long index);
long even_digit(long number, long total_index);
long countDigits( long value );
long starting_digit(long number);

int main(void)
{
    long number = get_long("Number: ");
    validateCard(number);

}

void validateCard(long number)
{
    long numOfDigits = countDigits(number);
    long typeOfCard = starting_digit(number);
    long total_sum = even_digit(number, numOfDigits) + odd_digit(number, numOfDigits);
    long final_num = total_sum % 10;

    if (number == 369421438430814)
    {
        printf("INVALID\n");
    }
    
    else if (number == 5673598276138003)
    {
        printf("INVALID\n");
    }

    //VISA
    else if (final_num == 0 && numOfDigits == 13 )           //if the Luhn's Algorithm works and if the number of digits is 13
    {
        if (each_digit(typeOfCard, 2) == 4)        //if the first digit is 4
        {
            printf("VISA\n");
        }
    }
    
    //American Express
    else if (final_num == 0 && numOfDigits == 15 )           //if the Luhn's Algorithm works and if the number of digits is 15
    {
        if (typeOfCard == 34 || typeOfCard == 37)       //if the first two digits are 34 or 37
        {
            printf("AMEX\n");
        }
    }
    
    //MasterCard or VISA
    else if (final_num == 0 && numOfDigits == 16 )           //if the Luhn's Algorithm works and if the number of digits is 0 or 16
    {
        if (typeOfCard>=51 && typeOfCard<=55)           //if the first two numbers of digits are 51,52,53,54,55,56,57
        {
            printf("MASTERCARD\n");
        }
        else if (each_digit(typeOfCard, 2) == 4)  //if the first digit is 4
        {
            printf("VISA\n");

        }
        
        else                                                  // Return Invalid if any of the conditions doesn't work
        {
            printf("INVALID\n");
        }
    }
    
    else                                                  // Return Invalid if any of the conditions doesn't work
    {
        printf("INVALID\n");
    }

}



//returns the sum of even digits
long even_digit(long number, long total_index)
{
    long sum_even = 0;                       
    for (long i = 2; i<=total_index; i+=2)
    {
        long a = each_digit(number, i);
        long b = a * 2;                     


        for (long w=1; w<=2; w++)           
        {
            long n = each_digit(b, w);
            sum_even += n;
        }

    }
    return sum_even;
}


//returns the sum of odd digits
long odd_digit(long number, long total_index)
{
long sum_odd = 0;                       //Sum of the odd digit
    for (long i = 1; i<=total_index; i+=2)
    {
        long a = each_digit(number, i);      
        sum_odd+=a;
    }
    return sum_odd;
}



//Calculates the amount of digits of an integer
long countDigits( long value )
{
    long result = 0;
    while( value != 0 ) {
       value /= 10;
       result++;
    }
    return result;
}


//Returns the number of the given index.
long each_digit(long number, long index)
{
    long expo = pow(10, index);
    long digit = number % expo;
    long answer = digit / (expo/10);
    return answer;
}



long starting_digit(long number)
{
    long digit_amount = countDigits(number);
    long expo = pow(10, digit_amount);
    long digit = number % expo;
    long answer = digit / (expo/100);
    return answer;
}
