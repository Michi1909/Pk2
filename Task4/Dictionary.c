#include <stdio.h>
#include <stdlib.h>
#include "Dictionary.h"
#define MAX 2

typedef struct Node node;
struct Node
{
    int data;
    node *next;
};

node *array[MAX] = {NULL};

int insert(int value)
{
    int key = value % MAX;
    node *ram = (node *)malloc(sizeof(node));
    if (ram != NULL)
    {
        ram->data = value;
        ram->next = array[key];
        array[key] = ram;
        return 1;
    }
    else
    {
        return 0;
    }
}

int delete (int value)
{
    int key = value % MAX;
    if (array[key] != NULL)
    {
        node *temp = array[key];
        node *beforeTemp = NULL;

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                if (beforeTemp == NULL)
                { // data in the first index
                    array[key] = array[key]->next;
                }
                else
                {
                    beforeTemp->next = temp->next;
                }
                free(temp);
                return 1;
            }
            else
            {
                beforeTemp = temp;
                temp = temp->next;
            }
        }
        return 0;
    }
    return 0;
}

int member(int value)
{
    int key = value % MAX;
    if (array[key] != NULL)
    {
        node *temp = array[key];
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
    return 0;
}