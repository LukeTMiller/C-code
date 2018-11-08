#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<memory.h>
#include<stdint.h>
#include<stdio.h>
#include"linkedlist.h"

#define pause() clear(); getchar()

int main(void)
{
	struct Student *head = 0;
	
	int d = 0;
	int s = 0;
	int v = 0;
	int p = 0;
	int numbertobedeleted = 0;
	int numbertosearchfor = 0;
	time_t seconds;
	
	seconds = time(NULL);
	srand(seconds);

	

while(1)
{
	printf("\nMenu:\n1 to add an element\n2 to delete an element\n3 to update the grade and age of an element\n4 to search for a grade\n5 to sort the list\n6 to print the list\n7 to print average grade\n8 to quit\n");
	scanf("%d", &p);
	
	switch(p)
	{
		
		case(1): 
		if(head == 0)
		{
			head = add(head);
			
		}
		else 
		{
			add(head);
		}
		break;
		if (head != 0)
		{
			
			case(2):
			if (head != 0)
			{
				printf("\nWhich node should be deleted?\n");
				scanf("%d",&numbertobedeleted);
				clear();
				
				if(numbertobedeleted == 1)
				{
					head =delete(head, numbertobedeleted);
				}   		
				else
				{
					delete(head,numbertobedeleted);
				}
			
			}
			else
			{
				printf("\nyou need an element in your list");
				pause();
			}									
			break;
		
			case(3):
			if (head != 0)
			{
				printf("\nwhat element do you want to update?\n");
				scanf("%d", &d);
				printf("\nwhat is the grade you want to update it to\n");
				scanf("%d", &s);
				printf("\nwhat is the age you want to update it to\n");
				scanf("%d", &v);
				update(head, d,s,v);
			}
			else
			{
				printf("\nyou need an element in your list");
				pause();
			}
			break;
		
			case(4):
			if (head != 0)
			{
				
				printf("\nwhat grade do you want to find?\n");
				scanf("%d",&numbertosearchfor);
				clear();
				search(head,numbertosearchfor);
				break;
			}
			else
			{
				printf("\nyou need an element in your list");
				pause();
			}
			
			case(5):
			if (head != 0)
			{
				head =sort(head);
			}
			else
			{
				printf("\nyou need an element in your list");
				pause();
			}
			break;
		}
		
		case(6):
		
		printlist(head);
		printf("press enter to continue");
		pause();
		break;
		case(7):
		if (head != 0)
		{
			average(head);
		}
		else
		{
			printf("\nyou need an element in your list");
			pause();
		}
		
		break;
		case(8):
		return 0;
		
		default:
		printf("wrong input\n\n");
		pause();
	}
}
return 0;
}