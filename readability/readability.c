#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // User prompt
    string text = get_string("Text: ");

    // Check length of a string
    int i = strlen(text);

    int letters = 0;
    int words = 0;
    int sentences = 0;

    // Loop for counting
    for (int x = 0; x < i; x++)
    {
        // Count letters
        char c = text[x];
        if (isalpha(c) != 0)
        {
            letters++;
        }

        // Count words
        if (c == ' ')
        {
            words++;
        }

        // Count Sentences
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // Account for last word
    words = words + 1;

    // Calculate the readability
    float L = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;
    float subindex = 0.0588 * L - 0.296 * s - 15.8;
    int index = round(subindex);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}