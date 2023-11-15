#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declaring the height
    int n;
    // getting the number by forcing the user to type a number between 1 and 8
    do
    {
        n = get_int("height = ");

    }
    while ((n > 8) || (n < 1));

    // the pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i + 1; j--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}