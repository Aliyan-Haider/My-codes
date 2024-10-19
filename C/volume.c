#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//The .WAV file's header always has a fixed size of 44 bytes.
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    //Check make sure there are exactly 4 command-line arguments.
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    //Open the audio file, and the file where the scaled audio will be stored.
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //factor is the value by which each sample is to be multiplied, to increase
    //the volume of the audio.
    float factor = atof(argv[3]);

    //Copy the .WAV header into another .WAV file.
    uint8_t header_byte;

    for(int i = 0; i < HEADER_SIZE; i++){

        fread(&header_byte, sizeof(header_byte), 1, input);
        fwrite(&header_byte, sizeof(header_byte), 1, output);
    }

    //When copying the data, multiply each sample by factor to change the
    //amplitude.
    int16_t data_byte;

    while(fread(&data_byte, sizeof(data_byte), 1, input) != 0){

        data_byte *= factor;

        fwrite(&data_byte, sizeof(data_byte), 1, output);
    }

    //Close files.
    fclose(input);
    fclose(output);
}