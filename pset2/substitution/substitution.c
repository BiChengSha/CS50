#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string plaintext, ciphertext, key; //keyUpper, keyLower;
    int keyLength, inputLength, index = 0;
    char keyUpper[2][26], keyLower[2][26];

    //printf("Beginning program...\n");

    if (argc != 2)
    {
        //printf("Checking inside argc != 2...\n");
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //printf("Assigning keyLength...\n");
    keyLength = strlen(argv[1]);
    //printf("keyLength assigned.\n");

    if (keyLength != 26){
        //printf("Checking inside keyLength != 26...\n");
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //printf("Assigning main key...\n");
    key = argv[1];
    //printf("Main key assigned. key is %s.\n", key);

    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(key[i]);
    }

    //printf("checking for duplicate characters in key...\n");
    for (int i = 0; i < keyLength - 1; i++)
    {
        for (int j = i + 1; j < keyLength; j++)
        {
            if (key[i] == key[j])
            {
                printf("duplicate characters found in key.\n");
                return 1;
            }
        }
    }

    //printf("looping through characters...\n");
    for (int i = 0; i < keyLength; i++)
    {
        //printf("loop #%i...\n", i);
        if (!isalpha(key[i])){
            //printf("checking !isalpha(key[%i])... key[%i] is %c\n", i, i, key[i]);
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    //printf("Passed checks. Initializing upper and lower keys...\n");
    //printf("Main key is %s.\n", key);

    for (int i = 0; i < 26; i++)
    {
        keyUpper[0][i] = 'A' + i;
        keyLower[0][i] = 'a' + i;
    }

    for (int i = 0; i < keyLength; i++)
    {
        if (!isupper(key[i])){
            keyUpper[1][i] = toupper(key[i]);
        }
        else
        {
            keyUpper[1][i] = key[i];
        }
        if (!islower(key[i])){
            keyLower[1][i] = tolower(key[i]);
        }
        else
        {
            keyLower[1][i] = key[i];
        }
    }

    //printf("keyUpper: ");
    for (int i = 0; i < 26; i++)
    {
        printf("%c", keyUpper[1][i]);
    }
    printf("\n");

    //printf("keyLower: ");
    for (int i = 0; i < 26; i++)
    {
        printf("%c", keyLower[1][i]);
    }
    //printf("\n");

    //printf("Upper and lower keys initialized.\n");

    plaintext = get_string("plaintext: ");

    inputLength = strlen(plaintext);

    ciphertext = malloc(inputLength + 1);
    strcpy(ciphertext, plaintext);

    //printf("looping through plaintext...\n");
    for (int i = 0; i < inputLength; i++)
    {
        if (islower(plaintext[i]))
        {
            //printf("plaintext[%i] is lower.\n", i);
            while (ciphertext[i] == plaintext[i])
            {
                if (plaintext[i] == keyLower[0][index])
                {
                    //printf("assigning ciphertext[%i] as keyLower[1][%i]...\n", i, index);
                    ciphertext[i] = keyLower[1][index];
                    //printf("ciphertext[%i] (%c) should be keyLower[1][%i] (%c)...\n", i, ciphertext[i], index, keyLower[1][index]);
                }
                index++;
            }
            index = 0;

        }
        else if (isupper(plaintext[i]))
        {
            //printf("plaintext[%i] is upper.\n", i);
            /*for (int j = 0; j < 26; j++)
            {
                if (plaintext[i] == keyUpper[0][j])
                {
                    printf("assigning ciphertext[%i] as keyUpper[1][%i]...\n", i, j);
                    ciphertext[i] = keyUpper[1][j];
                    printf("ciphertext[%i] (%c) should be keyUpper[1][%i] (%c)...\n", i, ciphertext[i], j, keyUpper[1][j]);
                }
            }*/

            while (ciphertext[i] == plaintext[i])
            {
                if (plaintext[i] == keyUpper[0][index])
                {
                    //printf("assigning ciphertext[%i] as keyUpper[1][%i]...\n", i, index);
                    ciphertext[i] = keyUpper[1][index];
                    //printf("ciphertext[%i] (%c) should be keyUpper[1][%i] (%c)...\n", i, ciphertext[i], index, keyUpper[1][index]);
                }
                index++;
            }
            index = 0;

        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
        //printf("\n\n");
    }

    printf("ciphertext: ");
    for (int i = 0; i < inputLength; i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}
