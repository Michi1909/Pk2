#include <stdio.h>
#include "Queue.h"
#define MAX 2

int array[MAX];
int first = 0;
int last = 0;

void enqueue(int value)
{
    if (array[first] == '\0') //test if list is empty and if its first element
    {
        array[first] = value;
    }
    else //when list is not empty then find another key and set value
    {
        first = (first + 1) % MAX;
        if (array[first] == '\0')
        {
            array[first] = value;
        }
    }
}

int dequeue()
{
    if (array[last] == '\0')
    {
        last = 0;
        return -1;
    }
    else
    {
        //else:the list is not empty and we start to remove the oldest element
        int value = array[last]; //to know what we delete we have to return the value of the deleted Element
        array[last] = '\0';      //then we delete the oldest element with \0 null
        last = (last + 1) % MAX; // find the key with modulo
        return value;            //return value of deleted element
    }
}