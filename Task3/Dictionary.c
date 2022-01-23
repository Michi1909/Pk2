#include <stdio.h>
#include "Dictionary.h"

typedef enum Status
{
    Empty,
    Full,

} status;

typedef struct Structure
{
    int data;
    status indexStatus;
} structure;

#define MAX 2
int elements = 0;

structure array[MAX];

int insert(int value)
{
    if (elements <= MAX)
    {
        for (int i = 0; i < MAX; i++)
        {
            int key = value % MAX;
            if (array[key].indexStatus != Full)
            {
                array[key].data = value;
                array[key].indexStatus = Full;
                elements++;
                return 1;
            }
            else
            {
                key++;
            }
        }
    }
    else
    {
        return 0;
    }
}

int delete (int value)
{

    if (elements <= MAX)
    {
        for (int i = 0; i < MAX; i++)
        {

            int key = value % MAX;

            if (array[key].data == value && array[key].indexStatus != Empty)
            {
                array[key].data = '\0';
                array[key].indexStatus = Empty;
                elements--;
                return 1;
            }
            else
            {
                key++;
            }
        }
    }
    else
    {
        return 0;
    }
}

int member(int value)
{
    if (elements <= MAX)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (array[i].data == value)
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}
