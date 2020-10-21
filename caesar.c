#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//main function of the program
int main(int argc, string argv[])
{
    //checks if there is key provided or not
    if (argc != 2)
    {
        printf("Usage : ./caesar key\n");
        return 1;
    }
    else
    {
        //checks for non numeric key
        for (int i = 0; i < strlen(argv[1]); i++)
            if (argv[1][i] > 57 || argv[1][i] < 48)
            {
                printf("Usage : ./caesar key\n");
                return 1;
            }
        //converts key into integer type    
        int k = atoi(argv[1]);
        if (k < 0)
        {
            printf("enter positive key\n");
            return 1;
        }
        //prompts user for plain text
        string ptext = get_string("Plain text:");
        string ctext = ptext;
        int n = strlen(ptext);
        for (int i = 0; i < n; i++)
        {
            if (ptext[i] >= 97 && ptext[i] <= 122)
            {
                ctext[i] = ((ptext[i] - 97 + k) % 26) + 97;
            }
            else  if (ptext[i] >= 65 && ptext[i] <= 90)
            {
                ctext[i] = ((ptext[i] - 65 + k) % 26) + 65;
            }


        }

        //prints cipher text
        printf("ciphertext:%s\n", ctext);
        return 0;
    }


}
