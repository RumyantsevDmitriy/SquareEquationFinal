#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <cctype>

#include "Functions.h"
#include "Constants.h"

int main(void)
{
	double a = NAN, b = NAN, c = NAN, root1 = NAN, root2 = NAN;

	printf("�� ������� ���������, �������� ���������� ���������\n���������� ��������� ����� ���: a * x^2 + b * x + c = 0 , ��� a, b, c - �����\n\n");
    printf("���� �� ������ �������������� ��������� ������������� - ������� Y ");

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
                          case NO_ROOT:          printf("\n������ ��������� �� ����� �������");
                                                 break;
                          case ONE_ROOT:         printf("\n������ ��������� ����� ���� �������: x1=x2= %lg", root1);
                                                 break;
                          case TWO_ROOT:         printf("\n������ ��������� ����� ��� �������: x1= %lg\n\t\t\t\t\t\b\b\b\bx2= %lg", root1, root2);
                                                 break;
                          case INF_ROOT:         printf("\n������ ��������� ����� ���������� ������� ���������� �������");
                                                 break;
                          default:               return 0;
                      }
                  }

    }

    return 0;
}
