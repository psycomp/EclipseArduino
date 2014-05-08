/*
 * Functions.cpp
 *
 *  Created on: May 5, 2014
 *      Author: sweinberger
 */
#include "Functions.h"
#include "Arduino.h"
#include <stdarg.h>

void p(char *fmt, ... ){
        char buf[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(buf, 128, fmt, args);
        va_end (args);
        Serial.print(buf);
}

void plot(int data1) {
  int pktSize;
  int buffer[20];

  buffer[0] = 0xCDAB;             //SimPlot packet header. Indicates start of data packet
  buffer[1] = 1*sizeof(int);      //Size of data in bytes. Does not include the header and size fields
  buffer[2] = data1;

  pktSize = 2 + 2 + (1*sizeof(int)); //Header bytes + size field bytes + data

  Serial.write((uint8_t * )buffer, pktSize);
}

