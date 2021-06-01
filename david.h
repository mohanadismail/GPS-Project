#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float getLatitude(char *data[])
{
    if (data[0] == "$GPGAA")
    {
        return strtof(data[2], NULL);
    }
}

float getLongitude(char *data[])
{
    if (data[0] == "$GPGAA")
    {
        return strtof(data[4], NULL);
    }
}
bool validity(char *data[])
{
    if (data[0] == "$GPGAA")
    {
        if (data[6] == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
