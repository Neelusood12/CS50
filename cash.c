#include<stdio.h>
#include<cs50.h>
#include<math.h>


//function prototypes
int change_owed();
int calculate_coins(int n);



//the main function
int main(void)
{
    int n = change_owed();
    int c = calculate_coins(n);
    printf("%i\n", c);
}



//function to prompt user to input the change owed
int change_owed()
{
    int n = -1;
    do
    {
        float f = get_float("Change owed : ");
        //coverting dollars into cents
        n = round(f * 100);;
    }
    while (!(n >= 0));
    return n;
}


//function to calculate number of coins
int calculate_coins(int n)
{
    int t = 0;
    //loop to calculate number of coins
    while (n > 0)
    {
        if (n >= 25)
        {
            n -= 25;
            t++;
        }
        if (n < 25 && n >= 10)
        {
            n -= 10;
            t++;
        }
        if (n < 10 && n >= 5)
        {
            n -= 5;
            t++;
        }
        if (n < 5 && n >= 1)
        {
            n -= 25;
            t++;
        }
    }
    return t;
}
