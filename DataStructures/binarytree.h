#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


struct Student *delete(struct Student *head, int number);

struct Student *search(struct Student *head, int number);

struct Student *deletem(struct Student *node, int data);

void print(struct Student *head);

struct Student *addnode(struct Student *head,struct Student *new);

struct Student *add(struct Student *head);