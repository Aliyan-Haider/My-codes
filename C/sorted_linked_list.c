#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{

    char name[20];
    char id[8];
    struct student *next;

};

bool id_sorter(char id_1[], char id_2[], int id_size);

int main(void){

    struct student *attendence_sheet = NULL;

    for(int i = 0; i < 6; i++){

        struct student *temp = malloc(sizeof(struct student));
        if(temp == NULL){

            for(struct student *j = attendence_sheet; j != NULL;){

                struct student *del = j;
                j = j->next;
                free(del);
            }
            return 1;
        }
        memset(temp->name, '\0', sizeof(temp->name));
        memset(temp->id, '\0', sizeof(temp->id));

        printf("Enter your name: ");
        fgets(temp->name, sizeof(temp->name), stdin);
        printf("Enter your id: ");
        fgets(temp->id, sizeof(temp->id), stdin);
        temp->next = NULL;

        int len = strlen(temp->name);
        if(len > 0 && temp->name[len - 1] == '\n'){

            temp->name[len - 1] = '\0';
        }
        
        char c;
        while ((c = getchar()) != '\n' && c != EOF);

        if(attendence_sheet == NULL){

            attendence_sheet = temp;
        }
        else if(id_sorter(temp->id, attendence_sheet->id, 
            (sizeof(temp->id) - 1))){

            temp->next = attendence_sheet;
            attendence_sheet = temp;
        }
        else{

            for(struct student *ptr = attendence_sheet;; ptr = ptr->next){

                if(ptr->next == NULL){

                    ptr->next = temp;
                    break;
                }
                else if(id_sorter(temp->id, ptr->next->id, 
                    (sizeof(temp->id) - 1))){

                    temp->next = ptr->next;
                    ptr->next = temp;
                    break;
                }
            }
        }
    }

    for(struct student *prnt = attendence_sheet; prnt != NULL; 
        prnt = prnt->next){

        printf("%s\t%s\n", prnt->name, prnt->id);
    }

    struct student *ptr = attendence_sheet;
    while (ptr != NULL) {
        struct student *del = ptr;
        ptr = ptr->next;
        free(del);
    }
}

// id_sorter checks whether id_1 is smaller than id_2.
bool id_sorter(char id_1[], char id_2[], int id_size){

    for(int i = 0; i < id_size; i++){

        if(id_1[i] < id_2[i]){

            return true;
        }
        else if(id_1[i] > id_2[i]){

            return false;
        }
    }
    return false;
}