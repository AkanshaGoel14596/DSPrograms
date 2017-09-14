#include<stdio.h>
#include<stdlib.h>
struct list
{
   int info;
   struct list * link;
};
typedef struct list node;
void insert_l(node **);
void insert_f(node **);
void insert_p(node **);
void insert_after_x(node **);
void delete_l(node **);
void delete_f(node **);
void delete_p(node **);
void traverse(node *);
void count_n(node*);
void search_unsorted(node*);
void main()
{
node *start,*ptr1;
int ch;
start=NULL;
while(1)
{
printf("\nenter your choice\n");
printf("\n_______________________________________________________\n");
printf("1->Insert at first position\n2->Insert at last position\n3->Insert at particular position\n4->Insert after a given element x\n5->Delete first node\n6->Delete last node\n7->Delete a particular node\n8->Traverse\n9->Count number of nodes\n10->Search an element from unsorted list\n11->Exit");
printf("\n_______________________________________________________\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
   insert_f(&start);
   break;
case 2:
    insert_l(&start);
    break;
case 3:
    insert_p(&start);
    break;
case 4:
    insert_after_x(&start);
    break;
case 5:
   delete_f(&start);
    break;
case 6:
    delete_l(&start);
    break;
case 7:
    delete_p(&start);
    break;
case 8:
    traverse(start);
    break;
case 9:
    count_n(start);
    break;
case 10:
    search_unsorted(start);
     break;
case 11:
    exit(0);
default:
    printf("invalid choice\n");
}}}

void insert_f(node **ptr)
{
int item;
node * new1;
new1=(node *)malloc(sizeof(node));
if(new1==NULL)
{
    printf("\nNo free memory is available\n");
}
else
{
   printf("\nEnter element that you want to insert\n");
    scanf("%d",&item);
    new1->info=item;
    new1->link=*ptr;
    *ptr=new1;
}}
void traverse(node * ptr)
{
    if(ptr==NULL)
    {      printf("\nList is empty\n");      }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->info);
            ptr=ptr->link;
        }
    }
}
void insert_l(node **ptr)
{
int item;
node * new1,*ptr1;
new1=(node *)malloc(sizeof(node));
if(new1==NULL)
{
    printf("\nNo free memory is available\n");
}
else
{
  printf("\nEnter element that you want to insert\n");
 scanf("%d",&item);
 new1->info=item;
if(*ptr==NULL)
{
    new1->link=NULL;
    *ptr=new1;
}
else
{
    ptr1=*ptr;
    while(ptr1->link!=NULL)
    {
        ptr1=ptr1->link;
    }
    ptr1->link=new1;
    new1->link=NULL;
}}}

void insert_p(node **ptr)
{
  int item,pos,i;
  node * new1,*ptr1;
  new1=(node *)malloc(sizeof(node));
  if(new1==NULL)
  {
    printf("\nNo free memory is available\n");
  }
else
{
  printf("\nEnter element that you want to insert\n");
  scanf("%d",&item);
  printf("enter the position at which you want to insert value\n");
  scanf("%d",&pos);
  new1->info=item;

 if(pos==1)
 {
    new1->info=item;
    new1->link=*ptr;
    *ptr=new1;
 }
  else
   {
       ptr1=*ptr;
       i=1;
       while(i<(pos-1)&&ptr1!=NULL)
       {
           ptr1=ptr1->link;
           i++;
       }
       if(ptr1!=NULL)
       {
           new1->link=ptr1->link;
           ptr1->link=new1;

       }
       else
       {
           printf("\nINVALID POSITION\n");
       }}}}

void insert_after_x(node ** ptr)
{
  int item,item_x;
  node * new1,*ptr1;
  ptr1=*ptr;
  printf("\nEnter element that you want to insert\n");
  scanf("%d",&item);
  while((ptr1->info!=item)&&(ptr1->link!=NULL))
  {
      ptr1=ptr1->link;
  }
  if(ptr1->link!=NULL)
  {
      printf("element already present...no need to insert again\n");
  }
  else
  {
      new1=(node *)malloc(sizeof(node));
       if(new1==NULL)
       {   printf("\nNo free memory is available\n");       }
       else
       {
            new1->info=item;
            ptr1=*ptr;
            printf("\nenter  the element after which you want to insert %d ",new1->info);
            scanf("%d",&item_x);
            while((ptr1->info!=item_x)&&ptr1!=NULL)
            {
                ptr1=ptr1->link;
            }
            if(ptr1!=NULL)
            {
                new1->link=ptr1->link;
                ptr1->link=new1;
            }
            else
            {
                printf("Cannot insert because the element after which you want to insert is not present\n");
            }
       }
  }
}
void delete_f(node ** ptr)
{
    node *ptr1;
    if(*ptr==NULL)
{
    printf("Can not delete as list is empty\n");
}
   ptr1=*ptr;
   if((*ptr)->link==NULL)
   {
       *ptr=NULL;
   }
   else
   {
       *ptr=(*ptr)->link;
   }
   free(ptr1);
}
void delete_l(node ** ptr)
{
    node *ptr1,*tptr;
    if(*ptr==NULL)
{
    printf("Can not delete as list is empty\n");
}
else
{
    if((*ptr)->link==NULL)
   {
       *ptr=NULL;
   }
   else
   {
       ptr1=*ptr;
    while(ptr1->link!=NULL)
    {
        tptr=ptr1;
        ptr1=ptr1->link;
    }
    tptr->link=NULL;
    free(ptr);
   }
}
}
void delete_p(node ** ptr)
{   int i=1,pos;
    node *ptr1,*tptr;
    if(*ptr==NULL)
{
    printf("Can not delete as list is empty\n");
}
    ptr1=*ptr;
    tptr=*ptr;
    printf("Enter the position from which you want to delete element\n");
    scanf("%d",&pos);
    if(((*ptr)->link==NULL)&&(pos==1))
    {
        *ptr=NULL;
    }
    else if((pos==1)&&((*ptr)->link!=NULL))
    {
        *ptr=(*ptr)->link;
    }
    else
    {
        while(i>pos&&ptr1!=NULL)
        {
            tptr=ptr1;
            ptr1=ptr1->link;
        }
        if(ptr1!=NULL)
        {
            tptr->link=ptr1->link;
        }
        else
        {
            printf("Invalid position\n");
        }
    }
    free(ptr);
}
void count_n(node* ptr)
{
     int i=0;
    node *ptr1;
      if(ptr==NULL)
{}
    else
    {
        ptr1=ptr;
        while(ptr1!=NULL)
        {
            i++;
            ptr1=ptr1->link;
        }
    }
    printf("\nnumber of nodes=%d\n",i);
}

void search_unsorted(node *ptr)
{
    int i,pos,item;
    node *ptr1,*tptr;
    printf("\nEnter the element that you want to search\n");
    scanf("%d",&item);
    if(ptr==NULL)
    {
    printf("Can not search as list is empty\n");
    }
    else
    {
        ptr1=ptr;
        i=1;
        while((ptr1->info!=item)&&ptr1->link!=NULL)
        {
            ptr1=ptr1->link;
            i++;
        }
        if(ptr1->link!=NULL)
        {
            printf("\nElement found at %d position",i);
        }
        else if(ptr1->info==item)
        {    printf("\nElement found at %d position",i);     }
        else
        {
            printf("\nElement not found\n");      }}}
