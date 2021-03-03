//MAMMA MIA

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct date
{
    int day;
    int month;
    int year;
};

struct node
{
    int ID;
    int meetings;//Number of people this node has met
    bool intfected;//if a valid code has been entered this bool is true
    struct date d[64];// Dates of meetings
    int othersMet[64];// ID of people met
    struct node* next;
};

struct node * createList(void)
{
    struct node* header = (struct node*) malloc(sizeof(struct node));
    header->next = NULL;
    header->intfected = false;
    header->ID = (rand() % 99999999 + 1);
    header->meetings = 0;
    return header;
}

void destroyList(struct node* h)
{   
    struct node* temp;
    while (h->next)
    {
        temp = h->next;
        free(temp);
        h = h->next;
    }
    free(h);
}

struct node *newRegistration(struct node *ptr)
{
    struct node* pointer = (struct node*) malloc(sizeof(struct node));
    int userID = (rand() % 99999999 + 1);
    if (ptr==NULL)
    {
        pointer->ID = userID;
        pointer->intfected = false;
        pointer->next = NULL;
        return pointer;
    }
    struct node *listPtr;
    listPtr = ptr;
    while (listPtr->next)
        listPtr = listPtr->next;
     listPtr->next = pointer; 
    pointer->ID = userID;
    pointer->intfected = false;
    pointer->next = NULL;
    return ptr;
}

int lengthList(struct node * h)
{
    int len = 0;
    struct node *current = h;
    while(current != NULL)
    {
        len++;
        current = current->next; 
    }
    return len;  
}

void printothersMet(struct node *h)
{
    int count = 1;
    struct node *current = h;
    while(current != NULL)
    {
        for(int i = 0; i < current->meetings; i++)
            printf("%d has met %d\n", current->ID, current->othersMet[i]);
        current = current->next; 
        count++;
    }
    return;
}

void printIDs(struct node *h)
{
    int count = 1;
    struct node *current = h;
    while(current != NULL)
    {
        printf("ID for object %d is %d\n", count, current->ID);
        current = current->next; 
        count++;
    }
    return;
}

void meeting(struct node *p1, struct node *p2)
{
    time_t t = time(0);
    struct tm now_t = *localtime(&t);
    

    p1->d[p1->meetings].year = now_t.tm_year + 1900;
    p1->d[p1->meetings].month = now_t.tm_mon + 1;
    p1->d[p1->meetings].day = now_t.tm_mday;

    p2->d[p1->meetings].year = now_t.tm_year + 1900;
    p2->d[p1->meetings].month = now_t.tm_mon + 1;
    p2->d[p1->meetings].day = now_t.tm_mday;
    
    p1->othersMet[p1->meetings] = p2->ID;
    p2->othersMet[p2->meetings] = p1->ID;

    p1->meetings++;
    p2->meetings++;

    return;
}

int countLeapYears(struct date d)
{
    int years = d.year;

    if(d.month <= 2)
        years--;
    
    return years / 4 - years / 100 + years / 400;
}

int dateDifference(struct date d1, struct date d2)//most recent date goes to the right
{
    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    long int n1 = d1.year * 365 + d1.day;
    for (int i = 0; i < d1.month - 1; i++)
        n1 += daysPerMonth[i];
    n1 += countLeapYears(d1);

    long int n2 = d2.year * 365 + d2.day;
    for (int i = 0; i < d2.month - 1; i++)
        n2 += daysPerMonth[i];
    n2 += countLeapYears(d2);

    return (n2 - n1);
}

void validateMeetingDates(struct node *h)
{
    time_t t = time(0);
    struct tm now_t = *localtime(&t);
    struct date today;

    today.year = now_t.tm_year + 1900;
    today.month = now_t.tm_mon + 1;
    today.day = now_t.tm_mday;

    struct node *ptr = h;

    while(ptr != NULL)
    {
        int i;
        for(i = 0; i < ptr->meetings; i++)
        {
            if(dateDifference(ptr->d[i],today) > 21)
            {
                int c;
                for(c = i; c < ptr->meetings - 1; c++)
                {
                    ptr->d[c] = ptr->d[c+1];
                    ptr->othersMet[c] = ptr->othersMet[c+1];
                }
                ptr->meetings--;
            }
        }
        ptr = ptr->next;
    }
    return;
}

void checkInfected(struct node *h)
{
    struct node *current = h;
    while(current != NULL)
    {
        if(current->intfected == true)
        {
            int i;
            for(i = 0; i < current->meetings; i++)
                printf("%d has been exposed to the virus by %d\n", current->othersMet[i], current->ID);
        }
        current = current->next;
    }
}

int main(void)
{
    struct node* p1 = createList();
    newRegistration(p1);
    newRegistration(p1);
    int len = lengthList(p1);

    printf("Length of the list is %d\n",len);

    meeting(p1,p1->next);
    meeting(p1,p1->next->next);
    printf("%d-%d-%d\n",p1->d[p1->meetings-1].year, p1->d[p1->meetings-1].month, p1->d[p1->meetings-1].day);
    printf("ID %d\n",p1->next->next->ID);
    printf("meetings: %d\n",p1->meetings);
    printf("\n");

    p1->intfected = true;
    checkInfected(p1);

    printf("\n");
    printothersMet(p1);
    p1->d[0].month--;
    printf("\n");
    validateMeetingDates(p1);
    printothersMet(p1);
    printf("\n");

    p1->intfected = true;
    checkInfected(p1);

    destroyList(p1);

    return 0;
}

