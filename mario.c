#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("Height: ");
    
    while ((height > 8) || (height < 1))
    {
        height = get_int("Invalid enty.\nEnter a value between 1 and 8 inclusive: ");
    }

    for (int i = 0; i < height; i++) //makes the rows
    {
        for (int j = 1; j < height - i; j++)
        {
            printf(" "); //prints the leading spaces
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#"); //prints a portion of the triangle leaning right
        }
        printf("  "); //prints the two space middle
        for (int j = 0; j <= i; j++)
        {
            printf("#"); //prints a portion of the triangle leaning left
        }
        printf("\n"); //creates the next row
    }
}