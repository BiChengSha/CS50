/////////////INCOMPLETE CODE////////////////
///////////////ABANDONDED///////////////////

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string plaintext, ciphertext, key; //keyUpper, keyLower;
    int keyLength, inputLength;
    char keyUpper[26][26], keyLower[26][26;]

    printf("Beginning program...\n");

    if (argc != 2)
    {
        printf("Checking inside argc != 2...\n");
        printf("Usage: ./substitution key\n");
        return 1;
    }

    printf("Assigning keyLength...\n");
    keyLength = strlen(argv[1]);
    printf("keyLength assigned.\n");

    if (keyLength != 26){
        printf("Checking inside keyLength != 26...\n");
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    printf("Assigning main key...\n");
    key = argv[1];
    printf("Main key assigned. key is %s.\n", key);

    printf("looping through characters...\n");
    for (int i = 0; i < keyLength; i++)
    {
        printf("loop #%i...\n", i);
        if (!isalpha(key[i])){
            printf("checking !isalpha(key[%i])... key[%i] is %c\n", i, i, key[i]);
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    printf("Passed checks. Initializing upper and lower keys...\n");
    printf("Main key is %s.\n", key);
    //keyUpper = malloc(keyLength + 1);
    //strcpy(keyUpper, key);
    //keyLower = malloc(keyLength + 1);
    //strcpy(keyLower, key);
    printf("Upper and lower keys initialized.\n");
    //printf("keyUpper: %s\nkeyLower: %s\n", keyUpper, keyLower);


    printf("Looping to change upper and lower keys...\n");
    for (int i = 0; i  < keyLength; i++)
    {
        printf("\nLoop #%i...\n", i);
        printf("Assigning keyUpper[%i]...\n", i);
        if (!isupper(key[i])){
            keyUpper[i] = toupper(key[i]);
        }
        printf("keyUpper[%i] assigned. keyUpper[%i] is %c...\n", i, i, keyUpper[i]);
        printf("Assigning keyLower[%i]...\n", i);
        if (!islower(keyLower[i])){
            keyLower[i] = tolower(key[i]);
        }
        printf("keyLower[%i] assigned. keyLower[%i] is %c...\n", i, i, keyLower[i]);
        printf("key: %s\nkeyUpper: %s\nkeyLower: %s\n", key, keyUpper, keyLower);
    }

    printf("\nkey: %s\nkeyUpper: %s\nkeyLower: %s\n", key, keyUpper, keyLower);

    plaintext = get_string("plaintext: ");
    ciphertext = plaintext;

    inputLength = strlen(plaintext);

    for (int i = 0; i < inputLength; i++)
    {
        if (islower(plaintext[i]))
        {
            ciphertext[i] = ciphertext[i] = ((((plaintext[i] + keyLower[i]) - 97) % 26) + 97);
        }
    }

}
// printf("...\n");
