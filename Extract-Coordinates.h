#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GPGGA_functions.h"

char *data[15]; //externed by GPGGA_functions.h

double getLatitude() { return atof(data[2]); }

double getLongitude() { return atof(data[4]); }

int validity(char *data[]) {
    
  if (*data[6] <= '0') {
      
    return 0;
      
  } else if ('1' <= *data[6] && *data[6] <= '5') {
      
    return 1;
      
  } else {      
    return 0;
  }
}

