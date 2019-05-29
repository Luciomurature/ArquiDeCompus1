#include <stdio.h>
#include <stdlib.h>


void output(unsigned char);
void autoFantastico();
void delayc(int);
void autoFantasticoAlgoritmico();
void carrera();

void choque();

//globals para funciones por tabla

unsigned char datosAuto[]= {
        0x80,
        0x40,
        0x20,
        0x10,
        0x08,
        0x04,
        0x02,
        0x01,
};

unsigned char datosChoque[] = {
        0x81,
        0x42,
        0x24,
        0x18,
        0x18,
        0x24,
        0x42,
        0x81,
};

unsigned char datosCarrera[] = {
        0x80,
        0x80,
        0x40,
        0x40,
        0x20,
        0x20,
        0x10,
        0x10,
        0x88,
        0x48,
        0x24,
        0x14,
        0x0A,
        0x06,
        0x03,
        0x01,
};


int main() {


    autoFantastico();

    autoFantasticoAlgoritmico();

    printf("\n");

    carrera();

    printf("\n");

    choque();








    return 0;
}


void delayc(int a){
    for(int j=0;j<a;j++){
        unsigned int i = 0x4fffff; //raspberry 0x3fffff
        while(i)i--;
    }
}



void output(unsigned char b){


    for(int i = 8; i > 0; i--){
        if((b&1) == 1){
            printf("*");
        }else printf("_");
        b = b >> 1;
    }

    printf("\n");


}

void autoFantastico() {

    printf("Auto Fantastico\n");
    output(1);
    delayc(25);
    int i = 2;
    do {
        output(i);
        delayc(25);
        i *= 2;
    } while (i <= 64);
    do {
        output(i);
        delayc(25);
        i /= 2;
    } while (i > 0);

}




void autoFantasticoAlgoritmico() {

    for(int i = 0; i < 8; i++){
        output(datosAuto[i]);
        delayc(25);
    }
    for(int i = 7; i > 0; i--){
        output(datosAuto[i]);
        delayc(25);
    }




}


void carrera(){
    for(int i = 0; i < 16; i++){
        output(datosCarrera[i]);
        delayc(25);
    }
}


void choque(){
    for(int i = 0; i < 8; i++){
        output(datosChoque[i]);
        delayc(25);
    }
}

