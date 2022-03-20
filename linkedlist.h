#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stddef.h>

struct node{
    void *data;
    struct node *link;
};

void createList(struct node **head);
int countOfNodes(struct node *head);
void printData(struct node *head, void (*fptr)(void *));
void printInt(void *n);
void printChar(void *n);
void addAtBeginning(struct node **head, void *data, size_t dataSize);
void addAtEnd(struct node **head, void *data, size_t dataSize);
void addAtPosition(struct node **head, void *data, int pos, size_t dataSize);
void deleteFirst(struct node **head);
void deleteLast(struct node **head);
void deleteAtPosition(struct node **head, int position);
void deleteList(struct node **head);

#endif /*LINKEDLIST_H_INCLUDED */