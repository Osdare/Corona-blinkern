#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

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

char * enterCode(int mode) // mode 0 = opening code. mode 1 = ID code
{
    static char code[9];
    bool validInput = false;
    if (mode == 0)
        printf("1. Input opening code (7 digits)\n");
    else if (mode == 1)
        printf("2.1. Enter ID code (8 digits)\n");
    else
        printf("Error in code: int mode has an invalid value.\n");
    while(validInput == false)
    {
        fgets(code, 9 + mode, stdin);
        fflush(stdin);
        int i, count;
        for(i = 0; code[i] != '\0'; i++)
        {
            if( isdigit(code[i]) == true)
                count++;
        }
        if(count == 7 + mode)
            validInput = true;
        else
        {
            printf("Invalid input >:(\n");
            count = 0;
        }
    }
    return code;
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
int Quit = 0;
    while (Quit == 0)
    {
        printf("3. Type 3 to confirm exit: ");
        scanf("%d", &Quit);

struct date enterDate()
{
    printf("2. Input date (DD.MM.YYYY)\n");
    struct date d;
    while(1)
    {
        scanf("%d.%d.%d", &d.day, &d.month, &d.year);
        

        if(dateValidator(d) == false)
            printf("Entered invalid date. Try again\n");
        else
            return d;
    }
}

int main(void)
{
    struct date d;
    printf ("3. Exit program\n");
    const char * code1 = enterCode(0);
    printf("The code is: %s",code1);
    d = enterDate();
    printf("The date is: %i.%i.%i", d.day, d.month, d.year);
    return 0;
}