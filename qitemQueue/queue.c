#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

QItem *createQueue()
{

  QItem *queue = (QItem *)malloc(sizeof(QItem));

  queue->value = ITEM_INIT_VALUE;
  queue->priority = ITEM_INIT_VALUE;
  queue->link = NULL;

  return queue;
}

void printQueue(QItem *queue)
{
  while (queue != NULL)
  {
    printf(" queue value : %i \n", queue->value);

    queue = queue->link;
  }
}

QItem *addQItem(QItem *queue, int value, int priority)
{
  QItem *newItem = (QItem *)malloc(sizeof(QItem));

  newItem->value = value;
  newItem->priority = priority;

  if (queue->value == -1 && queue->priority == -1 && queue->link == NULL)
  {
    queue->value = value;
    queue->priority = priority;
  }
  else if (queue->value != -1 && queue->priority != -1 && priority < queue->priority)
  {
    newItem->link = queue;
    queue = newItem;
  }
  else
  {
    QItem *aux = queue;
    while (aux->link != NULL && priority > aux->priority)
    {
      aux = aux->link;
    }

    if (aux->link == NULL)
    {
      newItem->link = NULL;
      aux->link = newItem;
    }
    else
    {
      newItem->link = aux->link;
      aux->link = newItem;
    }
  }

  return queue;
}