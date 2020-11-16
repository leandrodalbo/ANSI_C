#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  QItem *queue = createQueue();
  char cmdBuf[5];

  do
  {

    printf("check queue operations: add, print, exit... \n");
    scanf("%s", cmdBuf);

    if (strcmp(cmdBuf, "add") == 0)
    {
      int p, v;

      printf("inser priority -> HIGH:3, MEDIUM:2, LOW:1 \n");
      scanf("%d", &p);

      printf("insert value: \n");
      scanf("%d", &v);

      queue = addQItem(queue, v, p);
    }

    if (strcmp(cmdBuf, "print") == 0)
    {
      printQueue(queue);
    }

  } while (strcmp(cmdBuf, "exit") != 0);

  free(queue);
}