#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        printf("Usage ./recover jpeg_name\n");
        return 1;
    }

    //open memory card/file
    FILE *file = fopen(argv[1], "r");

    //check if the file is empty
    if (file == NULL)
    {
        printf("The memory card is empty\n");
        return 1;
    }

    //pointer variable buffer of size 512 bytes to store jpeg temporarily
    unsigned char *buffer = malloc(512);

    //counter to keep account of the number of jpeg files recovered
    int c = 0;

    //string type variable to store name of the file in which image is to be stored
    char *images = malloc(8);

    //file for storing images
    FILE *img;

    //loop until the end of the file
    while (fread(buffer, 512, 1, file))
    {
        //check if start of a new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0))
        {
            //if first jpeg
            if (c == 0)
            {
                sprintf(images, "%03i.jpg", c);
                img = fopen(images, "w");
                fwrite(buffer, 512, 1, img);
            }
            else
            {
                fclose(img);
                sprintf(images, "%03i.jpg", c);
                img = fopen(images, "w");
                fwrite(buffer, 512, 1, img);
            }
            c++;
        }

        else
        {
            //if a jpeg is already found
            fwrite(buffer, 512, 1, img);

        }

    }

    fclose(file);
    free(buffer);
    free(images);
    return 0;
}
