#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <cctype>

#include "Functions.h"
#include "Constants.h"

void GetData(double *a, double *b, double *c)
{
    printf("Введите значение аргумента a: ");
	CheckData(a);

	printf("Введите значение аргумента b: ");
	CheckData(b);

	printf("Введите значение аргумента c: ");
	CheckData(c);
}

void CheckData(double *value)
{
    assert(value != NULL);

	int data = scanf("%lg", value);

    if(!isfinite(*value) || !isspace(getchar()))
    {
        int status_of_programm = BAD_ENTERED_DATA;
        printf("%s\nЗапустите программу заново", StatusOfErrorToString(status_of_programm));
        exit(0);
    }
}
