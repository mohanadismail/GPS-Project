#include <string.h>

void split_GPGGA (char str[]) {
	char *data[15];
  data[0] = strtok(str, ",");
  int i = 0;
  while (data[i] != NULL && i < 14) {
		i++;
    data[i] = strtok(NULL, ",");
  }
}

void extract_GPGGA_message(char str[]) {
    str[0] = '$';
    str[1] = 'G';
    str[2] = 'P';
    str[3] = 'G';
    str[4] = 'G';
    str[5] = 'A';
    int i;
    while (1) {
        char c = readUART();
        i = 6;
        if (c == '$') {
            c = readUART();
            if (c == 'G') {
                c = readUART();
                if (c == 'P') {
                    c = readUART();
                    if (c == 'G') {
                        c = readUART();
                        if (c == 'G') {
                            c = readUART();
                            if (c == 'A') {
                                while (c != '\n') {
                                    c = readUART();
                                    str[i] = c;
                                    i++;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}