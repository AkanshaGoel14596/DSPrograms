#include<stdio.h>
#include<stdlib.h>
struct list
{
   int coff;
   int expo;
   struct list * link;
};
typedef struct list node;
void insert(node **,int,int);
void traverse(node *);
void add(node**,node**,node**);
void main()
{
node *start1,*start2,*start3;
int ch=1,ch2,coff,expo;
start1=NULL;
start2=NULL;
start3=NULL;
printf("for entering data in polynomials:\n");
while(ch!=5)
{

printf("\nenter your choice\n");
printf("1->insert in first polynomial\n2->traverse first polynomial\n3->insert in second polynomial\n4->traverse second polynomial\n5->add\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
   printf("\nEnter cofficient and exponent\n");
   scanf("%d%d",&coff,&expo);
   insert(&start1,coff,expo);
   break;
case 2:
   traverse(start1);
   break;
case 3:
     printf("\nEnter cofficient and exponent\n");
     scanf("%d%d",&coff,&expo);
     insert(&start2,coff,expo);
     break;
case 4:
     traverse(start2);
     break;
case 5:
       add(&start1,&start2,&start3);
       printf("Your Polynomial after addition is:\n");
       traverse(start3);
       break;
default:
    printf("invalid choice\n");
}
}



}




void traverse(node * ptr)
{
    if(ptr==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {   printf("\n________________________________\n");
        while(ptr!=NULL)
        {
            printf("\ncofficient->%d\nexponent->%d",ptr->coff,ptr->expo);
            ptr=ptr->link;
        }
        printf("\n________________________________\n");
    }

}

void insert(node **ptr,int coff,int expo)
{

node * new1,*ptr1;
new1=(node *)malloc(sizeof(node));
if(new1==NULL)
{
    printf("\nNo free memory is available\n");
}
 new1->coff=coff;
 new1->expo=expo;
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
}
}


void add(node **ptr1,node **ptr2,node **ptr3)
{
     node * new1;
     int coff,expo;
     while(*ptr1!=NULL&&*ptr2!=NULL)
     {
         if(((*ptr1)->expo)>((*ptr2)->expo))
         {
             coff=(*ptr1)->coff;
             expo=(*ptr1)->expo;
             insert(ptr3,coff,expo);
             (*ptr1)=(*ptr1)->link;
         }
         else if(((*ptr1)->expo)<((*ptr2)->expo))

         {
             coff=(*ptr2)->coff;
             expo=(*ptr2)->expo;
             insert(ptr3,coff,expo);
             (*ptr2)=(*ptr2)->link;
         }
         else
         {
             coff=((*ptr1)->coff)+((*ptr2)->coff);
             expo=(*ptr1)->expo;
             insert(ptr3,coff,expo);
             (*ptr1)=(*ptr1)->link;
             (*ptr2)=(*ptr2)->link;
         }
     }
     while(*ptr1!=NULL)
     {
             coff=(*ptr1)->coff;
             expo=(*ptr1)->expo;
             insert(ptr3,coff,expo);
             (*ptr1)=(*ptr1)->link;
     }
       while(*ptr2!=NULL)
    {
             coff=(*ptr2)->coff;
             expo=(*ptr2)->expo;
             insert(ptr3,coff,expo);
             (*ptr2)=(*ptr2)->link;
    }
}
