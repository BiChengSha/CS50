#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //printf("hello, world\n");
    string username = get_string("What is your name?: ");
    printf("hello, %s\n", username);
}