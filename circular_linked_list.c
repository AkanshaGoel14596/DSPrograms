#include<stdio.h>
#include<stdlib.h>
struct circular_list
{
   int info;
   struct circular_list * next;
};
typedef struct circular_list node;
int scan_element();
void insert_f(node **,int);
void insert_l(node **,int);
void traverse(node *);
void insert_p(node **,int);
void delete_f(node **);
void delete_l(node **);
void search_unsorted(node *);

void main()
{
node *start,*ptr1;
int ch,item;
start=NULL;
while(1)
{
printf("\nenter your choice\n");
printf("1->Insert at first position\n2->Insert at last position\n3->Delete from first position\n4->Delete from lase position\n5->Search from unsorted list\n99->Insert at particular position\n111->traverse\n");
scanf("%d",&ch);
switch(ch)
{

case 1:
   item=scan_element();
   insert_f(&start,item);
   break;
case 2:
   item=scan_element();
   insert_l(&start,item);
   break;
case 99:
   item=scan_element();
   insert_p(&start,item);
   break;
case 3:
    delete_f(&start);
    break;
case 4:
     delete_l(&start);
     break;
case 5:
     search_unsorted(start);
     break;
case 111:
    traverse(start);
    break;
default:
    printf("\nInvalid choice\n");
}
}
}

int scan_element()
{    int item;
     printf("\nEnter the element that you want to insert\n");
     scanf("%d",&item);
     return item;
}

void insert_f(node ** tail,int item)
{
    node * new;
     new=(node *) malloc(sizeof(node));
     if(new==NULL)
     {
         printf("\nNo free memory is available\n");
     }
     else
     {
         new->info=item;
         if(*tail==NULL)
            {
                new->next=new;
                *tail=new;
            }
         else
         {
                new->next=(*tail)->next;
                (*tail)->next=new;
         }

     }

}

void traverse(node * tail)
{
    node * ptr;
    if(tail==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr=tail->next;
        while(ptr!=tail)
        {
            printf("\n%d",ptr->info);
            ptr=ptr->next;
        }
            printf("\n%d",ptr->info);
    }
}

void insert_l(node ** tail,int item)
{
    node * new;
     new=(node *) malloc(sizeof(node));
     if(new==NULL)
     {
         printf("\nNo free memory is available\n");
     }
     else
     {
         new->info=item;
          if(*tail==NULL)
          {
              new->next=new;
              *tail=new;
          }
          else
          {
              new->next=(*tail)->next;
              (*tail)->next=new;
              (*tail)=new;
          }
     }
}
void insert_p(node ** tail,int item)
{
  int pos,i;
  node * new,*ptr1;
  new=(node *)malloc(sizeof(node));
  if(new==NULL)
  {
    printf("\nNo free memory is available\n");
  }
  else
  {

  printf("enter the position at which you want to insert value\n");
  scanf("%d",&pos);
  new->info=item;

  if(pos==1)
  {
     if(*tail==NULL)
        {
                new->next=new;
                *tail=new;
        }
         else
         {
                new->next=(*tail)->next;
                (*tail)->next=new;
         }


 }
  else
  {
       ptr1=(*tail)->next;
       i=1;
       while(i<(pos-1)&&ptr1!=(*tail))
       {
           ptr1=ptr1->next;
           i++;
       }
       if(ptr1==(*tail))
       {
              new->next=(*tail)->next;
              (*tail)->next=new;
              (*tail)=new;
       }
       else if(ptr1!=(*tail))
       {
              new->next=ptr1->next;
              ptr1->next=new;
       }
       else
       {
           printf("\nINVALID POSITION\n");
       }
   }
}
}


void delete_f(node ** tail)
{
    node * ptr;
    if((*tail)==NULL)
    {
        printf("\nCannot delete because list is empty\n");
    }
    else
  {
   if((*tail)->next==(*tail))
   {     ptr=(*tail);
       (*tail)=NULL;
   }
   else
   {
       ptr=(*tail)->next;
       (*tail)->next=(*tail)->next->next;
   }
  }
  free(ptr);
}

void delete_l(node ** tail)
{
    node * ptr,*ptr1;
    if((*tail)==NULL)
    {
        printf("\nCannot delete because list is empty\n");
    }
    else
    {
      if((*tail)->next==(*tail))
      {     ptr=(*tail);
           (*tail)=NULL;
      }
      else
      {    ptr1=(*tail)->next;
           while(ptr1->next!=(*tail))
           {
               ptr1=ptr1->next;
           }
           ptr=ptr1->next;
           ptr1->next=(*tail)->next;
           (*tail)=ptr1;

      }
      free(ptr);
   }
}

void search_unsorted(node * tail)
{
    node * ptr;
    int i=1,item;
    printf("\nEnter the element that you want to search\n");
    scanf("%d",&item);
    ptr=tail->next;
    if(tail==NULL)
    {
        printf("Cannot search as list is empty\n");
    }
    while(ptr!=tail&&item!=ptr->info)
    {
         ptr=ptr->next;
         i++;
    }
    if(ptr!=tail)
    {
        printf("\nElement found at %d position\n",i);
    }
    else if(ptr->info==item)
    {
         printf("\nElement found at %d position\n",i);
    }
    else
    {
        printf("\nThe element that you want to search is not present in list\n");
    }
}
