#include <ctype.h>
#include <stdio.h>
#include <string.h>

void convert_toupper(char a[]);
void point_counter(char a[], int b[], int *c);
int main(void)
{
    // Declare the points for each alphabet individually in a
    // character array.
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Use Standard Input to read the string entered by the user,
    // and copy the string to player_1.
    char player_1[100];
    printf("Player 1: ");
    fgets(player_1, sizeof(player_1), stdin);

    // Convert the string to uppercase, and give points in
    // accordance to the Scrabble rules.
    convert_toupper(player_1);
    int score_1 = 0;
    point_counter(player_1, points, &score_1);

    // See process for player_1, as both of them are the same.
    char player_2[100];
    printf("Player 2: ");
    fgets(player_2, sizeof(player_2), stdin);
    convert_toupper(player_2);
    int score_2 = 0;
    point_counter(player_2, points, &score_2);

    // Print message depending to the winner of the game.
    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
void convert_toupper(char a[])
{
    for (int i = 0; a[i] != '\0' && a[i] != '\n'; i++)
    {
        a[i] = toupper(a[i]);
    }
}

void point_counter(char a[], int b[], int *c)
{
    for (int i = 0; a[i] != '\0' && a[i] != '\n'; i++)
    {
        // Check if the ith index of "a" is a number. If yes, move on
        // to the next one. If not, continue.
        if (!isalpha(a[i]))
        {
            continue;
        }

        // Find out the number of points to be allocated to each
        // character, and add them to *c.
        int j = a[i] - 65;
        *c += b[j];
    }
}
