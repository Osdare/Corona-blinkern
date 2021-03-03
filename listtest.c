#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "list.h"

int main(void)
{
    node_t p1 = createList();
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