#include<stdio.h>
#include<stdlib.h>
struct doubly_list
{
   int info;
   struct doubly_list * forw;
   struct doubly_list* back;
};
typedef struct doubly_list node;
int scan_element();
void insert_f(node **,int);
void insert_l(node **,int);
void traverse(node *);
void insert_p(node **,int);
void insert_after_x(node **,int);
void delete_f(node **);
void delete_l(node **);
void delete_p(node **);
void delete_x(node **);
void count_n(node *);
void sort(node **);
void search_sorted(node *);
void search_unsorted(node *);
void insert_sorted(node **,int);
void new_alternate_element_list(node **);
void main()
{
node *start,*ptr1;
int ch,item;
start=NULL;
while(1)
{
printf("\nenter your choice\n");
printf("\n____________________________________________________________________________\n");
printf("\n1->Insert at first position\n2->Insert at last position\n3->Insert  at particular position\n4->Insert after a given item x\n5->Delete from first position\n6->Delete from last position\n7->Delete from particular position\n8->Delete a given item x\n9->Count no. of nodes\n10->Sort\n11->Search from unsorted list\n12->Search from sorted list\n13->Insert in sorted list\n14->To create new list by selectiong alternating element of given list\n15->Traverse\n00->Exit\n");
printf("\n____________________________________________________________________________\n");
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
case 3:
    item=scan_element();
    insert_p(&start,item);
    break;
case 4:
    item=scan_element();
    insert_after_x(&start,item);
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
     delete_x(&start);
     break;
case 9:
     count_n(start);
     break;
case 10:
     sort(&start);
     break;
case 11:
     search_unsorted(start);
     break;
case 12:
     search_sorted(start);
     break;
case 13:
     item=scan_element();
     insert_sorted(&start,item);
     break;
case 14:
     new_alternate_element_list(&start);
     break;
case 15:
     traverse(start);
     break;
default:
     printf("invalid choice\n");
}
}
}

int scan_element()
{    int item;
     printf("\nEnter the element that you want to insert\n");
     scanf("%d",&item);
     return item;
}

void insert_f(node ** ptr,int item)
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
         new->back=NULL;
          if(*ptr==NULL)

          {
             new->forw=NULL;
          }
          else
          {
              new->forw=(*ptr);
              (*ptr)->back=new;
          }
          (*ptr)=new;
    }
}

void traverse(node * ptr)
{
    if(ptr==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->info);
            ptr=ptr->forw;
        }
    }
}

void insert_l(node ** ptr,int item)
{
    node * new,*ptr1;
     new=(node *) malloc(sizeof(node));
     if(new==NULL)
     {
         printf("\nNo free memory is available\n");
     }
     else
     {
         new->info=item;
         new->forw=NULL;
          if(*ptr==NULL)
          {
             new->back=NULL;
            (*ptr)=new;
          }
          else
          {
              ptr1=*ptr;
              while(ptr1->forw!=NULL)
               {
                   ptr1=ptr1->forw;
               }
               new->back=ptr1;
               ptr1->forw=new;
          }

    }
}

void insert_p(node ** ptr,int item)
{

    int i=1,pos;
    node * new,*ptr1;
     new=(node *) malloc(sizeof(node));
     if(new==NULL)
     {
         printf("\nNo free memory is available\n");
     }
     else
     {
         printf("\nEnter the position at which you want to insert element\n");
         scanf("%d",&pos);
         new->info=item;
         if(pos==1)
         {
              new->back=NULL;
              if(*ptr==NULL)
              {
                 new->forw=NULL;
              }
              else
              {
                  new->forw=(*ptr);
                 (*ptr)->back=new;
              }
            (*ptr)=new;
        }
        else
        {
            ptr1=(*ptr);
            while(i<pos-1&&ptr1!=NULL)
            {
                ptr1=ptr1->forw;
                i++;
            }
            if(ptr1!=NULL)
            {
                new->forw=ptr1->forw;
                new->back=ptr1;
                ptr1->forw=new;
                ptr1->forw->back=new;
            }

            else
            {
                printf("\ncannot insert as position is invalid\n");
            }
        }
     }
    }


