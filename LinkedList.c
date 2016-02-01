/*
Welcome friends ! Below is my Implementation of Singly LinkedList using C Language....
Try, learnt,implement and enjoy !!
Also, I have described the important methods and information in the README.md file for your reference...
If you are having any suggestions, you are most welcome :)
copyrights @ itzme-vasu....
*/

#include<stdio.h>
#include<stdlib.h>
//Create a common structure for "Node"
struct node
{
    int data;
    struct node *next;
}*start=NULL;
//Declare the functions before you define/proceed to main program.....
void create();
void display();
void insert_first();
void insert_end();
void insert_specific();
void delete_specific();
void reverse();
//Main Logic for Function calls.....
void main(){
    int choice=0;
    clrscr();
    printf("Wonderful, You are about to work with Linked List !! ");
    while(choice !=8){
        printf("nPlease select your choicen1.Create a Linked Listn2.Display the Linked Listn3.Insert Element at the beginningn4.Insert Element at endn5.Insert at specific noden6.Delete a specific elementn7.Reverse the Linked Listn8.Exitnnn");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3:
            insert_first();
            break;
            case 4:
            insert_end();
            break;
            case 5:
            insert_specific();
            break;
            case 6:
            delete_specific();
            break;
            case 7:
            reverse();
            break;
            case 8:
            printf("Okay, Goodbye !");
            break;
            default:
            printf("Wrong choice please enter again");
        }
    }
    getch();
}
void create()
{
    struct node *new_node,*current;
    int i,number;
    
    printf("Enter the no of nodes for a Linked List:n");
    scanf("%d",&number);
    for(i=0;i<number;i++)
    {
        
        new_node = (struct node *)malloc(1*sizeof(struct node)); // Dynamically create a new_node
        printf("Enter data for the node:n ");
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(start==NULL) // first check if starting node is null
        {
            start=new_node;
        }
        else if(start->next == NULL)
        {start->next=new_node;
            current=new_node;
        }
        else {
            current->next=new_node;
            current=new_node;
        }
    }
}
void display()
{
    struct node *temp_node;
    printf("The linked List:n");
    temp_node=start;
    while(temp_node != NULL)
    {
        printf("%d-->",temp_node->data);
        temp_node=temp_node->next;
    }printf("NULL");
}

void insert_first()
{
    int element; // Element to be inserted to the Linked List
    struct node *ptr; // Temp pointer to swap the start node and new_node
    printf("nEnter the element to be inserted :");
    scanf("%d",&element);
    if(start==NULL)
    {
        start=(struct node *)malloc(1*sizeof(struct node));
        start->data = element;
        start->next=NULL;
    }
    else
    {
        ptr = start; //Get the start node in the Temp node (Here ptr is the temp node)
        start=(struct node *)malloc(sizeof(struct node)); // Now dynamically create the start node again
        start->data = element;
        start->next = ptr;
    }
    printf("nNode %d inserted successfully",element);
}

void insert_end()
{
    int element; // Element to be inserted to the Linked List
    struct node *new_node,*current;
    
    printf("Enter the element to be inserted at the end: ");
    scanf("%d",&element);
    if(start==NULL)
    {
        start=(struct node *)malloc(1*sizeof(struct node)); // Assign new node
        start->data = element; //Assign Data
        start->next=NULL; //Creating further Link
    }
    else {
        new_node=(struct node *)malloc(1*sizeof(struct node));
        new_node->data=element;
        new_node->next = NULL;
        current=start;
        while(current->next != NULL)
        current = current->next;
        
        current->next=new_node;
    }
    printf("nNode %d inserted successfully",element);
}
void insert_specific()
{
    int element,specific_node,count=1;
    struct node *new_node,*current;
    if(start==NULL)
    printf("nLinked list is empty !");
    else
    {
        printf("nPlease enter the specific node position for your element: ");
        scanf("%d",&specific_node);
        printf("Enter the element to be inserted: ");
        scanf("%d",&element);
        
        current=start;
        while(current!= NULL)
        {
            if(count==specific_node)
            {
                new_node=(struct node *)malloc(sizeof(struct node));
                new_node->data = element;
                new_node->next=current->next;
                current->next= new_node;
            }else
            {
                current = current->next;
            }
            count++;
        }
    }
}
void delete_specific()
{
    int element;
    struct node *current,*prev;
    printf("Enter the element to be deleted: ");
    scanf("%d", &element);
    
    if(start == NULL)
    printf("n Linked List is empty !");
    else if(start->data == element)
    {
        current=start;
        start = start->next;
        printf("nDeleted Data: %d",element);
        free(current);
    }else
    {
        current = start;
        prev = start;
        while(current != NULL)
        {
            if(current->data==element)
            {
                printf("nDeleted Data: %d",element);
                prev -> next = current -> next;
                free(current);
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    
}
void reverse()
{
    /*Define 3 pointers for:
    current - for pointing to current node
    prev - To point to previous node of the current node
    reverse - to rotate the list in loop
    */
    struct node *current=start,*prev=NULL,*reverse;
    if(start == NULL)
    printf("nEmpty Linked List....Insert some values first !");
    else
    {
        while(current != NULL)
        {
            reverse = prev;
            prev = current;
            current = current->next;
            prev->next=reverse;
        }
        
        start =prev;
        printf("n Reversed linked list: n");
        display();
    }
}
