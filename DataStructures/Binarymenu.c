
#include"binarytree.h" 

int main(void)
{
	int p = 0;
	int r = 0;
	struct Student *head = 0;
	time_t seconds;
	
	seconds = time(NULL);
	srand(seconds);
	
	while(1)
	{
		printf("\nMenu:\n1 to add to the tree\n2 to delete from the tree\n3 to search the tree\n4 to print the tree\n5 to quit\n");
		scanf("\n%d", &p);
		switch(p)
		{
			case(1):
			
			head= add(head);
			break;
			
			case(2):
			printf("what grade should be deleted?");
			scanf("%d", &r);
			delete(head, r);
			break;
			
			case(3):
			printf("what grade to search for?");
			scanf("%d", &r);
			search(head, r);
			break;
			
			case(4):
			print(head);
			break;
			
			case(5):
			return 0;
			break;
			default:
			printf("invalid input");
			break;
			
		}
	}
	
}