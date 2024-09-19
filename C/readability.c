#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void letters_counter(char a[], int *b);
void words_counter(char a[], int *b);
void sentences_counter(char a[], int *b);
void grade_level_counter(int *a, int *b, int *c, float *d, float *e, float *f);

int main(void)
{
    //Declare the variables.
    //"num" is short of number.
    char text[1000];
    int letters_num, words_num, sentences_num;
    float l, s, grade_level;

    //Ask for text from the user, and pass it to "Text."
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    //Call upon the necessary functions.
    letters_counter(text, &letters_num);
    words_counter(text, &words_num);
    sentences_counter(text, &sentences_num);
    grade_level_counter(&letters_num, &words_num, &sentences_num, &l, &s, &grade_level);

    //Check the integer converted float value in the "grade_level"
    //and print text in accordance to the value.
    if ((int) grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((int) grade_level > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) grade_level);
    }
}

void letters_counter(char a[], int *b)
{
    //Assign the pointer variable "*b" the value 0, to replace the
    //garbage value inside it.
    *b = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        //If a[i] is an English alphabet, add 1 to pointer variable
        //"*b", which in this case, is the number of letters.
        if (isalpha(a[i]))
        {
            (*b)++;
        }
    }
}
void words_counter(char a[], int *b)
{
    *b = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        //If a[i] isn't an alphabet, enter loop.
        if (!isalpha(a[i]))
        {
            //First, check if a[i] isn't an apostrophe "'" or a hyphen
            //"-". If true, check if a[i - 1] is an alphabet. If also
            //true, add 1 to pointer variable "*b", which in this case, is
            //the number of words.
            if (isalpha(a[i - 1]) && (a[i] != '\'' && a[i] != '-'))
            {
                (*b)++;
            }
            else
            {
                continue;
            }
        }
    }
}
void sentences_counter(char a[], int *b)
{
    *b = 0;


    for (int i = 0; a[i] != '\0'; i++)
    {
        //If a[i] isn't any of the ending punctuation marks, add 1 to
        //pointer variable "*b", which in this case, is the number of
        //sentences.
        if ((a[i] == '.') || (a[i] == '!') || (a[i] == '?'))
        {
            (*b)++;
        }
    }
}
void grade_level_counter(int *a, int *b, int *c, float *d, float *e, float *f)
{
    //Use the values received from the previous functions, and use
    //them in the Coleman-Liau index formula.
    *d = ((float) *a / (float) *b) * 100;
    *e = ((float) *c / (float) *b) * 100;
    *f = 0.0588 * (*d) - 0.296 * (*e) - 15.8;

    //Round off the given value to its nearest integer.
    *f = round(*f);
}
