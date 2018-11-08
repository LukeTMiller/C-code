
#include "binarytree.h"

struct Student *addnode(struct Student *head, struct Student *new);
struct Student
{
	uint8_t grade;
	uint8_t age;
	struct Student *leftnext;
	struct Student *rightnext;
};

struct Student *add(struct Student *head)
{

	struct Student *new;

	if (head == NULL)
	{
		head = (struct Student *)calloc(1, sizeof(struct Student));
		head->grade = (rand() % (100 + 1 - 3) + 3);
		head->age = (rand() % (17 + 1 - 14) + 14);
		printf("grade:\n%d\n", head->grade);
		return head;
	}

	else
	{
		new = (struct Student *)calloc(1, sizeof(struct Student));
		new->grade = (rand() % (100 + 1 - 3) + 3);
		new->age = (rand() % (17 + 1 - 14) + 14);
		printf("grade:\n%d\n", new->grade);
		addnode(head, new);
		return head;
	}
}

struct Student *addnode(struct Student *head, struct Student *new)
{

	if (new->grade >= head->grade)
	{
		if (head->rightnext == 0)
		{

			head->rightnext = new;

			return 0;
		}
		else
		{

			addnode(head->rightnext, new);
		}
	}
	else
	{
		if (head->leftnext == 0)
		{

			head->leftnext = new;
		}
		else
		{

			addnode(head->leftnext, new);
		}
	}
	return 0;
}
void print(struct Student *head)
{

	if (head->leftnext != 0)
	{
		print(head->leftnext);
	}

	printf("\n%d\n", head->grade);

	if (head->rightnext != 0)
	{
		print(head->rightnext);
	}
}

struct Student *search(struct Student *head, int number)
{

	if (number == head->grade)
	{
		printf("found %d", number);
		return head;
	}
	else
	{
		if (number >= head->grade)
		{
			if (head->rightnext != 0)
			{
				
				search(head->rightnext, number);
				
			}
			else
			{
				printf("sorry, could not find %d", number);
				return 0;
			}
		}
		else
		{
			if (head->leftnext != 0)
			{
				
				search(head->leftnext, number);
				
			}
			else
			{
				printf("sorry, could not find %d", number);
				return 0;
			}
		}
	}
	return 0;
}
struct Student *delete (struct Student *head, int number)
{
	/*struct Student *bemp;
	struct Student *demp;*/
	struct Student *nodetodelete;
	struct Student *tempnode;
	tempnode = head;
	
	if (tempnode == NULL)
	{
		printf("Element Not Found");
		return head;
	}
	else if (number < tempnode->grade)
	{
		tempnode->leftnext = delete(tempnode->leftnext, number);
	}
	else if (number >= tempnode->grade)
	{
		tempnode->rightnext = delete(tempnode->rightnext, number);
	}
	else
	{
		nodetodelete = tempnode;
printf("%d", nodetodelete->grade);
	
	
		if (nodetodelete->rightnext != 0 && nodetodelete->leftnext != 0)
		{
			printf("sho");
			tempnode = nodetodelete->leftnext;
			while (tempnode->rightnext != 0)
			{
				tempnode = tempnode->rightnext;
			}
			
			nodetodelete->grade = tempnode->grade;
			nodetodelete->age = tempnode->age;
			free(tempnode);

			return head;
		}
		else
		{
			
			printf("darn");
			tempnode = nodetodelete;
			if (nodetodelete->rightnext != 0)
			{
				nodetodelete->grade =
				    nodetodelete->rightnext->grade;
				nodetodelete->age =
				    nodetodelete->rightnext->age;
			}
			else if (nodetodelete->leftnext != 0)
			{
				nodetodelete->grade =
				    nodetodelete->leftnext->grade;
				nodetodelete->age = nodetodelete->leftnext->age;
			}
			
			printf("%d", nodetodelete->grade);
			
			free(tempnode);
			return head;
		
		}
		
	
	}
	return 0;

	}
	
struct Student *deletem(struct Student *node, int data)
{
	struct Student *temphead = node;
	struct Student *temp;
	if (node == NULL)
	{
		printf("Element Not Found");
		return temphead;
	}
	else if (data < node->grade)
	{
		node->leftnext = deletem(node->leftnext, data);
	}
	else if (data > node->grade)
	{
		node->rightnext = deletem(node->rightnext, data);
	}
	else
	{
		printf("%d", node->grade);
		/* Now We can delete this node and replace with either minimum
		   element
			   in the right sub tree or maximum element in the left
		   subtree*/
		if (node->rightnext && node->leftnext)
		{
			/* Here we will replace with minimum element in the
			 * right sub tree */
			temp = node->rightnext;
			while (temp->leftnext != 0)
			{
				temp = temp->leftnext;
			}

			node->grade = temp->grade;
			/* As we replaced it with some other node, we have to
			 * delete that node */
			node->rightnext = deletem(node->rightnext, temp->grade);
			return temphead;
		}
		else
		{
			/* If there is only one or zero children then we can
			   directly
				       remove it from the tree and connect its
			   parent to its child */
			temp = node;
			if (node->leftnext == NULL)
			{
				node = node->rightnext;
			}
			else if (node->rightnext == NULL)
			{
				node = node->leftnext;
			}
			free(temp); /* temp is longer required */
			return temphead;
		}
	}
	return temphead;
}
