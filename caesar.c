#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    string plaintext, ciphertext;
    int key, keyLength, inputLength;

    //conditional to check for two arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    keyLength = strlen(argv[1]);

    for (int i = 0; i < keyLength; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    key = atoi(argv[1]); //assigns key value as whatever was entered
    printf("argv[1]: %s\nkey: %i\n", argv[1], key);

    //check if key is valid entry
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    //encrypt here
    plaintext = get_string("plaintext: ");
    ciphertext = plaintext;

    inputLength = strlen(plaintext);


    /*for (int i = 0; i < inputLength; i++)
    {
        printf("plaintext[%i]: %c\n", i, plaintext[i]);
    }*/

    for (int i = 0; i < inputLength; i++)
    {
        if (islower(plaintext[i])) //check for lowercase character
        {
            //printf("placeholder for lowercase\n");
            ciphertext[i] = ((((plaintext[i] + key) - 97) % 26) + 97);
            //printf("%c\n", ciphertext[i]);
        }
        else if (isupper(plaintext[i])) //check for uppercase character
        {
            //printf("placeholder for uppercase\n");
            ciphertext[i] = ((((plaintext[i] + key) - 65) % 26) + 65);
            //printf("%c\n", ciphertext[i]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
            //printf("%c\n", ciphertext[i]);
        }
        //printf("\n");
    }
    printf("ciphertext: %s\n", ciphertext);
}