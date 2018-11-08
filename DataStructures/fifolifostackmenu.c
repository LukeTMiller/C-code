#include "Quemenu.h"
#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define pause()                                                                \
	clear();                                                               \
	getchar()

struct Student
{
	uint8_t grade;
	uint8_t age;
	struct Student *next;
};

struct stack_header
{
	struct Student *head;
	struct Student *top;
	struct Student *tail;
};
void fifotest(struct Student *head, int r)
{
	int i = 0;
	int counter = 0;
	struct Student *tail = 0;
	printf("printing empty fifo que");
	pause();
	printlist(head);
	printf("dequeing empty fifo que");

	if (head != 0)
	{
		if (counter == 1)
		{
			head = delete (head, counter, r);
			counter--;
		}
		else
		{

			head = delete (head, 1, r);

			counter--;
		}
	}
	else
	{
		printf("\nfifo que is empty");
		getchar();
	}
	printf("enqueing element\n");

	if (head == 0)
	{

		head = add(head);
		tail = head;
		counter++;
	}
	else
	{
		tail = addfifo(tail);
		counter++;
	}

	printlist(head);
	printf("enqueing 9 elements");
	getchar();

	for (i = 0; i < 9; i++)
	{

		if (head == 0)
		{

			head = add(head);
			tail = head;
			counter++;
		}
		else
		{
			tail = addfifo(tail);
			counter++;
		}
	}
	printlist(head);

	printf("dequeing 10 elements\n");
	for (i = 0; i < 10; i++)
	{

		if (head != 0)
		{
			if (counter == 1)
			{
				head = delete (head, counter, r);
				counter--;
			}
			else
			{

				head = delete (head, 1, r);

				counter--;
			}
		}
		else
		{
			printf("\nfifo que is empty");
			getchar();
		}
	}
	printf("dequeing 1 more element\n");
	if (head != 0)
	{
		if (counter == 1)
		{
			head = delete (head, counter, r);
			counter--;
		}
		else
		{

			head = delete (head, 1, r);

			counter--;
		}
	}
	else
	{
		printf("\nfifo que is empty");
		getchar();
	}
	printf("printing empty fifo que");
	getchar();
	printlist(head);
}
void stacktest(struct Student *head, int r)
{
	int i = 0;
	int counter = 0;
	printf("printing empty stack");
	pause();
	printlist(head);
	printf("popping empty stack");

	if (head != 0)
	{
		counter--;
		head = delete (head, 1, r);
	}
	else
	{
		printf("\nstack is empty");
		getchar();
	}
	printf("pushing element");
	getchar();
	if (counter < 10)
	{
		if (head == 0)
		{
			head = add(head);
			counter++;
		}
		else
		{
			head = add_stack(head);
			counter++;
		}
	}
	else
	{
		printf("stack is full");
		getchar();
	}

	printlist(head);
	printf("pushing 9 elements");
	getchar();
	for (i = 0; i < 9; i++)
	{
		if (counter < 10)
		{
			if (head == 0)
			{
				head = add(head);
				counter++;
			}
			else
			{
				head = add_stack(head);
				counter++;
			}
		}
		else
		{
			printf("stack is full");
			pause();
		}
	}

	printlist(head);
	printf("pushing 1 more element\n");
	if (counter < 10)
	{
		if (head == 0)
		{
			head = add(head);
			counter++;
		}
		else
		{
			head = add_stack(head);
			counter++;
		}
	}
	else
	{
		printf("stack is full");
		getchar();
	}

	printf("popping 10 elements\n");
	for (i = 0; i < 10; i++)
	{
		if (head != 0)
		{
			counter--;
			head = delete (head, 1, r);
		}
		else
		{
			printf("\nstack is empty");
			getchar();
		}
	}
	printf("popping 1 more element\n");

	if (head != 0)
	{
		counter--;
		head = delete (head, 1, r);
	}
	else
	{
		printf("\nstack is empty");
		getchar();
	}

	printf("printing empty stack");
	getchar();
	printlist(head);
}

