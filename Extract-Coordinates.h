#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GPGGA_functions.h"

char *data[15]; //externed by GPGGA_functions.h

double getLatitude() { return atof(data[2]); }

double getLongitude() { return atof(data[4]); }

int validity() {
    
  if (*data[6] <= '0') {
      
    return 0;
      
  } else if ('1' <= *data[6] && *data[6] <= '5') {
      
    return 1;
      
  } else {      
    return 0;
  }
}

double getTime() {
	double time = atof(data[1]);
	return ((int)(time/10000))*60*60 + (((int)(time/100)) - ((int)(time/10000))*100)*60 + (time - ((int)(time/100))*100);
}
