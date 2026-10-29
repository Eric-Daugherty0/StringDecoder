/*
Name: Eric Daugherty
Date: 10/11/2026
Purpose: This program reads a word or phrase 
from the user and encodes it with the decoder 
chart by replacing each letter with its coded letter.
*/

 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "Daugherty-StringDecoder.h"

int main(void)
{
    // Decoder chart that replaces each letter with its coded equivalent
    const char chart[] = "HIVJKWLAMYNBXOZCTPUDQSREGF"; 

    char original[MAX_LEN];
    char encoded[MAX_LEN];
    int again = 1;

    while (again)
    {
        printf("====================================\n");   
        printf("| Enter a word or phrase to encode | "); 
        printf("\n====================================\n");
        readLine(original, MAX_LEN);

        encodeString(original, encoded, chart);

        printf("\nOriginal word: %s\n", original);
        printf("Encoded word:  %s\n\n", encoded);

        again = askToRepeat();
    }

    printf("Program has ended.\n");
    return 0;
}

// Reads a line of text from the keyboard and removes the newline.
void readLine(char line[], int size)
{
    size_t len;
    int ch;

    if (fgets(line, size, stdin) == NULL)
    {
        line[0] = '\0';
        return;
    }

    len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
    {
        line[len - 1] = '\0';
    }
    else
   {
        // Line was too long; throw away the rest of it 
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }
}

// Encodes each letter using the chart. characters that are 
//not letters spaces, digits, punctuation are left unchanged.
void encodeString(const char original[], char encoded[], const char chart[])
{
    int i = 0;
    int index;
    char coded;

    while (original[i] != '\0')
    {
        if (isalpha((unsigned char)original[i]))
       {
            index = toupper((unsigned char)original[i]) - 'A';
            coded = chart[index];

            if (islower((unsigned char)original[i]))
            {
                coded = (char)tolower((unsigned char)coded);
            }
            encoded[i] = coded;
        }
        else
        {
            encoded[i] = original[i];
        }
        i++;
    }
    encoded[i] = '\0';
}

// Asks the user whether to run again. Keeps asking until Y or N is entered.
int askToRepeat(void)
{
    char answer[MAX_LEN];
    char c;

    while (1)
    {
        printf("Encode another word? (Y/N): ");
        readLine(answer, MAX_LEN);

        c = answer[0];

        if (c == 'Y' || c == 'y')
        {
            return 1;
        }
        if (c == 'N' || c == 'n')
        {
            return 0;
        } 
        else
        {
            printf("Please enter Y or N.\n");
        }   
   }
}