#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string plaintext, ciphertext;
    int key, keyLength, inputLength;

    if (argc != 2)                                                              //rejects any runs without an additional argument
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    keyLength = strlen(argv[1]);                                                //counts string length for loop

    for (int i = 0; i < keyLength; i++)                                         //loops through each char entered and rejects invalid char
    {
        if (!isdigit(argv[1][i]))                                               //checks if char is NOT a valid digit
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    key = atoi(argv[1]);                                                        //assigns key value as whatever was entered

    //printf("argv[1]: %s\nkey: %i\n", argv[1], key);

    if (key < 0)                                                                //check if key is valid entry (non negative)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    plaintext = get_string("plaintext: ");                                      //grabs user input for plaintext string

    ciphertext = plaintext;                                                     //initialize empty string (char array) to allocate memory & to change values non-destructively

    inputLength = strlen(plaintext);                                            //counts string length for loop

    for (int i = 0; i < inputLength; i++)                                       //loops through to change characters as necessary
    {
        if (islower(plaintext[i]))                                              //check for lowercase character
        {
            ciphertext[i] = ((((plaintext[i] + key) - 97) % 26) + 97);          //reduces value to any value between 0 and 26, then adds to 97 to find valid lowercase character
        }
        else if (isupper(plaintext[i]))                                         //check for uppercase character
        {
            ciphertext[i] = ((((plaintext[i] + key) - 65) % 26) + 65);          //reduces value to any value between 0 and 26, then adds to 65 to find valid uppercase character
        }
        else                                                                    //non letters fall here
        {
            ciphertext[i] = plaintext[i];                                       //no changes required
        }
    }
    printf("ciphertext: %s\n", ciphertext);                                     //print final cipher text
}