void insert_after_x(node ** ptr,int item)
{
    int i,x;
    node *new,*ptr1;
    ptr1=*ptr;
    while(ptr1!=NULL&&(ptr1->info)!=item)
    {
        ptr1=ptr1->forw;
    }
    if(ptr1!=NULL)
    {
        printf("\nThe element that you want to insert is already exist ...no need to insert again\n");
    }
    else
    {
        printf("\nEnter the element after which you want to insert\n");
        scanf("%d",&x);

    ptr1=(*ptr);
    while(ptr1!=NULL&&(ptr1->info)!=x)
    {
        ptr1=ptr1->forw;
    }
    if(ptr1==NULL)
    {
        printf("Cannot insert as the element after which you want to insert does not exist\n");
    }

    else
    {     new=(node *) malloc(sizeof(node));
          if(new==NULL)
          {
             printf("\nNo free memory is available\n");
          }
                new->info=item;
                new->forw=ptr1->forw;
                new->back=ptr1;
                ptr1->forw=new;
                ptr1->forw->back=new;

    }
    }
}

void delete_f(node ** ptr)
{
    node * ptr1;
     if(*ptr==NULL)
     {
         printf("Can not delete as list is empty\n");
     }
    ptr1=(*ptr);
    if((*ptr)->forw==NULL)
    {
        *ptr=NULL;
    }
    else
    {
      *ptr=(*ptr)->forw;
       (*ptr)->back=NULL;
    }
    free(ptr1);
}


void delete_l(node ** ptr)
{
    node *ptr1;
     if(*ptr==NULL)
     {
         printf("Can not delete as list is empty\n");
     }
     else
     {
        ptr1=(*ptr);
        if((*ptr)->forw==NULL)
        {
          *ptr=NULL;
        }
        else
        {
           while((ptr1->forw)!=NULL)
           {
              ptr1=ptr1->forw;
           }
            ptr1->back->forw=NULL;
        }
         free(ptr1);
      }
}


void delete_p(node ** ptr)
{
   node * ptr1;
   int i=1,pos;
   ptr1=(*ptr);
    if(*ptr==NULL)
     {
         printf("Can not delete as list is empty\n");
     }
     else
    {
       printf("\nEnter the position from which you want to delete element\n");
       scanf("%d",&pos);
       if(pos==1)
       {
          if((*ptr)->forw==NULL)
          {
               *ptr=NULL;
          }
          else
          {
               *ptr=(*ptr)->forw;
               (*ptr)->back=NULL;
          }
          free(ptr1);
     }
      else
     {
         while(i<pos&&ptr1!=NULL)
         {
             ptr1=ptr1->forw;
             i++;
         }
         if(ptr1==NULL)
         {
             printf("\nThe element that you want to delete is not present in the list\n");
         }
         else if(ptr1->forw==NULL)
         {
             ptr1->back->forw=ptr1->forw;
              free(ptr1);
         }
         else
         {
             ptr1->back->forw=ptr1->forw;
             ptr1->forw->back=ptr1->back;
             free(ptr1);
         }
   }
}
}


void delete_x(node ** ptr)
{
    int item;
    node * ptr1;
    if(*ptr==NULL)
     {
         printf("Can not delete as list is empty\n");
     }
     else
     {
          printf("\nEnter the element that you want to delete\n");
          scanf("%d",&item);
          ptr1=(*ptr);
          if((*ptr)->info==item)
          {
                if((*ptr)->forw==NULL)
                {
                   *ptr=NULL;
                }
                else
                {
                    *ptr=(*ptr)->forw;
                    (*ptr)->back=NULL;
                }
                free(ptr1);
          }
          else
    {
          while((ptr1->info!=item)&&(ptr1->forw!=NULL))
          {
              ptr1=ptr1->forw;

          }
             if(ptr1->forw==NULL)
            {
                 ptr1->back->forw=ptr1->forw;
                 free(ptr1);
            }
             else if(ptr1->info!=item)
            {
                 printf("\nThe element that you want to delete is not present in the list\n");
            }
             else
            {
                 ptr1->back->forw=ptr1->forw;
                 ptr1->forw->back=ptr1->back;
                 free(ptr1);
            }

     }
     }
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
            ptr1=ptr1->forw;
        }
    }
    printf("\nnumber of nodes=%d\n",i);
}

