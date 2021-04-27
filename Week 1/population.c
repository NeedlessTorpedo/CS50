#include <cs50.h>
#include <stdio.h>

void calc_years(int s_size, int e_size);
int main(void)
{
    
    // TODO: Prompt for start size
    // Asks the user's input for a value greater than or equal to 9.
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while(start_size < 9);
    
    // TODO: Prompt for end size
    // Asks the user's input for a value greater than or equal to the starting size.
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while(end_size < start_size);

    // TODO: Print number of years
    calc_years(start_size, end_size);

    
}

// TODO: Calculate number of years until we reach threshold
// Function that calculates the approximate years needed to reach the end size
void calc_years(int s_size, int e_size) 
{
    int per_year = s_size + s_size / 3 - s_size/4;                  //Population in one year based on the starting size
    int year = 1;
        
    while (per_year < e_size)                                   //While Loop that stops if the population is about to be greater than the end size
    {
        per_year = per_year + per_year/3 - per_year/4;
        year++;
    }
    printf("Years: %i\n", year);
}
