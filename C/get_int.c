//The necessary libraries are:
//ctype.h
//stdio.h
//string.h

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

        //If not, set all the indexes of "input" to '\0' and print the
        //message.
        else{

            memset(input, '\0', sizeof(input));
            printf("Invalid.\n");
        }
    }
}