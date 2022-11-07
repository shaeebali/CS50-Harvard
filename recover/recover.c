#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure appropriate usage
    if(argc!=2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // Open the image file
    FILE*inptr=fopen(argv[1], "r");
    if(inptr==NULL)
    {
        fprintf(stderr, "Failed to open %s.\n", argv[1]);
        return 2;
    }

    // Set out pointer to NULL
    FILE* outptr = NULL;

   // Create an array that stores 512 bytes in memory
    BYTE buffer[512];

    // Count number of jpeg files found
    int jpeg=0;

    // Single char string to hold a filename
    char filename[8]={0};

    // Read memory card until the end of file
    while(fread(buffer, sizeof(BYTE)*512, 1, inptr)==1)
    {
        //check if jpeg is found
        if(buffer[0]==0xFF&&buffer[1]==0xD8&&buffer[2]==0xFF&&(buffer[3]&0xF0)==0xE0)
        {
            // Close outptr if the jpeg was found before and written into a .jpg file
            if(outptr != NULL)
            {
                fclose(outptr);
            }
                sprintf(filename, "%03d.jpg", jpeg++);

                outptr = fopen(filename, "w");
        }

       // Continue writing to jpeg file if new jpeg is not found
       if(outptr != NULL)
       {
            fwrite(buffer, sizeof(BYTE)*512, 1, outptr);
       }
    }

    // Close last outptr
     if (outptr != NULL)
     {
      fclose(outptr);
     }

    // Close the input file
      fclose(inptr);

    return 0;

}