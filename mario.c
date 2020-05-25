#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("Height: ");
    
    while ((height > 8) || (height < 1))
    {
        height=get_int("Invalid enty.\nEnter a value between 1 and 8 inclusive: ");
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}