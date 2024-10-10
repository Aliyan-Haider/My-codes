//In the file, sequence.txt, the numbers were written in this manner:
//68, 78, 75, 69, 78, 77, 70

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_int(FILE *file, int *temp);
void selection_sort(int src[], int src_size, int dst[]);
float find_mean(int seq[], int size);
float find_median(int seq[], int size);
int find_mode(int seq[], int size);
int find_range(int seq[], int size);

int main(void){

    float mean;
    int median, mode, range;

    //uns_seq is an abbreviation for "unsorted sequence." It is dynamically
    //allocated because we don't know the size of the sequence. After
    //finding out its size, we'll move the elements from here to a dynamically
    //allocated array of its exact size.
    int *uns_seq = (int*)malloc(1000 * sizeof(int));
    if (uns_seq == NULL){

        printf("Memory allocation failed.\n");
        exit(1);
    }
    memset(uns_seq, 0, sizeof(uns_seq));

    FILE *sequence = fopen("sequence.txt", "r");

    //seq_len is an abbreviation for "sequence length."
    int seq_len = get_int(sequence, uns_seq);

    //s_seq is an abbreviation for "sorted sequence."
    int s_seq[seq_len];

    //Used a modified selection sort algorithm to copy the elements in a sorted
    //manner.
    selection_sort(uns_seq, seq_len, s_seq);

    free(uns_seq);

    mean = find_mean(s_seq, seq_len);
    median = find_median(s_seq, seq_len);
    mode = find_mode(s_seq, seq_len);
    range = find_range(s_seq, seq_len);

    printf("Mean: %f\nMedian: %d\nMode: %d\nRange: %d\n", mean, median, mode, 
    range);
}

int get_int(FILE *file, int *temp_seq){

    //Basically asking the operating system to find me two contiguous blocks of
    //bytes somewhere in the memory, and assign the first block of it to
    //buffer_1. If failed for whatever reason, print the message and exit the
    //program with exit status 1.
    char *buffer_1 = malloc(2 * sizeof(char));
    if (buffer_1 == NULL){

        printf("Memory allocation failed.\n");
        exit(2);
    }
    //counter is used to keep track of how many characters have been read, how
    //many characters to reallocate based on the input size, and is also used
    //as an index.
    int counter_1 = 0;
    int temp_seq_len = 0;

    //buffer_2 temporarily stores the character, to check whether or not it is
    //an integer or a newline.
    uint8_t buffer_2;

    while(fread(&buffer_2, sizeof(buffer_2), 1, file) != 0){

        if (isdigit(buffer_2)){

            //Here, we're asking the program to reallocate bytes based on the
            //size of the input. The address is being stored in a temporary
            //because if an error occurs, we don't want to lose track of the
            //data stored in buffer_1.
            char *temp = realloc(buffer_1, (2 + counter_1) * sizeof(char));
            if (temp == NULL){

                free(buffer_1);
                exit(3);
            }
            buffer_1 = temp;
            buffer_1[counter_1] = buffer_2;
            counter_1++;
            buffer_1[counter_1] = '\0';
        }
        else if(buffer_2 == ','){

            temp_seq[temp_seq_len] = atoi(buffer_1);
            temp_seq_len++;
            counter_1 = 0;
        }
        else{

            continue;
        }
    }
    temp_seq[temp_seq_len] = atoi(buffer_1);
    temp_seq_len++;
    free(buffer_1);

    return temp_seq_len;
}

void selection_sort(int src[], int src_size, int dst[]){

    //dst_in is abbreviation for "destination index," and this is used to as
    //index for where to store the smaller values.
    for(int dst_in = 0; dst_in < src_size; dst_in++){

        //in_sml_val is abbreviation for "index of smaller value."
        int in_sml_val = 0;

        //in_lrg_val is abbreviation for "index of larger value."
        for(int in_lrg_val = 0; in_lrg_val < src_size; in_lrg_val++){

            if (src[in_sml_val] == 0){

                in_sml_val++;
                in_lrg_val--;
            }
            else if (src[in_lrg_val] == 0){

                continue;
            }
            else if (src[in_sml_val] > src[in_lrg_val]){

                in_sml_val = in_lrg_val;
            }
        }
        dst[dst_in] = src[in_sml_val];

        //Set the index of smaller value to 0, to indicate that that integer
        //has already been copied in a separate array.
        src[in_sml_val] = 0;
    }
}

float find_mean(int seq[], int size){

    float mean = 0;
    for(int i = 0; i < size; i++){

        mean += seq[i];
    }
    mean /= size;

    return mean;
}

float find_median(int seq[], int size){

    float median;

    if (size % 2 == 0){

        median = seq[(size / 2) - 1] + seq[size / 2];
    }
    else{

        median = seq[size / 2];
    }
    return median;
}
int find_mode(int seq[], int size){

    int mode = 0;
    int frequency = 0;

    for(int i = 0; i < size; i++){

        if (seq[i] != mode){

            frequency = 1;
            mode = seq[i];
        }
        else{

            frequency++;
        }
    }
    return mode;
}

int find_range(int seq[], int size){

    int range = seq[0] - seq[size - 1];

    return range;
}