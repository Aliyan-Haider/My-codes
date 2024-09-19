#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caesar_key(char a[], char b[], int *c);

int main(int argc, char *argv[])
{

    //Check if argc is not equal to 2. If yes, print the message
    //and return 1.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    //Convert the numbers set to type string to type integer and
    //set that int value to variable "key."
    int key = atoi(argv[1]);

    //Declare character arrays and set all their indexes to '\0'.
    char plaintext[100];
    memset(plaintext, '\0', sizeof(plaintext));
    char ciphertext[100];
    memset(ciphertext, '\0', sizeof(ciphertext));

    //Check the numerical value stored in "key." If the user
    //entered any other value other than 0–9 digits, the entire
    //argument wouldn't be accepted, and "key" will remain set to
    //0.
    if (key > 0 && key < 2147483622)
    {
        //Ask for the user text that is to be ciphered, and set it to
        //"plaintext."
        printf("Plaintext:  ");
        fgets(plaintext, sizeof(plaintext), stdin);

        //Remove the newline automatically placed at the end of the
        //string by fgets, followed by '\0'.
        int len = strlen(plaintext);
        if (len > 0 && plaintext[len - 1] == '\n')
        {
            plaintext[len - 1] = '\0';
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    caesar_key(plaintext, ciphertext, &key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
void caesar_key(char a[], char b[], int *c)
{
    //Declare "i" and set it to 0.
    int i = 0;

    //This first while-loop will move through each index of a[],
    //in this case, "plaintext."
    while (a[i] != '\0')
    {
        //Declare int "k" and set its value to *c, in this case,
        //"key," and set the ith value of a[] to the ith value of b[],
        //which in this case, is "ciphertext."
        int k = *c;
        b[i] = a[i];

        //Check if ith character of  "a[]" is an English alphabet.
        if (isalpha(a[i]))
        {
            //This while-loop moves the ith character of "b[]" "k" number
            //of times.
            while (k > 0)
            {
                //This if statement checks if the ith character of "b[]" is
                //'Z' or 'z.' If yes, it will set 'Z' to '@' and set 'z' to
                //'`'.
                if (b[i] == 'Z' || b[i] == 'z')
                {
                    b[i] = b[i] - 26;
                }

                //Add one the ith character of "b[]" to change '@' to A, and
                //'`' to "a," or "A" to "B" and "a" "b." "k--" will subtract 1
                //from "k" with each iteration. So, if  "k" is 3 and "a[]" is
                //"ABC," by the end of the second while-loop, "k" will become
                //0, while the "a[i]" will have 3 added to its ASCII value.
                b[i] = b[i] + 1;
                k--;
            }
        }

        //After "a[i]" has been moved forward "k" number of times,
        //the program will exit the second while-loop and the first
        //if statement, and add 1 to "int i," and the program, still
        //in the first while-loop, will repeat the process with the
        //ith character of "a[]" unless the character is '\0'.
        i++;
    }
}
