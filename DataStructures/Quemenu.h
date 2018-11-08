#include <math.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Student *add_stack(struct Student *head);

int stack(int r);

int lifo(int r);

int fifo(int r);

void clear(void);

struct Student *sort(struct Student *head);

void printlist(struct Student *head);

void fifotest(struct Student *head, int r);

struct Student *addfifo(struct Student *current);

void lifotest(struct Student *head, int r);

struct Student *delete (struct Student *head, int node, int r);

void search(struct Student *head, int number);

void average(struct Student *head);

void update(struct Student *head, int element, int newgrade, int newage);

struct Student *add(struct Student *current);

void stacktest(struct Student *head, int r);