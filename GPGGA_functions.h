#include <string.h>
#include "UART.h"

extern char str[150]; //global variable for storing GPGGA message
extern char *data[15]; //global variable containing tokens of GPGGA message
extern int data_length; //global variable that will be used to check gps fix
int i;

void split_GPGGA () {
	//str[] is a global variable
	//This function takes the GPGGA message from str[] and splits it into tokens
	//to easily extract quality indicator, latitude and longitude
  data_length = 0;
	data[0] = strtok(str, ",");
  while (data[data_length] != NULL && data_length < 14) {
		data_length++;
    data[data_length] = strtok(NULL, ",");
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
  while (1) {
		char c = readUART5();
    i = 6;
    if (c == '$') {
        c = readUART5();
        if (c == 'G') {
            c = readUART5();
            if (c == 'P') {
                c = readUART5();
                if (c == 'G') {
                    c = readUART5();
                    if (c == 'G') {
                        c = readUART5();
                        if (c == 'A') {
													c = readUART5();
                            while (c != '\n') {
															str[i] = c;
                              i++;
															c = readUART5();
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
