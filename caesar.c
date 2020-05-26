#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string argument, plaintext, ciphertext;
    char tempChar;
    int valid = 0;
    int keyLength, key, ptLength;

    if (argc == 2)
    {
        argument = argv[1];

        keyLength = strlen(argument);

        for (int i = 0; i < keyLength; i++)
        {
            tempChar = argument[i];
            //printf("tempChar: %c\n", tempChar);
            if (tempChar < 48 || tempChar > 57)
            {
                valid++;
            }
        }

        if (valid == 0)
        {
            //printf("Entered: %i. SUCCESS\n", atoi(argument));
            plaintext = get_string("plaintext: ");
            ciphertext = plaintext;
            ptLength = strlen(plaintext);
            key = atoi(argument);

            while (key > 26)
            {
                key = key - 26;
            }

            for (int i = 0; i < ptLength; i++)
            {
                //printf("Loop #%i\n", i);
                //printf("plaintext[%i]: %c\n", i, plaintext[i]);
                //printf("plaintext[%i] + 1: %c\n", i, plaintext[i] + 1);
                if ((plaintext[i] >= 'A') && (plaintext[i] <= 'Z'))
                {
                    //printf("Made it to A-Z\n");
                    if (plaintext[i] + key > 'Z')
                    {
                        //printf("looping around\n");
                        ciphertext[i] = 'A' + (key - 'Z' - plaintext[i] - 1);
                    }
                    else
                    {
                        //printf("no loop needed\n");
                        ciphertext[i] = plaintext[i] + key;
                    }
                }
                else if ((plaintext[i] >= 'a') && (plaintext[i] <= 'z' - 1))
                {
                    //printf("Made it to a-z\n");
                    if (plaintext[i] + key > 'z')
                    {
                        //printf("looping around\n");
                        ciphertext[i] = 'a' + (key - 'z' - plaintext[i]);
                    }
                    else
                    {
                        //printf("no loop needed\n");
                        ciphertext[i] = plaintext[i] + key;
                    }
                }
                else
                {
                    ciphertext[i] = plaintext[i];
                }
            }
            printf("ciphertext: %s\n", ciphertext);
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }
}