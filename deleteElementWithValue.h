#ifndef DELETEELEMENTWITHVALUE_H_INCLUDED
#define DELETEELEMENTWITHVALUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "structlist.h"

//Function deleteElementWithValue() deletes element from list with given value if that element does not exist function prints out message
//Parameters:
//  head - pointer to the pointer of the first element in the linked list
//  data - pointer to the place where data is stored with which needs to be compared
//  (*fptr)(void *) - function name which determines which data type needs to used
void deleteElementWithValue(struct node **head, void *value, int (*fptr)(void *, void*)){
    struct node *current = *head;
    struct node *previous = *head;

    if(*head == NULL){
        printf("List is empty!\n");
        return;
    }
    else if(current->link == NULL && (*fptr)(current->data, value)){
        *head = current->link;
        free(current->data);
        free(current);
        current = NULL;
        return;
    }
    else{
        if((*fptr)(current->data, value)){
            deleteFirst(head);
            return;
        }
        //Traversing the linked list 
        while(current->link != NULL){
            if((*fptr)(current->data, value)){
                //previous->link = current->link;
                previous->link = current->link;
                free(current->data);
                free(current);
                return;
            }
            previous = current;
            current = current->link;
        }

        if((*fptr)(current->data, value)){
                //previous->link = current->link;
                previous->link = current->link;
                free(current->data);
                free(current);
                return;
            }

        printf("Given value does not exist in the given linked list!\n");
    }
}

//Function compareModule() compares two structs 
//Parameters:
//  value1 - pointer to a first struct Module
//  value2 - pointer to a second struct Module
//Return: 1 if value1 == value2, else 0 
int compareModule(void *value1, void *value2){
    Module *lesson1 = (Module*)value1;
    Module *lesson2 = (Module*)value2;

    if(lesson1->grade == lesson2->grade && strcmp(lesson1->name, lesson2->name) == 0){
        return 1;
    }
    
    return 0;
}

#endif /*DELETEELEMENTWITHVALUE_H INCLUDED */