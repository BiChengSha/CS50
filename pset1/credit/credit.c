#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long ccNum = get_long("Enter credit card number: ");
    long placeholder = ccNum;                                       //using this variable to non-destructively check for the length of the number
    long firstDigit = ccNum;                                        //this is to calculate the first digit(s) of the credit card number
    long cardMath = ccNum;                                          //to calculate sum of digits non destructively
    int countLength = 0;                                            //this is the length counter
    int endNum = 0;                                                 //to store the sum of every other number from the end
    int endNum2 = 0;                                                //to store the sum of every other number from the end
    int timesTwo = 0;                                               //to store the sum of every other number from the end
    int secondDigit = 0;                                            //to store the extra number if x2 is more than 9
    int sum;                                                        //sum of all digits

    while (placeholder != 0)                                        //this loop goes through to count the number of digits the number entered has
    {
        placeholder = placeholder/10;                               //every division of 10 is another digit place
        countLength++;                                              //iterate counter
    }

    while(firstDigit >= 100)                                        //this loop determines the first two numbers of the card
    {
        firstDigit = firstDigit / 10;                               //every division is another trailing digit removed
    }

    while (cardMath > 0)
    {
        endNum = endNum + (cardMath % 10);
        cardMath = cardMath / 10;
        //printf("endNum is %i and cardMath is %ld\n", endNum, cardMath);
        timesTwo = (cardMath % 10) * 2;

        if (timesTwo >= 10)
        {
            secondDigit = timesTwo % 10;
            timesTwo = timesTwo / 10;
        }

        endNum2 = endNum2 + secondDigit + timesTwo;
        secondDigit = 0;
        cardMath = cardMath / 10;
        //printf("endNum2 is %i and cardMath is %ld\n", endNum2, cardMath);
    }

    sum = endNum + endNum2;

    //printf("Length of number is %i and the first two numbers are %ld\n", countLength, firstDigit);
    //printf("Sum is %i\n", sum);

    if ((countLength == 13) || (countLength == 16))                 //to determine if Visa or MasterCard length
    {
        if ((firstDigit >= 51) && (firstDigit <= 55))               //check for valid MasterCard leading numbers
        {
            if ((sum % 10) == 0)                                    //check to see if the sum of digits ends in a 0
            {
                printf("MASTERCARD\n");                             //confirms to user card is MasterCard
            }
            else
            {
                printf("INVALID\n");                                //reject non valud MasterCard number
            }
        }
        else
        {
            firstDigit = firstDigit/10;                             //Visa only needs one leading number
            if (firstDigit == 4)                                    //check for valid Visa leading number
            {
                if ((sum % 10) == 0)                                //check to see if the sum of digits ends in a 0
                {
                    printf("VISA\n");                               //confirms to user card is Visa
                }
                else
                {
                    printf("INVALID\n");                            //reject invalid Visa number
                }
            }
            else
            {
                printf("INVALID\n");                                //reject non valid Visa or MasterCard leading number
            }
        }
    }
    else if(countLength == 15)                                      //to determine American Express format
    {
        if((firstDigit == 34) || (firstDigit == 37))                //check for valid American Express leading numbers
        {
            if((sum % 10) == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");                                //reject invalid American Express number
            }
        }
        else
        {
            printf("INVALID\n");                                    //reject non valid American Express leading number
        }
    }
    else
    {
        printf("INVALID\n");                                        //reject any number with incorrect length
    }
}
