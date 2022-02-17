#include <Stdio.h>
#include "Queue.h"

int main(void)
{
    enqueue(1);
    enqueue(2);
    enqueue(2);
    printf("%i ", dequeue());
    enqueue(3);
    printf("%i ", dequeue());
    printf("%i ", dequeue());
    printf("%i ", dequeue());
    enqueue(4);
    enqueue(5);
    printf("%i ", dequeue());
    printf("%i \n", dequeue());
    return 0;
}