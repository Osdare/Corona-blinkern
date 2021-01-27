#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

struct date
{
    int day;
    int month;
    int year;
};

bool isLeapYear (struct date d)
{
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
        return true; // It's a leap year
    else
        return false; // Not a leap year
}

bool isInfected (int code)
{
    int coronaCodes[3] = {24038623, 56509924, 15515512};

    if (code == coronaCodes[0] || code == coronaCodes[1] || code == coronaCodes[2])
        return true;
    else
        return false;
}

char * enterCode()
{
    static char code[8];
    bool validInput = false;
    printf("1. Input opening code\n");
    while(validInput == false)
    {
        fgets(code, 9, stdin);
        fflush(stdin);
        int i, count;
        for(i = 0; code[i] != '\0'; i++)
        {
            if( isdigit(code[i]) == true)
                count++;
        }
        if(count == 7)
            validInput = true;
        else
        {
            printf("Invalid input >:(\n");
            count = 0;
        }
    }
    return code;
}

struct date enterDate()
{
printf("2. Input identificationcode and date\n");
}

bool dateValidator(struct date d)
{
    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(d.month > 12 || d.month < 1)
        return false;
    if(d.month == 2 && d.day == 29 && (isLeapYear(d) == false) )
        return false;
    if(d.day > daysPerMonth[d.month] || d.day < 1)
        return false;
    if(d.year < 1 || d.year > 3000)
        return false;
    return true;
}

int main(void)
{
    const char * code1 = enterCode();
    printf("The code is: %s",code1);
    return 0;
}
