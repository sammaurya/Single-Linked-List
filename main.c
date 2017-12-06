#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *first=NULL;

void create();         //Create Circular Linked List
void insertbeg();      //Insert at Beginning
void insertmid();      //Insert at Middle
void insertend();      //Insert at End
void deletebeg();      //Delete at Beginning
void deletemid();      //Delete at Middle
void deleteend();      //Delete at End
void sorting();
void print();          //Print

int main()
{
    int choice;
    START0:
    printf("\n\t  OPERATIONS IN CIRCULAR LINKED LIST");
    printf("\n\t------------------------------------\n");
    printf("\n1.Create\n2.Insert\n3.Delete\n4.Sorting\n5.Print\n6.Clear Screen\n7.Exit");
    do
    {
        printf("\n\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: printf("\n1.Insert at Begining\n2.Insert at Middle\n3.Insert at End");
                    do
                    {
                        printf("\n\nEnter Choice : ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: insertbeg();
                                    break;
                            case 2: insertmid();
                                    break;
                            case 3: insertend();
                                    break;
                            default: printf("\nWrong Choice!!!");
                        }
                    }while(choice!=1&&choice!=2&&choice!=3);
                    break;
            case 3: printf("\n1.Delete at Begining\n2.Delete at Middle\n3.Delete at End");
                    do
                    {
                         printf("\n\nEnter Choice : ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: deletebeg();
                                    break;
                            case 2: deletemid();
                                    break;
                            case 3: deleteend();
                                    break;
                            default: printf("\nWrong Choice!!!");
                        }
                    }while(choice!=1&&choice!=2&&choice!=3);
                    break;
            case 4: sorting();
                    break;
            case 5: print();
                    break;
            case 6: system("cls");
                    goto START0;
                    break;
            case 7: printf("\nExiting...\n");
                    break;
            default: printf("\nWrong Choice!!!\nEnter again : ");
        }
    }while(choice!=7);
    return 0;
}

void create()
{
    char ch;
    struct node *ptr,*cpt;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    first=ptr;
    do
    {
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        ptr->next=cpt;
        ptr=cpt;
        printf("You want to Continue (Press C) :");
        scanf(" %c",&ch);
    }while(ch=='c'||ch=='C');
    ptr->next=first;
}

void insertbeg()
{
    struct node *ptr,*cpt;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=first;
        while(ptr->next!=first)
        {
            ptr=ptr->next;
        }
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        ptr->next=cpt;
        cpt->next=first;
        first=cpt;
        printf("Data %d is Inserted",cpt->data);
        }
}

void insertmid()
{
    int num;
    struct node *ptr,*cpt;
    ptr=first;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        printf("Enter Data After Which You Want to Insert : ");
        scanf("%d",&num);
        while(ptr->data!=num)
        {
            ptr=ptr->next;
        }
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        cpt->next=ptr->next;
        ptr->next=cpt;
        printf("Data %d is Inserted",cpt->data);
    }
}

void insertend()
{
    struct node *ptr,*cpt;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=first;
        while(ptr->next!=first)
        {
            ptr=ptr->next;
        }
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        cpt->next=first;
        ptr->next=cpt;
        printf("Data %d is Inserted",cpt->data);
    }
}

void deletebeg()
{
    struct node *ptr,*cpt;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=first;
        cpt=ptr->next;
        while(ptr->next!=first)
        {
            ptr=ptr->next;
        }
        ptr->next=cpt;
        ptr=first;
        ptr->next=NULL;
        printf("Data Deleted : %d\n",ptr->data);
        first=cpt;
        free(ptr);
    }
}

void deletemid()
{
    int num;
    struct node *ptr,*cpt;
    if(first==NULL)
    {
        printf("Link List is Inserted");
    }
    else
    {
        printf("Enter Data you want to delete : ");
        scanf("%d",&num);
        ptr=first;
        do
        {
            if(ptr->data==num)
            {
                break;
            }
            cpt=ptr;
            ptr=ptr->next;
        }while(ptr!=first);
        if(ptr==first)
        {
            printf("Data %d is Not Found",num);
        }
        else
        {
            cpt->next=ptr->next;
            ptr->next=NULL;
            printf("Data Deleted : %d\n",ptr->data);
            free(ptr);
        }
    }
}

void deleteend()
{
    struct node *ptr,*cpt;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=first;
        while(ptr->next!=first)
        {
            cpt=ptr;
            ptr=ptr->next;
        }
        cpt->next=first;
        printf("Data Deleted : %d\n",ptr->data);
        free(ptr);
    }
}

void sorting()
{
    int temp;
    struct node *ptr,*cpt;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=first;
        while(ptr->next!=first)
        {
            cpt=ptr->next;
            while(cpt!=first)
            {
                if(ptr->data>cpt->data)
                {
                    temp=ptr->data;
                    ptr->data=cpt->data;
                    cpt->data=temp;
                }
                cpt=cpt->next;
            }
            ptr=ptr->next;
        }
        printf("\nData List is Sorted\n");
    }
}
void print()
{
    struct node *ptr;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=first;
        printf("\nData : %d",ptr->data);
        do
        {
        ptr=ptr->next;
        printf("\nData : %d",ptr->data);
        }while(ptr->next!=first);
    }
}
