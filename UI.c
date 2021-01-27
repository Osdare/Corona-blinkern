#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    int day;
    int month;
    int year;
};

bool isLeapYear(struct date d)
{
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
        return true; // It's a leap year
    else
        return false; // Not a leap year
}

bool isInfected(int code)
{
    int coronaCodes[3] = {24038623, 56509924, 15515512};

    if (code == coronaCodes[0] || code == coronaCodes[1] || code == coronaCodes[2])
        return true;
    else
        return false;
}

char *enterCode(int mode) // mode 0 = opening code(got the C). mode 1 = ID code
{
    static char code[9];
    bool validInput = false;

    while (validInput == false)
    {
        fgets(code, 8 + mode, stdin);
        fflush(stdin);
        int i, count;
        for (i = 0; code[i] != '\0'; i++)
        {
            if (isdigit(code[i]) == true)
                count++;
            else
            {
                printf("Invalid input :( try again!\n");
                count = 0;
                memset(code, 0, 9*sizeof(char));
            }
            
        }
        if (count == 7 + mode)
            validInput = true;
        else
            count = 0;
        
    }
    return code;
}

bool dateValidator(struct date d)
{
    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.month > 12 || d.month < 1)
        return false;
    if (d.month == 2 && d.day == 29 && (isLeapYear(d) == false))
        return false;
    if (d.day > daysPerMonth[d.month] || d.day < 1)
        return false;
    if (d.year < 1 || d.year > 3000)
        return false;
    return true;
}

struct date enterDate()
{
    printf("2. Input date (DD.MM.YYYY)\n");
    struct date d;
    while (1)
    {
        scanf("%d.%d.%d", &d.day, &d.month, &d.year);
        fflush(stdin);

        if (dateValidator(d) == false)
            printf("Entered invalid date. Try again\n");
        else
            return d;
    }
}

int main(void)
{
    printf("-------------------\n");
    printf("Input opening code:\n\n");
    struct date d;

    const char *id = enterCode(0);
    printf("%s\n\n",id);
    fflush(stdin);
    d = enterDate();
    printf("\n%d.%d.%d\n", d.day, d.month, d.year);
    printf("-------------------\n");
    printf("Input verfication code: \n\n");
    const char *code = enterCode(1);
    printf("\n%s\n",code);
    printf("Code activated sucessfully!\n");
    printf("---------------------------\n");

    return 0;
}