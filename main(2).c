//Author: Domas Nemanius
//Student's ID: 2110604
//N1.Sudaryti vienpusį sąrašą. Parašyti procedūrą, kuri išmeta reikšme nurodytą elementą.
//Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include "linkedlist.h"
#include "deleteElementWithValue.h"
#include "structlist.h"

#define MSG_MODULE_DETAILS "Module name-------------------------Grade\n\n"
#define MSG_SEPERATOR      "-----------------------------------------\n\n"
#define MSG_OPTIONS        "To end program - 0, to delete Module 1\n"

#define MODULE_AMOUNT 5
#define MODULE_NAME_MAX_SIZE 40

void fillLinkedList(struct node **head){
    Module lesson;

    char name[MODULE_AMOUNT][MODULE_NAME_MAX_SIZE] = {
        "Math",
        "Procedural_Programming",
        "English",
        "Computer_Architecture",
        "Discrete_Math"
    };

    int grade[MODULE_AMOUNT] = {8, 7, 10, 9, 5};

    for(int i = 0; i < 5; ++i){
        strcpy(lesson.name, name[i]);
        lesson.grade = grade[i];
        addAtEnd(head, &lesson, sizeof(Module));
    }

    return;
}

void printModuleList(struct node *head){
    printf(MSG_MODULE_DETAILS);

    while(head != NULL){
        Module *lesson = (Module *)head->data;
        printf("%-35s %d\n", lesson->name, lesson->grade);
        head = head->link;
    }

    printf(MSG_SEPERATOR);

    return;
}

void validateOption(int *option){
    if( (scanf("%d", option) != 1) || (*option > 1) || (*option < 0) || getchar() != '\n' ){               
        *option = 2;                        
        
        printf("Incorrect input!\n");

        while(getchar() != '\n'){
        }       
            
    }

    return;
}

void deleteElement(struct node **head){

    Module compareTo;
    printf("Enter lesson name and it's grade that you would like to delete\n");

    while(1){
        printf("Name:\n");
        if(scanf("%29s", compareTo.name) == 1 && getchar() == '\n'){
            break;
        }
        else{
            printf("Bad input!\n");
            while(getchar() != '\n'){
            }
        }
    }

    while(1){
        printf("Grade:\n");
        if(scanf("%d", &compareTo.grade) == 1 && getchar() == '\n' && compareTo.grade >= 0 && compareTo.grade <= 10){
            break;
        }
        else{
            printf("Bad input!\n");
            while(getchar() != '\n'){
            }
        }
    }

    deleteElementWithValue(head, &compareTo, compareModule);

    return;
    
}

void loadUserInterface(struct node **head){
    int option = 2; //two options (0) - end program, (1) delete module

    while(option){
        printModuleList(*head);

        printf(MSG_OPTIONS);
        validateOption(&option);

        if(option == 1){
            deleteElement(head);
        }
    }


}


int main(){

    struct node *head;

    createList(&head);

    fillLinkedList(&head);
    loadUserInterface(&head);
    deleteList(&head);

    return EXIT_SUCCESS;
}


