#include <stdio.h>

void WriteToFile(char *data)
{

    FILE * fptr = fopen("code.txt", "a+");
    if(fptr == NULL)
    {
        printf("Error opening a file");
    }
    fputs(data, fptr);
    fclose(fptr);
}

void ValidateFileDates()
{

}

