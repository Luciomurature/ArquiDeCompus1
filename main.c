#include <stdio.h>
#include <stdlib.h>


void output(unsigned char);
void autoFantastico();
void delayc(int);


int main() {


    //auto fantastico


    autoFantastico();








    return 0;
}


void output(unsigned char b){
    char led[8] = {'_','_','_','_','_','_','_','_'};

    for(int i = 0; i < 8; i++){
        if((b&1) == 1){
            led[i] = '*';
        }
        b = b >> 1;
    }


    for(int i = 8; i > 0; i--)
    printf("%c", led[i-1]);


    printf("\n");
    printf("\n");
    printf("\n");


}

void autoFantastico() {
    output(1);
    delayc(25);
    int i = 2;
    do {
        output(i);
        delayc(25);
        i = i * 2;
    } while (i <= 64);
    do {
        output(i);
        delayc(25);
        i = i / 2;
    } while (i > 0);
}


void delayc(int a){
        for(int j=0;j<a;j++)
        {
            unsigned int i = 0x4fffff; //raspberry 0x3fffff
            while(i)i--;
        }
        //system("clear");
    }


