#include <stdio.h>
#include <stdlib.h>

struct frame 
{
  int reference, lifespan, pagenumber;
  struct frame *next;
} frame;

int main(void)
{
  FILE *f = fopen("input.txt", "r");
  int *arr = NULL, i, j, size = 0, fsize = 0, hitrate = 0, missrate = 0;

  while ((i = fgetc(f)) != EOF)
  {
    if (i == ' ')
    {
      size += 1;
    } 
  }
  size += 1;

  fclose(f);
  f = fopen("input.txt", "r");
  arr = (int*) calloc(size, sizeof(int));
  
  for (i = 0; i < size; i++)
  {
    fscanf(f, "%d", &arr[i]);
  }

  printf("The number of page frames: ");
  scanf("%d", &fsize);

  struct frame *head = (struct frame*) malloc(sizeof(struct frame));
  head->next = NULL;
  struct frame *frm_a = head;

  for (i = 0; i < fsize; i++)
  {
    frm_a->next = (struct frame*) malloc(sizeof(struct frame));
    
    frm_a->reference = -1;
    frm_a->lifespan = 0;
    frm_a->pagenumber = -1;
   
    frm_a = frm_a->next;
  }
  frm_a->next = NULL;
  frm_a = head;

  for (i = 0; i < size; i++)
  {
    frm_a = head;
    struct frame *min = NULL;
    int is_min = 99999999, is_insert = 0, is_init = 0;
    while (frm_a->next != NULL)
    {
      frm_a->lifespan = frm_a->lifespan >> 1;
      //printf("arr[%d] = %d\n%d %d %d\n",i , arr[i], frm_a->reference, frm_a->lifespan, frm_a->pagenumber);

      if (!is_insert)
      {
        if (frm_a->reference == -1)
        {
          frm_a->pagenumber = arr[i];
          frm_a->reference = 1;
          frm_a->lifespan = 64;
          is_insert = 1;
          is_init = 1;
        } 
        else if (frm_a->pagenumber == arr[i])
        {
          frm_a->reference = 1;
          frm_a->lifespan = 64 | frm_a->lifespan >> 1;
          min = frm_a;
          hitrate += 1;
          is_insert = 1;
        }
        else
        {
          frm_a->reference = 0;
        }

        if ((frm_a->lifespan < is_min) && !is_insert)
        {
          min = frm_a;
          is_min = frm_a->lifespan;
        }
      }
      
      frm_a = frm_a->next;
    }

    if(min != NULL && !is_init)
    {
      min->pagenumber = arr[i];
      min->lifespan = 64;
      missrate += 1;
    }
    //printf("\n");
  }

  printf("hitrate = %d\nmissrate = %d\n", hitrate, missrate);
  return 0;
}