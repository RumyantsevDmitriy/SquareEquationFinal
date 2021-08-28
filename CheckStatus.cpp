#include <stdio.h>

#include "Functions.h"
#include "Constants.h"

const char* StatusOfErrorToString(int status_of_programm)
{
    switch (status_of_programm)
	{
        case BAD_ENTERED_DATA: return(BAD_ENTERED_DATA_MSG);
                               break;
        case BAD_ROOT_ADDR:    return(BAD_ROOT_ADDR_MSG);
                               break;
        default:               return(UNIDENTIFIED_ERROR_MSG);
                               break;
	}
}

bool IsSuccess(int status_of_programm)
{
    return (status_of_programm >= 0) ? 1 : 0;
}
