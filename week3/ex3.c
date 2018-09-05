#include <stdio.h>
#include <stdlib.h>

typedef struct int_list
{
  int val;
  struct int_list *next;
} list_t;

int print_list(list_t *), insert_node (list_t **, int), delete_node (list_t **, int);

int main(void)
{
  int i;
  list_t *head = NULL;

  print_list(head);

  for (i = 0; i < 10; i++)
  {
    insert_node(&head, i);
  }
  print_list(head);

  delete_node(&head, 0);
  delete_node(&head, 9);
  delete_node(&head, 5);
  print_list(head);

  return 0;
}

int insert_node(list_t **head, int val)
{
  if (*head == NULL)
  {
    *head = (list_t *) malloc(sizeof(list_t));
    (*head)->next = NULL;
    (*head)->val = val;
  }
  else
  {
    list_t *swp = *head;
    list_t *tmp = (list_t *) malloc(sizeof(list_t));

    tmp->next = NULL;
    tmp->val = val;

    while (swp->next != NULL)
    {
      swp = swp->next;
    }

    swp->next = tmp;
  }

  return 0;
}

int delete_node(list_t **head, int val)
{
  if (*head == NULL)
  {
    return 1;
  }
  else
  {
    list_t *swp = *head, *pre = (list_t *) malloc(sizeof(list_t));
    pre = swp;

    if (swp->val == val)
    {
      list_t *tmp = (list_t *) malloc(sizeof(list_t));
      tmp->next = swp;
      *head = swp->next;
      free(tmp);

      return 0;
    }
    while (swp != NULL)
    {
      if (swp->val == val)
      {
        list_t *tmp = (list_t *) malloc(sizeof(list_t));
        tmp->next = swp->next;
        free(swp);
        pre->next = tmp->next;
        free(tmp);

        return 0;
      }
      
      pre = swp;
      swp = swp->next;
    }
  }

  return 1;
}

int print_list(list_t *head)
{
  if (head == NULL)
  {
    printf("Empty linked list\n");
  }
  else
  {
    printf("Linked list: ");
  }

  while (head != NULL)
  {
    printf("%d ", head->val);
    head = head->next;
  }
  
  printf("\n");
  return 0;
}
