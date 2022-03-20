//Author: Domas Nemanius
//Student's ID: 2110604
//This program is providing unit tests for 'linkedlist.h' module.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "linkedlist.h"

int unitTestingCreateList(){

    struct node *head = (struct node*)10000;

    createList(&head);

    if(head == NULL){
        deleteList(&head);
        return EXIT_SUCCESS;
    }
    else{
        deleteList(&head);
        return EXIT_FAILURE;
    }
}

int unitTestingDeletingList_1(){
    int i = 0;
    struct node *head;
    createList(&head);

    addAtBeginning(&head, &i, sizeof(int));

    deleteList(&head);

    if(head == NULL){
        return EXIT_SUCCESS;
    }
    else{
        return EXIT_FAILURE;
    }
}

int unitTestingDeletingList_2(){
    int i = 0;
    struct node *head;
    createList(&head);

    addAtBeginning(&head, &i, sizeof(int));
    addAtBeginning(&head, &i, sizeof(int));
    addAtBeginning(&head, &i, sizeof(int));

    deleteList(&head);

    if(head == NULL){
        return EXIT_SUCCESS;
    }
    else{
        return EXIT_FAILURE;
    }
}

int unitTestingDeletingList_3(){
    struct node *head;
    createList(&head);

    deleteList(&head);

    if(head == NULL){
        return EXIT_SUCCESS;
    }
    else{
        return EXIT_FAILURE;
    }
}

int unitTestingPrintInt(){
    struct node *head;
    createList(&head);

    for(int i = 0; i < 5; ++i){
        addAtEnd(&head, &i, sizeof(int));
    }

    printData(head, printInt);

    return EXIT_SUCCESS;
}

int unitTestingPrintChar(){
    char c[5] = {'a', 'b', 'c', 'd', 'e'};
    struct node *head;
    createList(&head);

    for(int i = 0; i < 5; ++i){
        addAtEnd(&head, &c[i], sizeof(int));
    }

    printData(head, printChar);

    return EXIT_SUCCESS;
}

int unitTestingAddAtPosition(){
    struct node *head;
    createList(&head);

    int value = 10;

    for(int i = 0; i < 5; ++i){
        addAtEnd(&head, &i, sizeof(int));
    }

    addAtPosition(&head, &value, 3, sizeof(int));

    for(int i = 0; i < 2; ++i){
        head = head->link;
    }

    if(*(int*)(head->data) == value){
        deleteList(&head);
        return EXIT_SUCCESS;
    }

    deleteList(&head);
    return EXIT_FAILURE;
}

int unitTestingAddAtEnd(){
    struct node *head;
    createList(&head);

    int value = 10;

    for(int i = 0; i < 5; ++i){
        addAtEnd(&head, &i, sizeof(int));
    }

    addAtEnd(&head, &value, sizeof(int));

    for(int i = 0; i < 5; ++i){
        head = head->link;
    }

    if(*(int*)(head->data) == value){
        deleteList(&head);
        return EXIT_SUCCESS;
    }

    deleteList(&head);
    return EXIT_FAILURE;
}

int unitTestingAddAtBeginning(){
    struct node *head;
    createList(&head);

    int value = 10;

    for(int i = 0; i < 5; ++i){
        addAtEnd(&head, &i, sizeof(int));
    }

    addAtBeginning(&head, &value, sizeof(int));

    if(*(int*)(head->data) == value){
        deleteList(&head);
        return EXIT_SUCCESS;
    }

    deleteList(&head);
    return EXIT_FAILURE;
}

int unitTestingDeleteAtPosition(){
    struct node *head;
    createList(&head);

    int value = 10;

    for(int i = 0; i < 5; ++i){
        addAtEnd(&head, &i, sizeof(int));
    }
    
    deleteAtPosition(&head, 3);


    for(int i = 0; i < 2; ++i){
        head = head->link;
    }

    if(*(int*)(head->data) == 3){
        deleteList(&head);
        return EXIT_SUCCESS;
    }
    else{
        deleteList(&head);
        return EXIT_FAILURE;
    }

}

