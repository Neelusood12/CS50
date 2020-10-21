#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//function prototypes
int letters(string text);
int words(string text);
int sentences(string text);
void index(int L, int W, int S);

//The main function of the program
int main(void)
{
    string text = get_string("Text:");
    //letters
    int L = letters(text);
    //words
    int W = words(text);
    //sentences
    int S = sentences(text);
    printf("%i letter(s)\n", L);
    printf("%i word(s)\n", W);
    printf("%i sentence(s)\n", S);
    index(L, W, S);
}


//function to count letters
int letters(string text)
{
    int l = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }
    }
    return l;
}



//function to count words
int words(string text)
{
    int w = 1;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if ((char) text[i] == ' ')
        {
            w++;
        }
    }
    return w;
}



//function to count sentences
int sentences(string text)
{
    int s = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if ((char) text[i] == '.' || (char) text[i] == '?' || (char) text[i] == '!')
        {
            s++;
        }
    }
    return s;
}



//function to calculate index
void index(int L, int W, int S)
{
    float l = ((float) L / W) * 100;
    float s = ((float) S / W) * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int n = round(index);
    if (n < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (n > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", n);
    }
}