void lifotest(struct Student *head, int r)
{
	int i = 0;
	int counter = 0;
	printf("printing empty lifo que");
	pause();
	printlist(head);
	printf("dequeing empty lifo que");

	if (head != 0)
	{
		counter--;
		head = delete (head, 1, r);
	}
	else
	{
		printf("\nlifo que is empty");
		getchar();
	}
	printf("enqueing element");
	getchar();

	if (head == 0)
	{
		head = add(head);
		counter++;
	}
	else
	{
		head = add_stack(head);
		counter++;
	}

	printlist(head);
	printf("enqueing 9 elements");
	getchar();
	for (i = 0; i < 9; i++)
	{

		if (head == 0)
		{
			head = add(head);
			counter++;
		}
		else
		{
			head = add_stack(head);
			counter++;
		}
	}

	printlist(head);

	printf("dequeing 10 elements\n");
	for (i = 0; i < 10; i++)
	{
		if (head != 0)
		{
			counter--;
			head = delete (head, 1, r);
		}
		else
		{
			printf("\nlifo que is empty");
			getchar();
		}
	}
	printf("dequeing 1 more element\n");

	if (head != 0)
	{
		counter--;
		head = delete (head, 1, r);
	}
	else
	{
		printf("\nlifo que is empty");
		getchar();
	}

	printf("printing empty lifo que");
	getchar();
	printlist(head);
}
struct Student *add_stack(struct Student *head)
{
	struct Student *new;

	new = (struct Student *)calloc(1, sizeof(struct Student));
	new->next = head;

	new->grade = (rand() % (100 + 1 - 3) + 3);
	new->age = (rand() % (17 + 1 - 14) + 14);

	return new;
}

int stack(int r)
{
	int p = 0;
	struct Student *head = 0;
	int d = 0;
	int s = 0;
	int v = 0;
	int numbertosearchfor = 0;
	int counter = 0;

	while (1)
	{
		printf("\nMenu:\n1 to push\n2 to pop\n3 to update the grade "
		       "and age of the "
		       "stack\n4 to search for a grade\n5 to print the "
		       "stack\n6 to print "
		       "average grade\n7 to test \n8 to quit\n");
		scanf("%d", &p);

		switch (p)
		{

		case (1):
			if (counter < 10)
			{
				if (head == 0)
				{
					head = add(head);
					counter++;
				}
				else
				{
					head = add_stack(head);
					counter++;
				}
			}
			else
			{
				printf("stack is full");
				pause();
			}
			break;
		
			case (2):
				if (head != 0)
				{
					counter--;
					head = delete (head, 1, r);
				}
				else
				{
					printf("\nstack is empty");
					pause();
				}
				break;

			case (3):
				if (head != 0)
				{
				PLEASEGOBACK:
					printf("\nwhat element do you want to "
					       "update?\n");
					scanf("%d", &d);
					if (d > counter || d < 0)
					{
						printf("there is no element %d",
						       d);
						pause();
						goto PLEASEGOBACK;
					}
					printf("\nwhat is the grade you want "
					       "to update it to\n");
					scanf("%d", &s);
					printf("\nwhat is the age you want to "
					       "update it to\n");
					scanf("%d", &v);
					update(head, d, s, v);
				}
				else
				{
					printf("\nstack is empty");
					pause();
				}
				break;

			case (4):
				if (head != 0)
				{

					printf("\nwhat grade do you want to "
					       "find?\n");
					scanf("%d", &numbertosearchfor);
					clear();
					search(head, numbertosearchfor);
					break;
				}
				else
				{
					printf("\nstack is empty");
					pause();
				}
			

		case (5):

			printlist(head);
			printf("press enter to continue");
			pause();
			break;
		case (6):
			if (head != 0)
			{
				average(head);
			}
			else
			{
				printf("\nstack is empty");
				pause();
			}

			break;
		case (7):
			if (head == 0)
			{
				stacktest(head, r);
			}
			else
			{
				printf("stack needs to be empty");
			}
			break;
		case (8):
			return 0;

		default:
			printf("wrong input\n\n");
			pause();
		}
	}
}

