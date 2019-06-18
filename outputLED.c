#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "EasyPIO.h"



void outputLED(unsigned char b){
    const char led[] = {14,15,18,23,25,8,7};
    const char sw[] = {12,16,20,21};
    for(int i = 8; i > 0; i--){
        if((b&1) == 1){
            //prender
            digitalWrite(led[i], OUTPUT);
        }else digitalWrite(led[i], 0); //apagar
        b = b >> 1;
    }
}