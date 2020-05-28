#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string sentence = get_string("Text: ");
    int charCount = 0;
    int wordCount = 0;
    int sentenceCount = 0;
    int enteredLength = strlen(sentence);
    int indexRound;
    char lastChar = ' ';
    char thisChar;
    float averageLetters, averageWords, index;

    for (int i = 0; i < enteredLength; i++)
    {
        if (((sentence[i] >= 'A') && (sentence[i] <= 'Z')) || ((sentence[i] >= 'a') && (sentence[i] <= 'z')))
        {
            charCount++;
        }
    }

    //printf("%i letter(s)\n", charCount);

    for (int i = 0; i < enteredLength; i++)
    {
        thisChar = sentence[i];
        if ((((thisChar >= 'A') && (thisChar <= 'Z')) || ((thisChar >= 'a') && (thisChar <= 'z'))) &&
            (((lastChar == ' ') || (lastChar == 34)) && (lastChar != '-')))
        {
            wordCount++;
        }
        lastChar = thisChar;
    }

    //printf("%i word(s)\n", wordCount);

    for (int i = 0; i < enteredLength; i++)
    {
        if ((sentence[i] == '.') || (sentence[i] == '!') || (sentence[i] == '?'))
        {
            sentenceCount++;
        }
    }

    //printf("%i sentence(s)\n", sentenceCount);

    averageLetters = (float) charCount / wordCount * 100;
    averageWords = (float) sentenceCount / wordCount * 100;
    index = (0.0588 * averageLetters) - (0.296 * averageWords) - 15.8;

    //printf("Average character count per 100 words: %.4f\n", averageLetters);
    //printf("Average word count per 100 sentences: %.4f\n", averageWords);
    //printf("Index value is %.4f.\n", index);

    indexRound = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((index >= 1) && (index < 16))
    {
        printf("Grade %i\n", indexRound);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("WTF????\n");
    }
}
