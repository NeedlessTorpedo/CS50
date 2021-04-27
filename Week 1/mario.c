#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Asks User's input
    int dimension;
    do
    {
        dimension = get_int("Height: ");
    }
    while (dimension<1 || dimension>8);

    for (int j=1; j<=dimension; j++)
    {
        //left hashes' space
        for (int i=dimension; i>j; i--)
        {
            printf(" ");
        }

        //left hashes
        for (int b=0; b<j; b++)
        {
            printf("#");
        }

        //middle space
        for (int i = 0; i<2; i++)
        {
            printf(" ");
        }


        //right hashes
        for (int b=0; b<j; b++)
        {
            printf("#");
        }



        //new line
        printf("\n");

        }







}


