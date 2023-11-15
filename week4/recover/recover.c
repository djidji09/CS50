#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("file invalid");
         return 1;
    }
    unsigned char bytes[512];

    int counter = 0;

    FILE *jpeg = NULL;

    char * filename = malloc (8 * sizeof(char));

    while(fread(bytes,sizeof(char),512,file))

    {
        if((bytes[0]==0xff) && (bytes[1]==0xd8) && (bytes[2]==0xff) && (bytes[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                fclose(jpeg);
            }
            sprintf(filename,"%03i.jpg",counter);

            jpeg=fopen(filename,"w");

            counter++;

        }
        if(jpeg!=NULL)

            {
                fwrite(bytes,sizeof(char),512,jpeg);
            }

    }
    free(filename);
    fclose(jpeg);
    fclose(file);
    return 0;
}




