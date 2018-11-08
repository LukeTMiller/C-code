#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<memory.h>
#include<stdint.h>
#include<stdio.h>
#include"linkedlist.h"

#define pause() clear(); getchar()

struct Student
{
	uint8_t grade;
	uint8_t age;
	struct Student * next;
};
void clear(void)
{
	char buffer[100];
	
	gets(buffer);
}
struct Student * sort(struct Student* head)
{
	uint8_t previous;
	struct Student *temphead;
	struct Student *current;
	
	if(head->next != 0)
	{
		while(current != head)
		{
			temphead = head;
			while(temphead->next !=current)
			{
			
				if (temphead->grade < temphead->next->grade)
				{
					previous = temphead->next->grade;
					temphead->next->grade = temphead->grade;
					temphead->grade = previous;
				}
		
				temphead= temphead->next;
				
				if(temphead->next == 0)
				{
					break;
				}
			}
			current = temphead;
		
		}
	}
	
return head;	
}
void printlist(struct Student *head)
{
	struct Student *watch;
	watch = head;
	while(watch != 0)
	{
		
		printf("grade:%d\n", watch->grade);
		printf("age:%d\n\n", watch->age);
		watch=watch->next; 
	}
	
}
struct Student *delete(struct Student *head, int node)
{
	int i = 0;
	struct Student *temp;
	struct Student *temphead;
	temphead = head;
	
	for(i = 0; i < (node); i++)
	{
		if (node == 1)
		{
			temphead = head->next;
			free(head);
			head=temphead;
			return head;
		}
		if (i == node-2)
		{
			temp = head;
			
		}
		if (i == node-1)
		{
		
			temp->next=head->next;
			free(head);
			break;
		}
		if (head->next == 0)
		{
			temp->next = 0;
			free(head);
		}
		head = head->next;
	}
	return 0;
}
void search(struct Student *head, int number)
{
	struct Student *watch;
	watch = head;
	while(watch != 0)
	{
		if (watch->grade == number)
		{
			printf("found:%d\n\n", watch->grade);
			break;
		}
		if (watch->next == 0)
		{
			printf("\ncould not find, sorry\n");
			break;
		}
		watch=watch->next; 
	}
	
}
void average(struct Student *head)
{
	int i = 0;
	int number = 0;

	while(head != 0)
	{
		number += head->grade;
		i++;
		head=head->next;
	}

	printf("\nthe average grade is: %d", number/i);
	pause();
}
void update(struct Student *head, int element, int newgrade, int newage)
{
	
	int i = 0;
	for(i = 0; i < (element); i++)
	{
		if (i == element-1)
		{
			head->grade=newgrade;
			head->age= newage;
		}
		
		
		head = head->next;
	}
}
struct Student *add(struct Student *current)
{
	
	struct Student *new;
	struct Student *had;
	had = current; 
	if(current == NULL)
	{
		current= (struct Student*)calloc(1, sizeof(struct Student));
		current->grade=(rand() % (100 + 1 - 3) + 3);
		current->age= (rand() % (17 + 1 - 14) + 14);
		
		return current;
	}
	
	
	while(current->next != 0)
	{
		current = current ->next; 
	
	}
	
	new = (struct Student*)calloc(1, sizeof(struct Student));
	current->next = new; 
	
	new->grade=(rand() % (100 + 1 - 3) + 3);
	new->age= (rand() % (17 + 1 - 14) + 14);
	new ->next = 0;
	
	return had;
}