int lifo(int r)
{
	int p = 0;
	struct Student *head = 0;
	int d = 0;
	int s = 0;
	int v = 0;
	int numbertosearchfor = 0;
	int counter = 0;

	while (1)
	{
		printf("\nMenu:\n1 to enque\n2 to deque\n3 to update the grade "
		       "and age of "
		       "the lifo que\n4 to search for a grade\n5 to print the "
		       "lifo que\n6 "
		       "to print average grade\n7 to test\n8 to quit\n");
		scanf("%d", &p);

		switch (p)
		{

		case (1):

			if (head == 0)
			{
				head = add(head);
				counter++;
			}
			else
			{
				head = add_stack(head);
				counter++;
			}

			break;
			

			case (2):
				if (head != 0)
				{
					counter--;
					head = delete (head, 1, r);
				}
				else
				{
					printf("\nlifo que is empty");
					pause();
				}
				break;

			case (3):
				if (head != 0)
				{
				GOBACK:
					printf("\nwhat element do you want to "
					       "update?\n");
					scanf("%d", &d);
					if (d > counter || d < 0)
					{
						printf("there is no element %d",
						       d);
						pause();
						goto GOBACK;
					}
					printf("\nwhat is the grade you want "
					       "to update it to\n");
					scanf("%d", &s);
					printf("\nwhat is the age you want to "
					       "update it to\n");
					scanf("%d", &v);
					update(head, d, s, v);
				}
				else
				{
					printf("\nlifo que is empty");
					pause();
				}
				break;

			case (4):
				if (head != 0)
				{

					printf("\nwhat grade do you want to "
					       "find?\n");
					scanf("%d", &numbertosearchfor);
					clear();
					search(head, numbertosearchfor);
					break;
				}
				else
				{
					printf("\nlifo que is empty");
					pause();
				}
			

		case (5):

			printlist(head);
			printf("press enter to continue");
			pause();
			break;
		case (6):
			if (head != 0)
			{
				average(head);
			}
			else
			{
				printf("\nlifo que is empty");
				pause();
			}

			break;
		case (7):
			if (head == 0)
			{
				lifotest(head, r);
			}
			else
			{
				printf("lifo que needs to be empty");
			}
			break;
		case (8):
			return 0;

		default:
			printf("wrong input\n\n");
			pause();
		}
	}
}
int fifo(int r)
{
	int p = 0;
	struct Student *head = 0;
	int d = 0;
	int s = 0;
	int v = 0;
	int numbertosearchfor = 0;
	int counter = 0;
	struct Student *tail = 0;

	while (1)
	{
		printf("\nMenu:\n1 to enque\n2 to deque\n3 to update the grade "
		       "and age of "
		       "the fifo que\n4 to search for a grade\n5 to print the "
		       "fifo que\n6 "
		       "to print average grade\n7 to test\n8 to quit\n");
		scanf("%d", &p);

		switch (p)
		{

		case (1):

			if (head == 0)
			{

				head = add(head);
				tail = head;
				counter++;
			}
			else
			{
				tail = addfifo(tail);
				counter++;
			}

			break;
			

			case (2):
				if (head != 0)
				{
					if (counter == 1)
					{
						head =
						    delete (head, counter, r);
						counter--;
					}
					else
					{

						head = delete (head, 1, r);

						counter--;
					}
				}
				else
				{
					printf("\nfifo que is empty");
					pause();
				}
				break;

			case (3):
				if (head != 0)
				{
				STILLGOBACK:
					printf("\nwhat element do you want to "
					       "update?\n");
					scanf("%d", &d);
					if (d > counter || d < 0)
					{
						printf("there is no element %d",
						       d);
						pause();
						goto STILLGOBACK;
					}
					printf("\nwhat is the grade you want "
					       "to update it to\n");
					scanf("%d", &s);
					printf("\nwhat is the age you want to "
					       "update it to\n");
					scanf("%d", &v);
					update(head, d, s, v);
				}
				else
				{
					printf("\nfifo que is empty");
					pause();
				}
				break;

			case (4):
				if (head != 0)
				{

					printf("\nwhat grade do you want to "
					       "find?\n");
					scanf("%d", &numbertosearchfor);
					clear();
					search(head, numbertosearchfor);
					break;
				}
				else
				{
					printf("\nfifo que is empty");
					pause();
				}
			

		case (5):

			printlist(head);
			printf("press enter to continue");
			pause();
			break;
		case (6):
			if (head != 0)
			{
				average(head);
			}
			else
			{
				printf("\nfifo que is empty");
				pause();
			}

			break;
		case (7):
			if (head == 0)
			{
				fifotest(head, r);
			}
			else
			{
				printf("fifo que needs to be empty");
			}
			break;
		case (8):
			return 0;

		default:
			printf("wrong input\n\n");
			pause();
		}
	}
}
void clear(void)
{
	char buffer[100];

	gets(buffer);
}
struct Student *sort(struct Student *head)
{
	uint8_t previous;
	struct Student *temphead;
	struct Student *current;

