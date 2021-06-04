#include <string.h>
#include "UART.h"

extern char str[150]; //global variable for storing GPGGA message
extern char *data[15]; //global variable containing tokens of GPGGA message

void split_GPGGA () {
	//str[] is a global variable
	//This function takes the GPGGA message from str[] and splits it into tokens
	//to easily extract quality indicator, latitude and longitude
  int i = 0;
	data[0] = strtok(str, ",");
  while (data[i] != NULL && i < 14) {
		i++;
    data[i] = strtok(NULL, ",");
  }
}

void extract_GPGGA_message() {
	//str[] is a global variable
	//This function keeps on receiving input from the UART until
	//it detects the GPGGA message, then stores the message in str[]
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
