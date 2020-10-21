#include <stdio.h>
#include <cs50.h>
#include <math.h>

//function prototypes
int check_validity(int n, int Ar[n]);
void check_type(int n, int Ar[n]);

//main function
int main(void)
{
    int k;
    int i;
    long n = get_long("Enter the card number:");
    long t = n;
    //checking for length
    for (k = 0; t > 0; k++)
    {
        t /= 10;
    }
    int Ar[k];
    t = n;
    //getting the number into array
    for (i = 0; i < k; i++)
    {
        Ar[k - 1 - i] = t % 10;
        t /= 10;
    }
    //confirming the valid length
    if (k == 13 || k == 16 || k == 15)
    {
        //checking the mathematical validity of the number
        int c = check_validity(k, Ar);
        if (c == 1)
        {
            printf("INVALID\n");
            return 0;
        }
        else
        {
            check_type(k, Ar);
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

//function to check the mathematical validity of the number
int check_validity(int n, int Ar[n])
{
    int t = 0;
    int k = 0;
    int s = 0;
    int m = 0;
    //loop to calculate sum
    for (int i = n - 2; i >= 0; i -= 2)
    {
        t = Ar[i] * 2;
        if (t >= 10)
        {
            s = 0;
            s = t % 10;
            t /= 10;
            s += t;
            k += s;
        }
        else
        {
            k += t;
        }
    }
    for (int i = n - 1; i >= 0; i -= 2)
    {
        m += Ar[i];
    }
    //condition to check the validity
    if ((m + k) % 10 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//function to check the type of card
void check_type(int n, int Ar[n])
{
    //american express
    if (n == 15 && (Ar[0] == 3 && (Ar[1] == 4 || Ar[1] == 7)))
    {
        printf("AMEX\n");
    }
    //mastercard
    else if (n == 16 && (Ar[0] == 5 && (Ar[1] > 0 && Ar[1] < 6)))
    {
        printf("MASTERCARD\n");
    }
    //visa
    else if ((n == 13 || n == 16) && Ar[0] == 4)
    {
        printf("VISA\n");
    }
    //invalid
    else
    {
        printf("INVALID\n");
    }
}
