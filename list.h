#ifndef __LIST_H__
#define __LIST_H__

struct date;
struct node;

struct node * createList(void);
void destroyList(struct node* h);
struct node *newRegistration(struct node *ptr);
int lengthList(struct node * h);
void printothersMet(struct node *h);
void printIDs(struct node *h);
void meeting(struct node *p1, struct node *p2);
int countLeapYears(struct date d);
int dateDifference(struct date d1, struct date d2);
void validateMeetingDates(struct node *h);
void checkInfected(struct node *h);

#endif