int unitTestingDeleteLast(){
    struct node *head;
    createList(&head);

    int value = 10;

    for(int i = 0; i < 5; ++i){
        addAtEnd(&head, &i, sizeof(int));
    }
    
    deleteLast(&head);


    while(head->link != NULL){
        head = head->link;
    }

    if(*(int*)(head->data) == 3){
        deleteList(&head);
        return EXIT_SUCCESS;
    }
    else{
        deleteList(&head);
        return EXIT_FAILURE;
    }

}

int unitTestingDeleteFirst(){
    struct node *head;
    createList(&head);

    int value = 10;

    for(int i = 0; i < 5; ++i){
        addAtEnd(&head, &i, sizeof(int));
    }
    
    deleteFirst(&head);

    if(*(int*)(head->data) == 1){
        deleteList(&head);
        return EXIT_SUCCESS;
    }
    else{
        deleteList(&head);
        return EXIT_FAILURE;
    }

}

int unitTestingCountOfNodes_1(){
    struct node *head;
    createList(&head);

    for(int i = 0; i < SHRT_MAX; ++i){
        addAtEnd(&head, &i, sizeof(int));
    }

    if(countOfNodes(head) == SHRT_MAX){
        deleteList(&head);
        return EXIT_SUCCESS;
    }
    else{
        deleteList(&head);
        return EXIT_FAILURE;
    }
}

int unitTestingCountOfNodes_2(){
    struct node *head;
    createList(&head);
    int i = 4;

    addAtEnd(&head, &i, sizeof(int));

    if(countOfNodes(head) == 1){
        deleteList(&head);
        return EXIT_SUCCESS;
    }
    else{
        deleteList(&head);
        return EXIT_FAILURE;
    }
}

int unitTestingCountOfNodes_3(){
    struct node *head;
    createList(&head);

    if(countOfNodes(head) == 0){
        deleteList(&head);
        return EXIT_SUCCESS;
    }
    else{
        deleteList(&head);
        return EXIT_FAILURE;
    }
}

int main(){

    //createList
    assert(unitTestingCreateList() == EXIT_SUCCESS);

    //deleteList
    //1. One element
    //2. Few elements
    //3. Empty list
    assert(unitTestingDeletingList_1() == EXIT_SUCCESS);
    assert(unitTestingDeletingList_2() == EXIT_SUCCESS);
    assert(unitTestingDeletingList_3() == EXIT_SUCCESS);

    //printData
    //1. Print int
    //2. Print char
    assert(unitTestingPrintInt() == EXIT_SUCCESS);
    assert(unitTestingPrintChar() == EXIT_SUCCESS);

    //Add elements
    //1. Add elements in the middle (addAtPosition)
    //2. Add elements in the end (addAtEnd)
    //3. Add elements in the beginning
    assert(unitTestingAddAtPosition() == EXIT_SUCCESS);
    assert(unitTestingAddAtEnd() == EXIT_SUCCESS);
    assert(unitTestingAddAtBeginning() == EXIT_SUCCESS);

    //deleteElements
    //1. Delete element at the middle (deleteAtPosition)
    //2. Delete element at the end (deleteLast)
    //3. Delete First element (deleteFirst)
    assert(unitTestingDeleteAtPosition() == EXIT_SUCCESS);
    assert(unitTestingDeleteLast() == EXIT_SUCCESS);\
    assert(unitTestingDeleteFirst() == EXIT_SUCCESS);

    //countOfNodes
    //1. When list size = SHRT_MAX
    //2. When list size = 1
    //3. When list size = 0
    assert(unitTestingCountOfNodes_1() == EXIT_SUCCESS);
    assert(unitTestingCountOfNodes_2() == EXIT_SUCCESS);
    assert(unitTestingCountOfNodes_3() == EXIT_SUCCESS);

    printf("All tests have been passed successfully!\n");
    return EXIT_SUCCESS;
}
