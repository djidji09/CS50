#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc > 2 || argc <= 1 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`

    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string text = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            // call rotate function
            printf("%c", rotate(text[i], key));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

// Make sure every character in argv[1] is a digit

bool only_digits(string s)
{
    bool a = true;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
        }
        else
        {
            a = false;
        }
    }
    return a;
}
// For each character in the plaintext:

// Rotate the character if it's a letterd
char rotate(char c, int n)
{
    char rotated = 'a';
    if (islower(c))
    {
        c = c - 'a';
        rotated = ((c + n) % 26) + 'a';
    }
    else if (isupper(c))
    {
        c = c - 'A';
        rotated = ((c + n) % 26) + 'A';
    }
    return rotated;
}
