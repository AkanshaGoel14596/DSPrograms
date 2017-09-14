#include<stdio.h>
int partition(int a[],int low ,int high);
void quicksort(int a[] ,int low ,int high);
void main() {
int a[20],n,i,max=0;
printf("Enter the size of array\n");
scanf("%d",&n);
printf("Enter the values\n");
for(i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
    if(a[i]>max)
    {
        max=a[i];
    }
}
a[n]=max+1;
quicksort(a ,0,n-1);
printf("Sorted array");
for(i=0;i<n;i++)
{
    printf("\n%d",a[i]);
}
}
void quicksort(int a[],int low,int high)
{
     int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int partition(int a[] ,int low ,int high)
{
    int i,j,pivot ,temp;
    i=low;
    j=high+1;
    pivot= a[low];
    do{
    do{
    i++;
    }
    while(a[i]<pivot);
    do{
    j--;
    } while(a[j]>pivot);
    if(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    }
    while(i<j);
    temp=a[j];
    a[j]=a[low];
    a[low]=temp;
     return j;
}