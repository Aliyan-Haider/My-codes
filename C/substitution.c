#include <ctype.h>
#include <stdio.h>
#include <string.h>

int key_checker(char a[], char b[]);
void substitution_cipher(char a[], char b[], char c[]);

int main(int argc, char *argv[])
{
    //The character array "key" will store the key input by the
    //user if the if-statement is true, and end the program and
    //return 1 if false.
    char key[26];
    if (argc == 2)
    {
        int result = key_checker(argv[1], key);

        if (result != 0)
        {
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }

    //Declare character arrays and set all their indexes to '\0'.
    char plaintext[100];
    memset(plaintext, '\0', sizeof(plaintext));
    char ciphertext[100];
    memset(ciphertext, '\0', sizeof(ciphertext));

    //Ask for the user text that is to be ciphered, and set it to
    //"plaintext" character array.
    printf("Plaintext:  ");
    fgets(plaintext, sizeof(plaintext), stdin);

    
    //string by fgets, followed by '\0'.
    int len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n')
    {
            plaintext[len - 1] = '\0';
    }

    substitution_cipher(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);
}
int key_checker(char a[], char b[])
{
    //The "check" character array will check for any repetition in
    //"char a[]", which in this case, is "argv[1]". Further
    //explanation on line 67.
    char check[26];
    memset(check, '\0', sizeof(check));

    int i = 0;
    while (i < 26)
    {
        //This will check if a[i] is a character or not.
        if (!isalpha(a[i]))
        {
            printf("Usage: ./substitution key\n");

            return 1;
        }
        else
        {
            //With each iteration, the variable "alpha_location" will be
            //reset to 0, and then assigned the value achieved by
            //subtracting 65 from the ASCII value of the ith letter.
            //Example: if the ith character is 'H' which has an ASCII
            //value of 72, when subtracted 65 from it, we will get 7.
            //To simplify things for the program, the ith character will
            //be converted to uppercase before the subtraction.
            int alpha_location = 0;
            alpha_location = toupper(a[i]) - 65;

            //The if-statement will check if the index of the value
            //provided—7 in our example—is occupied by another letter. If
            //yes, it would mean that a letter has been repeated twice in
            //the user provided key.
            if (check[alpha_location] != '\0')
            {
                printf("Usage: ./substitution key\n");

                return 1;
            }
            else
            {
                check[alpha_location] = a[i];
            }

            b[i] = toupper(a[i]);
        }
        i++;

        //This if-statement will make sure that the key provided
        //contains 27 characters (26 letters and 1 null-termination).
        //If the user provides a key with more than 26 letters, the
        //first 26 letters will be the only ones accepted by the
        //program.
        if (i < 26 && a[i] == '\0')
        {
           printf("Usage: ./substitution key\n");

           return 1;
        }
    }
    return 0;
}

void substitution_cipher(char a[], char b[], char c[])
{
    //This while-loop will loop through the entire "char a[]"
    //which in this case, is "plaintext[100]", and stop if "a[i]"
    //is '\0'.
    int i = 0;
    while (a[i] != '\0')
    {
        //If "a[i]" is an English alphabet, the program will enter the
        //loop; else, it will set "b[i]" to "a[i]" as is.
        if (isalpha(a[i]))
        {
            //With each iteration, the variable "alpha_location" will be
            //reset to 0, and then depending on whether "a[i]" is in
            //uppercase or lowercase, will have either 65 or 97 subtracted
            //from its ASCII value and the remaining value will be set to
            //"alpha_location". The integer in "alpha_location" will then
            //be used as an index for "char c[]" which in this case, is
            //"key[100]". The character at "b[i]" would then be replaced
            //by "c [alpha_location]".
            int alpha_loction = 0;

            if (isupper(a[i]))
            {
                alpha_loction = a[i] - 65;
                b[i] = c[alpha_loction];
            }
            else
            {
                alpha_loction = a[i] - 97;
                b[i] = tolower(c[alpha_loction]);
            }
        }
        else
        {
            b[i] = a[i];
        }

        i++;
    }
}
