#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<memory.h>
#include<stdint.h>
#include<stdio.h>



void clear(void);

struct Student * sort(struct Student* head);

void printlist(struct Student *head);

struct Student *delete(struct Student *head, int node);

void search(struct Student *head, int number);

void average(struct Student *head);

void update(struct Student *head, int element, int newgrade, int newage);

struct Student *add(struct Student *current);