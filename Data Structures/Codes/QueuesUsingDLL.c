#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
enum { VAL_SUCC = 0, VAL_ERR = 1};
 
struct dlqueue
{
  int num;
  struct dlqueue* next;
  struct dlqueue* prev;
};
 
 
struct dlqlist
{
  struct dlqueue* head;
  struct dlqueue* tail;
};
 
 
 
int enqueue(struct dlqlist*, int);
int dequeue(struct dlqlist*);
void print_queue(struct dlqlist* );

int main(void)
{
  struct dlqlist* s; //s is a pointer to dlqlist which has pointers head and tail
  s = malloc(1 * sizeof *s);
  int choice=0,data=0;
  if(NULL == s)
    {
      printf("Out Of Memory \n");
      return EXIT_FAILURE;
      
    }
  else
    {
      s->head = s->tail = NULL;
    }
 
//   enqueue(s, 10);
//   enqueue(s, 11);
//   enqueue(s, 12);
//   enqueue(s, 13);
//   print_queue(s);
  
//   dequeue(s);
//   printf("\n\n----------------------------\n");
//   print_queue(s);
 
//   dequeue(s);
//   printf("\n\n----------------------------\n");
//   print_queue(s);
 
 
//   dequeue(s);
//   printf("\n\n----------------------------\n");
//   print_queue(s);

    
    do
    {
        printf("\n1.EnQueue\t2.DeQueue\t3.Print\t\t4.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter the data value :");
            scanf("%d",&data);
            enqueue(s, data);
            break;
            case 2:
            dequeue(s);
            break;
            case 3:
            printf("\n\n----------------------------\n");
            print_queue(s);
            break;
            case 4:
            printf("\nProgram Complete!");
            break;
            default:
            printf("\nINVALID INPUT!");
            break;
        }
    }while(choice!=4);
  return EXIT_SUCCESS;
}

int enqueue(struct dlqlist* s, int i)
{
  int ret;
  if(NULL == s)
    {
      printf("Invalid\n");
      ret = VAL_ERR;
    }
  else if(NULL == s->head && NULL == s->tail)
    {
      struct dlqueue* p = malloc(1 * sizeof *p);
      if(NULL == p)
    {
      printf("Out Of Memory \n");
      ret = VAL_ERR;
    }
      else
    {
      p->num = i;
      p->prev = p->next = NULL;
 
      s->head = s->tail = p;
      ret = VAL_SUCC;
    }
    }
  else if(NULL == s->head || NULL == s->tail)
    {
      printf("Error\n");
      printf("One of the list's head/tail is null while other is not\n");
      ret = VAL_ERR;
    }
  else
    {
      struct dlqueue* p = malloc(1 * sizeof *p);
      if(NULL == p)
    {
      printf("Out Of Memory\n");
      ret = VAL_ERR;
    }
      else
    {
      p->num = i;
      p->prev = p->next = NULL;
 
      s->tail->next = p;
      p->prev = s->tail;
      s->tail = p;
      ret = VAL_SUCC;
    }
    }
 
  return ret;
}
 
 
 
int dequeue(struct dlqlist* s)
{
  int ret;
  if(NULL == s)
    {
      printf("Invalid \n");
      ret = VAL_ERR;
    }
  else if(NULL == s->head && NULL == s->tail)
    {
      printf("Nothing to Dequeue()\n");
      ret = VAL_SUCC;
    }
  else if(NULL == s->head || NULL == s->tail)
    {
      printf("Error");
      printf("One of the list's head/tail is null while other is not\n");
      ret = VAL_ERR;
    }
  else
    {
      struct dlqueue* p = s->head;
      if(NULL == s->head->next && NULL == s->tail->next) /* if last element */
    {
      s->head = s->tail = NULL;
    }
      else
    {
      s->head = s->head->next;
    }
 
      free(p);
      ret = VAL_SUCC;
    }
 
  return ret;
}

void print_queue(struct dlqlist* s)
{
  if(NULL == s)
    {
      printf("Invalid \n");
     }
  else if(NULL == s->head && NULL == s->tail)
    {
      printf("Nothing to print\n");
    }
  else if(NULL == s->head || NULL == s->tail)
    {
      printf("Error \n");
      printf("One of the list's head/tail is null while other is not\n");
    }
  else
    {
      struct dlqueue* p = s->head;
      while(p)
    {
      printf("num = %d\n", p->num);
      p = p->next;
    }
    }
}