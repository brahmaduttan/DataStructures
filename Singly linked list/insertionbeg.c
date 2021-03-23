#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next ;
};

int main()
{
    
    struct node *head =NULL;
    struct node *current = NULL;
    struct node *newnode = NULL;
    int i,n;
    printf("Enter limit\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        struct node *newnode=malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode ->next=NULL;
        
        if(head==NULL)
        {
            head=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }
    }
    
    for(current=head; current!=NULL;current=current->next)
    {
        printf("%d-->",current->data);
    }
    printf("NULL");

    printf("\nEnter the element to be added at the beginning\n");
    struct node *newnode1=malloc(sizeof(struct node));
    scanf("%d",&newnode1->data);
        newnode1 ->next=head;
        head=newnode1;
        current=newnode1;
         for(current=head; current!=NULL;current=current->next)
    {
        printf("%d-->",current->data);
    }
    printf("NULL");



}
        
     
        

  
