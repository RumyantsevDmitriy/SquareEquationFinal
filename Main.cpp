#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <cctype>

#include "Functions.h"
#include "Constants.h"

int main(void)
{
	double a = NAN, b = NAN, c = NAN, root1 = NAN, root2 = NAN;

	printf("Вы открыли программу, решающую квадратные уравнения\nКвадратное уравнение имеет вид: a * x^2 + b * x + c = 0 , где a, b, c - числа\n\n");
    printf("Если вы хотите протестировать программу автоматически - нажмите Y ");

    switch (getchar())
    {
        case 'Y': RunUnitTest();
                  break;
        default:  GetData(&a, &b, &c);
                  int status_of_programm = SolveSquareEquation(a, b, c, &root1, &root2);

                  if(!IsSuccess(status_of_programm))
                  {
                      printf("%s", StatusOfErrorToString(status_of_programm));
                  }
                  else
                  {
                      switch (status_of_programm)
                      {
                          case NO_ROOT:          printf("\nДанное уравнение не имеет решений");
                                                 break;
                          case ONE_ROOT:         printf("\nДанное уравнение имеет одно решение: x1=x2= %lg", root1);
                                                 break;
                          case TWO_ROOT:         printf("\nДанное уравнение имеет два решения: x1= %lg\n\t\t\t\t\t\b\b\b\bx2= %lg", root1, root2);
                                                 break;
                          case INF_ROOT:         printf("\nДанное уравнение иммет бесконечно большое количество решений");
                                                 break;
                          default:               return 0;
                      }
                  }

    }

    return 0;
}
