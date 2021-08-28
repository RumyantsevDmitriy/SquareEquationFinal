#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "Functions.h"
#include "Constants.h"

int SolveSquareEquation(double a, double b, double c, double* root1, double* root2)
{
	int status_of_solve_square_equation = 0;

    if(!isfinite(a) || !isfinite(b) || !isfinite(c))
    {
        status_of_solve_square_equation = BAD_ENTERED_DATA;
        return status_of_solve_square_equation;
    }

    if(root1 == NULL || root2 == NULL || root1 == root2)
    {
        status_of_solve_square_equation = BAD_ROOT_ADDR;
        return status_of_solve_square_equation;
    }

	if(IsZero(a))
	{
		status_of_solve_square_equation = SolveLineEquation(b, c, root1);
		*root2 = *root1;
		return status_of_solve_square_equation;
	}
	else
	{
		double D = b * b - 4 * a * c;

        if(IsZero(D))
		{
			*root1 = *root2 = -b / (2 * a);
			status_of_solve_square_equation = ONE_ROOT;
            return status_of_solve_square_equation;
		}
		else if (D < 0)
		{
            status_of_solve_square_equation = NO_ROOT;
            return status_of_solve_square_equation;
		}
		else
		{
			*root1 = (-b + sqrt(D)) / (2 * a);
			*root2 = (-b - sqrt(D)) / (2 * a);
			status_of_solve_square_equation = TWO_ROOT;
            return status_of_solve_square_equation;
		}
	}
}

int SolveLineEquation(double k, double b, double *root)
{
    int status_of_solve_line_equation = 0;

    if(!isfinite(k) || !isfinite(b))
    {
        status_of_solve_line_equation = BAD_ENTERED_DATA;
        return status_of_solve_line_equation;
    }

    if(root == NULL)
    {
        status_of_solve_line_equation = BAD_ROOT_ADDR;
        return status_of_solve_line_equation;
    }

    if(IsZero(b))
    {
        if(IsZero(k))
        {
            status_of_solve_line_equation = INF_ROOT;
            return status_of_solve_line_equation;
        }
    }
    else if(!IsZero(k))
    {
        *root = -b / k;
        status_of_solve_line_equation = ONE_ROOT;
        return status_of_solve_line_equation;
    }

    status_of_solve_line_equation = NO_ROOT;
    return status_of_solve_line_equation;
}

int CompareDoubles(double val1, double val2)
{
    if(isnan(val1) && isnan(val2))
    {
        return EQUAL;
    }

    if(fabs(val1 - val2) <= PRECISION)
    {
        return EQUAL;
    }
    else if (val1 - val2 < 0)
    {
        return LESS;
    }
    else
    {
        return MORE;
    }
}

bool IsZero(double val)
{
    assert(!isnan(val));
    return (fabs(val) <= PRECISION);
}
