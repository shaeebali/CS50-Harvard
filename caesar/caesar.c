#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Confirms two arguments
    if (argc == 2)
    {
        // Iteration of key and positive integer
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            // Returns error message
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        // Plaintext to ciphertext
        for (int i = 0; i < strlen(plaintext); i++)
        {

            if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                printf("%c", ((((plaintext[i] - 'a') + key) % 26) + 'a'));
            }

            else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                printf("%c", ((((plaintext[i] - 'A') + key) % 26) + 'A'));
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
    // Returns error message when code is not in the correct form
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}