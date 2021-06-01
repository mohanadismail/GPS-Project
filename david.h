#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float getLatitude(char *data[])
{
    if (!strcmp(data[0], "$GPGGA"))
    {
        return strtof(data[2], NULL);
    }
}

float getLongitude(char *data[])
{
    if (!strcmp(data[0], "$GPGGA"))
    {
        return strtof(data[4], NULL);
    }
}
int validity(char *data[])
{
    if (!strcmp(data[0], "$GPGGA"))
    {
        if (*data[6] == '1')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
