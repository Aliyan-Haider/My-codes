#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Maximum numbers of voters and candidates.
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

//Preferences[i][j] is jth preference for voter i.
int preferences[MAX_VOTERS][MAX_CANDIDATES];

//Candidates have name, vote count, eliminated status.
typedef struct
{
    char name[20];
    int votes;
    bool eliminated;
} candidate;

//Array of candidates.
candidate candidates[MAX_CANDIDATES];

//Numbers of voters and candidates.
int voter_count;
int candidate_count;

//Function prototypes.
void eliminate(int min);
int find_min(void);
void get_int(int *n);
bool is_tie(int min);
bool print_winner(void);
void tabulate(void);
bool vote(int voter, int rank, char name[]);

int main(int argc, char *argv[])
{
    //Check for invalid usage.
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    //Check the number of candidates and make sure they're equal
    //to or less than "MAX_CANDIDATES".
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    //Make sure all garbage value is removed from the structure
    //array.
    memset(candidates, '\0', sizeof(candidates));
    memset(preferences, 0, sizeof(preferences));

    //Assign candidates to the "candidates" structure array.
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    //Get the number of voters and make sure they're not more than
    //"MAX_VOTERS".
    get_int(&voter_count);
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    //Keep querying for votes.
    for (int i = 0; i < voter_count; i++)
    {

        //Keep querying for the rank of their votes.
        for (int j = 0; j < candidate_count; j++)
        {
            //Inquire for the name of their j + 1 candidate.
            char name[20];

            printf("Rank %d:", j + 1);
            fgets(name, sizeof(name), stdin);

            //Remove the newline automatically placed at the end of the
            //string by fgets, following '\0'.
            int len = strlen(name);
            if (len > 0 && name[len - 1] == '\n')
            {
                name[len - 1] = '\0';
            }

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    //Keep holding runoffs until winner exists.
    while (true)
    {
        //Calculate the votes given to remaining candidates.
        tabulate();

        //Check if election has been won. If yes, break the loop.
        bool won = print_winner();
        if (won)
        {
            break;
        }

        //Find the candidate with the minimum number of votes.
        int min = find_min();

        //Check if the election is a tie. If yes, print the winners
        //and break the loop.
        bool tie = is_tie(min);
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        //Eliminate anyone with minimum number of votes.
        eliminate(min);

        //Set all votes back to 0, as they will be reassigned by
        //tabulate() in the next loop.
        for(int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

void get_int(int *n){

    //The program can work with a maximum of "input-1" figures
    //number. To change it, assign more or less bytes to "input".
    char input[5];

    //"is_number" is a flag that is by default set to 1, meaning
    //false. The flag will be switched to true once the user
    //enters a valid number, effectively stopping the function.
    int is_number = 1;

    //This "while-loop" which uses the "is_number" flag will
    //repeatedly ask the user to enter a number, until the user
    //does.
    while (is_number != 0){

        //Ask the user for a number, and assign it to "input".
        printf("Number: ");
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

        //If not, set all the indexes of "input" to '\0'.
        else{

            memset(input, '\0', sizeof(input));
        }
    }
}

//Record preference if vote is valid.
bool vote(int voter, int rank, char name[])
{
    int i = 0;
    while (i < candidate_count){

        if (strcmp(candidates[i].name, name) == 0){

            //Record their preferred candidate's index.
            preferences[voter][rank] = i;

            return true;
        }
        i++;
    }
    return false;
}

//Tabulate votes for non-eliminated candidates.
void tabulate(void)
{
    int voter = 0;
    int pref = 0;

    while (voter < voter_count){

        //Grab the candidate index stored at preferences[voter][pref]
        //and increase their current votes by one, if not eliminated.
        //Otherwise, look at the voter's next preference.
        int cand_index = preferences[voter][pref];

        if (candidates[cand_index].eliminated == true){

            pref++;
            continue;
        }
        candidates[cand_index].votes++;
        voter++;
        pref = 0;
    }
    return;
}

//Print the winner of the election, if there is one.
bool print_winner(void)
{
    //To win, a candidate must have more than 50% of the total
    //votes.
    int win_requirement = voter_count / 2 + 1;
    int i = 0;

    while(i < candidate_count){

        if (candidates[i].votes >= win_requirement){

            printf("%s\n", candidates[i].name);

            return true;
        }

        i++;
    }
    return false;
}

//Return the minimum number of votes any remaining candidate
//has.
int find_min(void)
{
    //Assign the votes of the first candidate to "lowest_votes"
    //and loop over all the non-eliminated candidates to find a
    //candidates with votes equal to or lower than the current
    //one.
    int lowest_votes = candidates[0].votes;
    int i = 0;

    while(i < candidate_count){

        if (candidates[i].eliminated == false && lowest_votes >= candidates[i].votes){

            lowest_votes = candidates[i].votes;
        }
        i++;
    }
    return lowest_votes;
}

//Return true if the election is tied between all candidates,
//false otherwise.
bool is_tie(int min)
{
    int i = 0;
    while(i < candidate_count){

        if (candidates[i].eliminated == false && candidates[i].votes != min){

            return false;
        }
        i++;
    }
    return true;
}

//Eliminate the candidate (or candidates) in last place.
void eliminate(int min)
{
    int i = 0;
    while(i < candidate_count){

        if (candidates[i].votes == min){

            candidates[i].eliminated = true;
        }
        i++;
    }
}
