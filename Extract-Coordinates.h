#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float getLatitude(char *data[]) { return strtof(data[2], NULL); }

float getLongitude(char *data[]) { return strtof(data[4], NULL); }

int validity(char *data[]) {
    
  if (*data[6] <= '0') {
      
    return 0;
      
  } else if ('1' <= *data[6] && *data[6] <= '5') {
      
    return 1;
      
  } else {      
    return 0;
  }
}

