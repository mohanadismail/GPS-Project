#include <string.h>

void splitUART (char str[]) {
	char *data[15];
  data[0] = strtok(str, ",");
  int i = 0;
  while (data[i] != NULL && i < 14) {
		i++;
    data[i] = strtok(NULL, ",");
  }
}