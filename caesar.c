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
    int keyLength, key, ptLength, backwards;

    if (argc == 2)
    {
        argument = argv[1];

        keyLength = strlen(argument);

        for (int i = 0; i < keyLength; i++)
        {
            tempChar = argument[i];
            printf("tempChar: %c\n", tempChar);
            if (tempChar < 48 || tempChar > 57)
            {
                valid++;
            }
        }

        if (valid == 0)
        {
            printf("Entered: %i. SUCCESS\n", atoi(argument));
            plaintext = get_string("plaintext: ");
            ciphertext = plaintext;
            ptLength = strlen(plaintext);
            key = atoi(argument);

            while (key > 26)
            {
                key = key - 26;
            }
            backwards = 26 - key;
            printf("key & backwards: %i, %i\n", key, backwards);

            for (int i = 0; i < ptLength; i++)
            {
                printf("\n\n\nLoop #%i\n", i);
                printf("plaintext[%i]: %c\n", i, plaintext[i]);
                //printf("plaintext[%i] + key: %c\n", i, plaintext[i] + 1);
                if ((plaintext[i] >= 'A') && (plaintext[i] <= 'Z'))
                {
                    printf("Made it to A-Z\n");
                    if (plaintext[i] + key > 'Z')
                    {
                        printf("looping around\n");
                        ciphertext[i] = plaintext[i] - backwards;
                        printf("plaintext[%i] - backwards: %c\n", i, (plaintext[i] - backwards));
                        printf("ciphertext[%i]: %c\n", i, ciphertext[i]);
                    }
                    else
                    {
                        printf("no loop needed\n");
                        ciphertext[i] = plaintext[i] + key;
                        printf("plaintext[%i] = %c, plaintext[%i] + key: %c\n", i, plaintext[i], i, (plaintext[i] + key));
                        printf("ciphertext[%i]: %c\n", i, ciphertext[i]);
                    }
                }
                else if ((plaintext[i] >= 'a') && (plaintext[i] <= 'z' - 1))
                {
                    printf("Made it to a-z\n");
                    if (plaintext[i] + key > 'z')
                    {
                        printf("looping around\n");
                        ciphertext[i] = 'z' - backwards;
                        printf("plaintext[%i] - backwards: %c\n", i, (plaintext[i] - backwards));
                        printf("ciphertext[%i]: %c\n", i, ciphertext[i]);
                    }
                    else
                    {
                        printf("no loop needed\n");
                        ciphertext[i] = plaintext[i] + key;
                        printf("plaintext[%i] + key: %c\n", i, (plaintext[i] + key));
                        printf("ciphertext[%i]: %c\n", i, ciphertext[i]);
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