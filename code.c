#include <stdio.h>

WriteToFile(char *data)
{
    int i;
    FILE * fptr = fopen("code.txt", "a+");
    if(fptr == NULL)
    {
        printf("Error opening a file");
        return 0;
    }
    fputs(data, fptr);
    fclose(fptr);
    return 0;
}

ValidateFileDates()
{

}

