#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // this the main function
    string text = get_string("text: ");
    float letters = count_letters(text);
    printf("letters = %i\n", count_letters(text));
    float words = count_words(text);
    printf("words = %i\n", count_words(text));
    float sentences = count_sentences(text);
    printf("sentences = %i\n", count_sentences(text));
    float l = letters / words * 100;
    printf("l = %f\n", l);
    float s = sentences / words * 100;
    printf("s = %f\n", s);
    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.f\n", round(index));
    }
}

int count_letters(string text)
{
    // this function is counting letters
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // this function is counting words
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words + 1;
}
int count_sentences(string text)
{
    // this function is counting sentences
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
