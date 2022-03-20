#include <stdio.h>
#include <stdlib.h>

//Generic linked list structure
struct node{
    void *data;
    struct node *link;
};

//Function createList() creates empty linked list
//Parameters: 
//  head - pointer to the pointer of the first element of the linkedlist
//Return:  function does not return anything
void createList(struct node **head){
    //Initializing linked list and assigning the first node value
    *head = NULL;
}

//Function countOfNodes() counts the number of nodes in linked list
//Parameters:
//  head - pointer to the first element of a linked list
//Return: number of nodes in linked list
int countOfNodes(struct node *head){
    int count = 0;
    if(head == NULL){
        return count;
    }

    struct node *ptr = NULL;//pointer for storing current node adrress
    ptr = head;

    //traversing the list and counting the number of nodes in it
    while(ptr != NULL){
        ++count;
        ptr = ptr->link;
    }

    return count;
}

//Function printData() prints linked list to stdout
//Parameters:
//  head - pointer to the first element in the linked list
// (*fptr)(void *) - function name which determines which data type needs to be printed
//Return: function does not return anything
void printData(struct node *head, void (*fptr)(void *)){
    if(head == NULL){
        printf("Linked list is empty!\n");
        return;
    }  

    struct node *ptr = NULL;
    ptr = head;

    // traversing the list and printing stored values
    while(ptr != NULL){
        (*fptr)(ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

//Function printInt() prints int type value to stdout
//Parameters:
//  n - pointer to the memory where data is stored
//Return: function does not return anything
void printInt(void *n){
   printf("%d ", *(int *)n);
}

//Function printInt() prints char type value to stdout
//Parameters:
//  n - pointer to the memory where data is stored
//Return: function does not return anything
void printChar(void *n){
    printf("%c ", *(char *)n);
}

//Function addAtBeginning() adds new node to the beginning of the linked list
//  head - pointer to the pointer of the first element in the linked list
//  data - pointer to the place where data is stored
//  dataSize - size of a data type that will be used
//Return: function does not return anything
void addAtBeginning(struct node **head, void *data, size_t dataSize){
    //creating new node
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = malloc(dataSize);
    ptr->link = NULL;

    // Copy contents of new_data to newly allocated memory.
    for(int i = 0; i < dataSize; ++i){
        *(char *)(ptr->data + i) = *(char *)(data + i);
    }

    ptr->link = *head;//linking new node at the beginning of the list
    *head = ptr;//updating head pointer 
}
//TODO documentation
//Function addAtEnd() adds new node to the end of the linked list
//Parameters:
//  head - pointer to the first element in the linked list
//  data - pointer to the place where data is stored
//  dataSize - size of a data type that will be used
//Return: function does not return anything
void addAtEnd(struct node **head, void *data, size_t dataSize){
    struct node *ptr, *temp;
    ptr = *head;
    //creating new node
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = malloc(dataSize);
    temp->link = NULL;

    // Copy contents of new_data to newly allocated memory.
    for(int i = 0; i < dataSize; ++i){
        *(char *)(temp->data + i) = *(char *)(data + i);
    }
    
    if(*head == NULL){
        addAtBeginning(head, data, dataSize);
        return;
    }
    //getting to the currently last node in the list
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;//linking new node to the end of the list
}


//Function addAtPossition() adds new node to the desired possition from 2 to countOfNodes
//If needed to insert new node to the beggining of the list call addAtBeginning().
//Parameters:
//  head - pointer to the pointer of the first element in the linked list
//  data - pointer to the place where data is stored
//  pos - position where new node news to be placed
//  dataSize - size of a data type that will be used
//Return: function does not return anything
void addAtPosition(struct node **head, void *data, int pos, size_t dataSize){
    if(pos > countOfNodes(*head)){
        printf("Currently it is imposible to add element to this position!\n");
        return;
    }

    if(pos == 1){
        addAtBeginning(head, data, dataSize);
        return;
    }
    
    struct node *ptr = *head;

    //creating new node
    struct node *ptr2 = (struct node*)malloc(sizeof(struct node));
    ptr2->data = malloc(sizeof(dataSize));
    ptr2->link = NULL;

    // Copy contents of new_data to newly allocated memory.
    for(int i = 0; i < dataSize; ++i){
        *(char *)(ptr2->data + i) = *(char *)(data + i);
    }

    //Traversing the list while needed location is reached
    --pos;
    while(pos != 1){
        ptr = ptr->link;
        --pos;
    }
    //Linking node to desired possition
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

//Function deleteFirst() deletes the first element in the linked list
//Parameters:
//  head - pointer to the pointer of the first element in the linked list
//Return: function does not return anything
void deleteFirst(struct node **head){
    if(*head == NULL){
        printf("List is already empty");
    }
    else{
        struct node *temp = *head;
        *head = temp->link;
        free(temp->data);
        free(temp);
        temp = NULL;
    }
}

//Function deleteFirst() deletes the last element in the linked list
//Parameters:
//  head - pointer to the pointer of the first element in the linked list
//Return: function does not return anything
void deleteLast(struct node **head){
    struct node *temp = *head;
    struct node *temp2 = *head;
    if(temp == NULL){
        printf("List is already empty!\n");
    }
    else if(temp->link == NULL){ //If linked list contains just one element
        free(temp->data);
        free(*head);
        *head = NULL;
    }
    else{
        //Traversing the linked list
        while(temp->link !=NULL){
            temp2 = temp;
            temp = temp2->link;
        }
        //Deleting last node
        temp2->link = NULL;
        free(temp->data);
        free(temp);
    }

}

//Function deleteAtPossition() deletes specified element in the linked list
//Parameters:
//  head - pointer to the pointer of the first element in the linked list
//  position - possition of the element that needs to be deleted
//Return: function does not return anything
void deleteAtPosition(struct node **head, int position){
    if(position > countOfNodes(*head)){
        printf("Currently element in this position does not exist!\n");
        return;
    }
    struct node *current = *head;
    struct node *previous = *head;

    if(*head == NULL){
        printf("List is already empty!\n");
    }
    else if(position == 1){
        *head = current->link;
        free(current->data);
        free(current);
        current = NULL;
    }
    else{
        while(position != 1){
            previous = current;
            current = current->link;
            --position;
        }
        previous->link = current->link;
        free(current->data);
        free(current);
        current = NULL;
    }
}

//Function deleteList() deletes the whole linked list
//Parameters:
//  head - pointer to the pointer of the first element in the linked list
//Return: function does not return anything
void deleteList(struct node **head){
    struct node *temp = *head;

    while(temp != NULL){
        free(temp->data);
        temp = temp->link;
        free(*head);
        *head = temp;
    }
}
