#include<stdio.h>
#include<cs50.h>

//function prototypes
int height();
void pyramids(int n);
void dots(int m);
void pyramid(int i);



int main(void)
{
    int n = height();
    pyramids(n);
}



//function to enter desired height of the pyramids
int height()
{
    int h = 0;
    //loop to ensure that the height is from 1 to 8
    do
    {
        //Prompting the user to enter the required height of the pyramid
        h = get_int("Height\n");
    }
    while (!(h > 0 && h < 9));
    return h;
}



//function for making pyramids of height n
void pyramids(int n)
{
    //loop for making pyramids of height n
    for (int i = 0; i < n; i++)
    {
        dots(n - 1 - i);
        pyramid(i);
        dots(2);
        pyramid(i);
        printf("\n");
    }
 
}



//function to print blank spaces/dots
void dots(int m)
{
    for (int i = 0 ; i < m ; i++)
    {
        printf(" ");
    }
}



//function to print pyramid
void pyramid(int i)
{
    for (int j = 0 ; j <= i; j++)
    {
        printf("#");
        
    }
}
