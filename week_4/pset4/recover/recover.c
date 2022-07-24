#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

/*
check if input is valid
    else, return 1
open input file (the memory card)
repeat until end of card
    read 512 bytes into a buffer
    if start of new jpeg
        if first jpeg
            write new jpeg
        else
            close current file
            open new file
    else
        if already found jpeg
            keep writing to jpeg
end of memory card
close all open files
*/
int main(int argc, char *argv[])
{
    // Check for invalid input
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *input_file = argv[1];
    FILE *input_pointer = fopen(input_file, "r");
    if (input_file == NULL)
    {
        printf("Unable to open: %s\n", input_file);
        return 1;
    }


    // Create buffer
    unsigned char buffer[BUFFER_SIZE];

    // File counter, initialise
    int image_counter = 0;
    FILE *output_pointer = NULL;

    // Check if JPEG is found
    int jpg_has_alr_been_found = 0; //False


    //Read through the whole block, repeat for all files
    while (fread(&buffer, BUFFER_SIZE, 1, input_pointer) == 1)
    {
        //if start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if JPEG has been found
            if (jpg_has_alr_been_found == 1)
            {
                // Start of an image has been found, so close current image
                fclose(output_pointer);
            }

            //if first JPEG, create a new first file and write in it
            else
            {
                //new JPEG discovered and we can write on file
                jpg_has_alr_been_found = 1;
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", image_counter);
            output_pointer = fopen(filename, "w");
            image_counter++;
        }
        if (jpg_has_alr_been_found == 1)
            //once new JPEGS are found

        {
            //copy over the blocks from buffer into new file
            fwrite(&buffer, BUFFER_SIZE, 1, output_pointer);
        }
    }


    if (output_pointer == NULL)
    {
        fclose(output_pointer);
    }
    if (input_pointer == NULL)
    {
        fclose(input_pointer);
    }
    return 0;
}