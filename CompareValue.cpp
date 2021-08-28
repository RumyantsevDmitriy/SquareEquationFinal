#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "Functions.h"
#include "Constants.h"

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
