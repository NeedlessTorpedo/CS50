#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change Owed: ");             //Asks the user for input
    }
    while (dollars < 0);
    
    int cents = round(dollars * 100);                           //Converts dollars into cents.
    int coinsUsed = 0;                                           //Keeps track of how many coins are used
    int change = cents; 
    
    
    while(change>=25) {                                 //Gives a quarter and adds the number of coin used while the change is greater than or equal to 25
        change -= 25;
        coinsUsed+=1;
    }
    
    while(change>=10) {                                 //Gives a quarter and adds the number of coin used while the change is greater than or equal to 10
        change -= 10;
        coinsUsed++;
    }
    
    while (change>=5) {                                 //Gives a quarter and adds the number of coin used while the change is greater than or equal to 5
        change -= 5;
        coinsUsed++;
    }
    
    while (change>=1) {                                 //Gives a quarter and adds the number of coin used while the change is greater than or equal to 1
        change -= 1;
        coinsUsed++;
    }
    
    printf("%i\n", coinsUsed);

    
}
