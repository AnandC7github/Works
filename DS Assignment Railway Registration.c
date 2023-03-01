#include<stdio.h>
#include<stdlib.h>
#define size 2
typedef struct NODE
{
	int reg_no;
	int age;
	char name[20];
	struct NODE *next;
} node;
node* deq();
int create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();
node *start;
node *front;
node *rear;
int count=0;
int num=0;

int create( )
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->reg_no=1;
	printf("Please enter the passenger name: ");
	scanf("%s", new->name);
	printf("Please enter the passenger age : ");
	scanf("%d", &new->age);
    if(new->age>=90 || new->age<=10) {
        free(new);
        return -1;
    }
	start=new;
	new->next=NULL;
	num++;
    return 1;
}

int reserve(node *start)
{
	int temp;
	if(start==NULL)
	{   
   		temp = create(start);
		 return temp;
	}
	else 
	{
		node *temp, *new_node;
		temp=start;
		while(temp->next!=NULL)
		{ 
		  temp=temp->next;
		}
		new_node=(node *)malloc(sizeof(node));
		printf("Name: ");
		scanf("%s", new_node->name);
		printf("Age : ");
		scanf("%d", &new_node->age);
   		if(new_node->age >=90 || new_node->age<=10){
   	    	return -1;
  		}
		new_node->next=NULL;
		if(num<=size)
		{
			num++;
			new_node->reg_no=num;
			temp->next=new_node;	
			return 1;
		}
		else
		{
			enq(new_node);
			return 0;
		}
	}
}

int cancel(int reg)
{
	node *ptr, *preptr, *new;
	ptr=start;
	preptr=NULL;
	if(start==NULL)
		return -1;
	if(ptr->next==NULL && ptr->reg_no==reg)
	{
		start=NULL;
		num--;
		free(ptr);
		return 1;
	}
	else{	
		while(ptr->reg_no!=reg && ptr->next!=NULL)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			if(ptr==NULL && ptr->reg_no!=reg)
				return -1;
			else
				preptr->next=ptr->next;
			free(ptr);
			new=deq();
			while(preptr->next!=NULL)
				preptr=preptr->next;
			preptr->next=new;
			num--;
			return 1;
	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}	
}

void display()
{
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("\nRegistration Number: %d\n", temp->reg_no);
		printf("Name : %s\n\n", temp->name);
		temp=temp->next;
    }
}

int main()
{
	int choice, status=0,canc=0, reg=0;
	start=NULL;
	rear=NULL;
	front=NULL;
	printf("\t\t\t**HELLO!! WELCOME TO ONLINE RAILWAY RESERVATION**\t\t\t\t\n");
	printf("\t\t\t---------------------------------------------\t\t\t\t\n");
	int ch =0;
	while(ch!=4)
	{
		printf("\n\nWhat do you want to do - \n 1. Book a ticket \n 2. Cancel Booking \n 3. Display passenger details \n 4.Help Desk\n5. exit\nEnter Your Choice\n");
		scanf("%d", &choice); 
		switch(choice)
		{	
			case 1 : status=reserve(start);
	   	  	        if(status==0)
	   	         	    printf("\nThe Booking is Full!! \nYou are added to waiting list and Waiting list number is %d", count);
	            	else if(status == -1) {
                	    printf("\n age not eligible");
                	}
                  	else
	               		printf(" \nThe Booking was Successful!!! Enjoy your journey! Your Reg No is %d\n\n", num);
	                break;
	   		case 2: printf(" \n Give the Registration number to be cancelled\n");
	              	scanf(" %d", &reg);
	             	if(reg>num)
	              		printf("Registration Number Invalid!!");
	              	else
	              	{
	              		canc=cancel(reg);
	              		if(canc==-1)
	              			printf("\nRegistration number invalid!!\n");
	              		else
	              			printf("\nRegistration cancelled successfully.\n");
	              		}
	              	break;
	              
	    	case 3: display();
	   			 	break;
	   		case 4: printf("\t\t\tWelcome to Help Desk\t\t\t\n");
	   				printf("\t\t\t*********************\t\t\t\n");
	   				printf("1.If you wish to reserve a seat, press 1, and then fill out the form by entering the passenger's name and age. Following that, you will be given a Registration number, which you must preserve. Age eligibility is important to notice.");
	   				printf("\n2.Alternatively, you can cancel a ticket by pressing 2 and entering the appropriate registration number. and a confirmation that the ticket was cancelled will follow. If you don't submit a valid registration number, an error will appear. Within 15 days, you will receive your money back.");
	   				printf("\n  Press 3 to see the whole list of passengers' details if you want to display their information.");
	   				printf("\n  When the procedure is finished, hit 5 to go.\n");
	   				printf("\n  Please call one of the following numbers if you need assistance with anything else: 9224949667 or 9998834895.\n");
	   				continue;
	   		case 5: exit(0);
	   				break;
	    	default: printf("\nWrong choice!\n");       
		}
	}
}