void sort(node ** ptr)
{
    node *ptr1,*ptr2;
    int temp;
    ptr1=*ptr;
    while(ptr1!=NULL)
    {
        ptr2=(*ptr);
        while(ptr2->forw!=NULL)
        {
            if((ptr2->info)>(ptr2->forw->info))
            {
                temp=ptr2->info;
                ptr2->info=ptr2->forw->info;
                ptr2->forw->info=temp;
            }
            ptr2=ptr2->forw;
        }
        ptr1=ptr1->forw;
    }

}


void search_unsorted(node * ptr)
{
   node * ptr1;
   int i=1,item;
   printf("\nEnter the element that you want to search\n");
   scanf("%d",&item);
   ptr1=(ptr);
   if(ptr==NULL)
    {
    printf("\nCan not search as list is empty\n");
    }
    else
{
   while(ptr1!=NULL&&ptr1->info!=item)
   {
       ptr1=ptr1->forw;
       i++;
   }
   if(ptr1==NULL)
   {
       printf("\nElement not found\n");
   }
   else
   {
       printf("Element found at %d position",i);
   }
}
}
void search_sorted(node *ptr)
{
    int i=1,pos,item;
    node *ptr1,*tptr;
    printf("\nEnter the element that you want to search\n");
    scanf("%d",&item);
    if(ptr==NULL)
    {
    printf("\nCan not search as list is empty\n");
    }
    else
    {  ptr1=ptr;
      while(ptr1->forw!=NULL&&(item>ptr1->info))
      {
          ptr1=ptr1->forw;
          i++;
      }

        if(ptr1->forw!=NULL)
        {
            printf("\nElement found at %d position",i);
        }
        else if(ptr1->info==item)
        {    printf("\nElement found at %d position",i);     }
        else
        {
            printf("\nElement not found\n");
        }
    }
}


void insert_sorted(node **ptr,int item)
{
     node * new,*ptr1;
     new=(node *) malloc(sizeof(node));
     if(new==NULL)
     {
         printf("\nNo free memory is available\n");
     }
     else
     {
         new->info=item;
         if(*ptr==NULL)
          {
             new->back=NULL;
             new->forw=NULL;
            (*ptr)=new;
          }
          else if(item<(*ptr)->info)
          {
               new->forw=(*ptr);
               new->back==NULL;
               (*ptr)->back=new;
               (*ptr)=new;
          }
          else
          {   ptr1=(*ptr);
              while(ptr1->forw!=NULL&&(item>ptr1->info))
              {
                  ptr1=ptr1->forw;
              }
              if(ptr1->forw!=NULL&&ptr1->info==item)
              {
                  printf("\nElement already present ..you dont need to insert again\n");
              }
              else if(ptr1->forw==NULL&&item>ptr1->info)
              {
                  new->back=ptr1;
                  ptr1->forw=new;
                  new->forw=NULL;
              }
              else
              {
                  ptr1=ptr1->back;
                  new->forw=ptr1->forw;
                  new->back=ptr1;
                  ptr1->forw=new;
                  ptr1->forw->back=new;
              }
          }
     }
}


void new_alternate_element_list(node ** ptr)
{
    node * start,*ptr1;
    ptr1=(*ptr);
    start=NULL;
    while(ptr1!=NULL&&ptr1->forw!=NULL)
    {

        insert_l(&start,ptr1->info);
        ptr1=ptr1->forw->forw;
    }
    if(ptr1!=NULL&&ptr1->forw==NULL)
    {
        insert_l(&start,ptr1->info);
    }
    printf("\nYour new list is:\n");
    traverse(start);

}

