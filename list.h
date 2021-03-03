#ifndef __LIST_H__
#define __LIST_H__

typedef struct node* node_t;
struct date;

node_t createList(void);
void destroyList(node_t h);
node_t newRegistration(node_t ptr);
int lengthList(node_t h);
void printothersMet(node_t h);
void printIDs(node_t h);
void meeting(node_t p1, node_t p2);
int countLeapYears(struct date d);
int dateDifference(struct date d1, struct date d2);
void validateMeetingDates(node_t h);
void checkInfected(node_t h);

#endif