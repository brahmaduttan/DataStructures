#include<stdio.h>
#include<stdlib.h>
#define n 5
int main()
{
    int queue[n],ch=1,front=-1,rear=-1,i,x=n,element;
    printf("Queue");
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");
    while(ch)
    {
        printf("\nEnter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
         printf("\n Enter no :");
                scanf("%d",&element);
            if(rear==x)
                printf("\n Queue is Full");
            else if(front ==-1 && rear==-1)
            {
                
                front++;
                rear++;
                queue[front]=element;
            }
            else
            {
                rear++;
                queue[rear]=element;
            }
            break;
        case 2:
            if(front==-1 &&  rear==-1)
            {
                printf("\n Queue is empty");
            }
            else if(front == rear)
            {
                front= rear =-1;
            }
            else{
                printf("Deleted element is %d", queue[front]);
                front++;
            }
            break;
        case 3:
            printf("\nQueue Elements are:\n ");
            if(front==-1 && rear== -1)
                printf("\n Queue is Empty");
            else
            {
                for(i=front; i<rear+1; i++)
                {
                    printf("%d",queue[i]);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice");
            }
        }
    }
    return 0;
}