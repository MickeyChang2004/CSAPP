/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    /* Remember to handle the case if malloc returned NULL */
    queue_t *q=(queue_t*)malloc(sizeof(queue_t));//malloc needs mandatory type change
    if(q==NULL)
      {return NULL;}
    q->head=NULL;
    q->tail=NULL;
    q->queue_size=0;//set size to zero
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
  if(q==NULL)
    return;
  for(int i=0;i<q->queue_size;i++)
  {
    list_ele_t *temp=q->head;//pick the first one out
    q->head=q->head->next;//move head
    free(temp);
  }
  free(q);//free the storage created by malloc
    /* Remember to free the queue structue and list elements */
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    /* What should you do if the q is NULL? */
    if(q==NULL)
      return false;
    list_ele_t* temp=(list_ele_t*)malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if(temp==NULL)
      return false;
    temp->value=v;
    if(q->queue_size==0)//empty queue
    {
      q->head=temp;
      q->tail=temp;
      temp->next=NULL;
    }
    else
    {
    temp->next=q->head;
    q->head=temp;
    }
    q->queue_size++;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* Remember: It should operate in O(1) time */
    if(q==NULL)
      return false;
    list_ele_t* temp=(list_ele_t*)malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if(temp==NULL)
      return false;
    temp->value=v;
    temp->next=NULL;//tail's next must be NULL
    if(q->queue_size==0)//empty queue
    {
      q->head=temp;
      q->tail=temp;
    }
    else
    {
    q->tail->next=temp;
    q->tail=temp;
    }
    q->queue_size++;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    if(q==NULL)
      return false;
    if(q->queue_size==0)
      return false;
    list_ele_t* temp=q->head;
    q->head=q->head->next;
    if(vp!=NULL)//vp non-NULL
      *vp=temp->value;
    free(temp);
    q->queue_size--;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if(q==NULL||q->queue_size==0)
      return 0;
    return q->queue_size;
    /* Remember: It should operate in O(1) time */
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
  if(q==NULL||q->queue_size==0)
    return;
  list_ele_t* original_head=q->head;//store the original ones
  list_ele_t* original_tail=q->tail;
  for(int i=0;i<q->queue_size-1;i++)//reverse
  {
    list_ele_t* temp=q->head;
    q->head=q->head->next;
    temp->next=q->tail->next;
    q->tail->next=temp;
  }
  q->head=original_tail;
  q->tail=original_head;
  return;
}

