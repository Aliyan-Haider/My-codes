#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_int(int *n);
void bill_calculator(int* a, int* b);

int main(void)
{
    int total_units;
    int bill = 0;

    get_int(&total_units);
    bill_calculator(&total_units, &bill);

    printf("%d\n", bill);
}

void get_int(int *n){

    //The program can work with a maximum of "input-1" figures
    //number. To change it, assign more or less bytes to "input".
    char input[6];

    //"is_number" is a flag that is by default set to 1, meaning
    //false. The flag will be switched to true once the user
    //enters a valid number, effectively stopping the function.
    int is_number = 1;

    //This "while-loop" which uses the "is_number" flag will
    //repeatedly ask the user to enter a number, until the user
    //does.
    while (is_number != 0){

        //Ask the user for a number, and assign it to "input".
        printf("Total electricity bill: ");
        fgets(input, sizeof(input), stdin);

        //Remove the newline automatically placed at the end of the
        //string by fgets, followed by '\0'.
        int len = strlen(input);
        if (len > 0 && input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
        }

        //If the user input is larger than what "input" can store,
        //clear the buffer.
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        //Check if the user input was number.
        if (isdigit(input[0])){

            *n = atoi(input);
            is_number = 0;
        }

        //If not, set all the indexes of "input" to '\0' and print the
        //message.
        else{

            memset(input, '\0', sizeof(input));
            printf("Invalid.\n");
        }
    }
}

void bill_calculator(int* a, int* b){

    int i = *a;
        while(i > 0){

        if (i > 500){

            i -= 500;
            *b += 500 * 22;

            continue;
        }
        else if (i > 400){

            i -= 400;
            *b += 400 * 18;

            continue;
        }
        else if (i > 300){

            i -= 300;
            *b += 300 * 15;

            continue;
        }
        else if (i > 200){

            i -= 200;
            *b += 200 * 13;

            continue;
        }
        else if (i > 100){

            i -= 100;
            *b += 100 * 11;

            continue;
        }
        else{

            *b += i * 5;
            i -= i;

            continue;
        }
    }
}
