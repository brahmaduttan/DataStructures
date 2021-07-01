#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertion_beginning();  
void insertion_last();  
void insertion_specified();  
void deletion_beginning();  
void deletion_last();  
void deletion_specified();  
void display();  
void search();  
void main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  

        
        printf("\n\n1.Insertion at Beginning\n2.Insertion at a location\n3.Insertion at last\n4.Deletion at Beginning\n5.Delete a specific Element\n6.Deletion at last\n7.Search\n8.Traverse\n9.Exit\n");  
        printf("\nEnter your choice: ");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
                insertion_beginning();  
                break;  
            case 2:  
                insertion_at_location();
                break;  
            case 3:  
                insertion_last();
                break;  
            case 4:  
                deletion_beginning();  
                break;  
            case 5:  
                deletion_element();  
                break;  
            case 6:  
                deletion_last();
                break;  
            case 7:  
                search();  
                break;  
            case 8:  
                traverse();  
                break;  
            case 9:  
                exit(0);  
                break;  
            default:  
                printf("Please enter valid choice: ");  
        }  
    }  
}  
void insertion_beginning()  
{  
   struct node *ptr;   
   int e;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nList...Overflow...List is full...!!!");  
   }  
   else  
   {  
    printf("\nEnter element value: ");  
    scanf("%d",&e);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=e;
       head=ptr;  
   }  
   else   
   {  
       ptr->data=e;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nElement inserted");  
}  
     
} 

void insertion_at_location()  
{  
   struct node *ptr,*temp;  
   int e,location,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nList...Overflow...List is Full...!!!");  
   }  
   else  
   {  
       temp=head;  
       printf("\nEnter the location at which next to enter: ");  
       scanf("%d",&location);  
       for(i=0;i<location;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\n There are less than %d elements", location);  
               return;  
           }  
       }  
       printf("\nEnter element value: ");  
       scanf("%d",&e);  
       ptr->data = e;  
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       temp->next->prev=ptr;  
       printf("\nElement inserted");  
   }  
}  

void insertion_last()  
{  
   struct node *ptr,*temp;  
   int e;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nList...Overflow...List is Full...!!!");  
   }  
   else  
    {  
       printf("\nEnter element value: ");  
       scanf("%d",&e);  
        ptr->data=e;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
    }  
     printf("\nElement inserted");  
}  

void deletion_beginning()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList...Underflow...List is Empty...!!!");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nElement deleted");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nElement deleted");  
    }  
  
}  
void deletion_element()  
{  
    struct node *ptr, *temp;  
    int e;  
    printf("\n Enter the Element to delete: ");  
    scanf("%d", &e);  
    ptr = head;  
    while(ptr -> data != e)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL) 
    {  
        printf("\nDeletion not Possible!!!");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("\nElement deleted");  
    }     
}

void deletion_last()  
{  
    struct node *ptr,*temp;  
    if(head == NULL)  
    {  
        printf("\nList...Underflow...List is Empty...!!!");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nElement deleted");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        temp = ptr -> prev 
        temp -> next = NULL;   
        free(ptr);  
        printf("\nElement deleted");  
    }  
}  
  
void traverse()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is Empty...!!!");
    }
    else
    {
        printf("\n Elements in List...");  
        ptr = head;  
        while(ptr != NULL)  
        {  
            printf("%d\t",ptr->data);  
            ptr=ptr->next;  
        }
    }
}   

void search()  
{  
    struct node *ptr;  
    int e,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)
    {  
        printf("\nList is Empty...!!!");  
    }  
    else  
    {   
        printf("\nEnter the value of element to search: \n");   
        scanf("%d",&e);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == e)  
            {  
                printf("\nElement at location %d ",i);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nElement not found\n");  
        }  
    }     
          
}  