	if (head->next != 0)
	{
		while (current != head)
		{
			temphead = head;
			while (temphead->next != current)
			{

				if (temphead->grade < temphead->next->grade)
				{
					previous = temphead->next->grade;
					temphead->next->grade = temphead->grade;
					temphead->grade = previous;
				}

				temphead = temphead->next;

				if (temphead->next == 0)
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
	while (watch != 0)
	{

		printf("grade:%d\n", watch->grade);
		printf("age:%d\n\n", watch->age);
		watch = watch->next;
	}
}
struct Student *delete (struct Student *head, int node, int r)
{
	int i = 0;
	struct Student *temp;
	struct Student *temphead;
	temphead = head;

	for (i = 0; i < (node); i++)
	{
		if (node == 1)
		{
			temphead = head->next;
			if (r == 1)
			{
				printf("you have popped \ngrade:%d\nage:%d\n",
				       head->grade, head->age);
				getchar();
			}
			else if (r == 2)
			{
				printf("you have dequed \ngrade:%d\nage:%d\n",
				       head->grade, head->age);
				getchar();
			}
			else
			{
				printf("you have dequed \ngrade:%d\nage:%d\n",
				       head->grade, head->age);
				getchar();
			}
			free(head);
			head = temphead;
			return head;
		}
		if (i == node - 2)
		{
			temp = head;
		}
		if (i == node - 1)
		{

			temp->next = head->next;
			if (r == 1)
			{
				printf("you have popped \ngrade:%d\nage:%d\n",
				       head->grade, head->age);
				getchar();
			}
			else if (r == 2)
			{
				printf("you have dequed \ngrade:%d\nage:%d\n",
				       head->grade, head->age);
				getchar();
			}
			else
			{
				printf("you have dequed \ngrade:%d\nage:%d\n",
				       head->grade, head->age);
				getchar();
			}
			free(head);
			break;
		}
		if (head->next == 0)
		{
			temp->next = 0;
			if (r == 1)
			{
				printf("you have popped \ngrade:%d\nage:%d\n",
				       head->grade, head->age);
				getchar();
			}
			else if (r == 2)
			{
				printf("you have dequed \ngrade:%d\nage:%d\n",
				       head->grade, head->age);
				getchar();
			}
			else
			{
				printf("you have dequed \ngrade:%d\nage:%d\n",
				       head->grade, head->age);
				getchar();
			}
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
	while (watch != 0)
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
		watch = watch->next;
	}
}
void average(struct Student *head)
{
	int i = 0;
	int number = 0;

	while (head != 0)
	{
		number += head->grade;
		i++;
		head = head->next;
	}

	printf("\nthe average grade is: %d", number / i);
	pause();
}
void update(struct Student *head, int element, int newgrade, int newage)
{

	int i = 0;
	for (i = 0; i < (element); i++)
	{
		if (i == element - 1)
		{
			head->grade = newgrade;
			head->age = newage;
		}

		head = head->next;
	}
}
struct Student *add(struct Student *current)
{

	struct Student *new;
	struct Student *had;
	had = current;
	if (current == NULL)
	{
		current = (struct Student *)calloc(1, sizeof(struct Student));
		current->grade = (rand() % (100 + 1 - 3) + 3);
		current->age = (rand() % (17 + 1 - 14) + 14);

		return current;
	}

	while (current->next != 0)
	{
		current = current->next;
	}

	new = (struct Student *)calloc(1, sizeof(struct Student));
	current->next = new;

	new->grade = (rand() % (100 + 1 - 3) + 3);
	new->age = (rand() % (17 + 1 - 14) + 14);
	new->next = 0;

	return had;
}

struct Student *addfifo(struct Student *current)
{

	struct Student *new;

	if (current == NULL)
	{
		current = (struct Student *)calloc(1, sizeof(struct Student));
		current->grade = (rand() % (100 + 1 - 3) + 3);
		current->age = (rand() % (17 + 1 - 14) + 14);

		return current;
	}

	while (current->next != 0)
	{
		current = current->next;
	}

	new = (struct Student *)calloc(1, sizeof(struct Student));
	current->next = new;

	new->grade = (rand() % (100 + 1 - 3) + 3);
	new->age = (rand() % (17 + 1 - 14) + 14);
	new->next = 0;

	return new;
}
