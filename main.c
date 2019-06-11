#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <termios.h>
#include <sys/ioctl.h>

static const int DELAYBAJO = 3;
static const int DELAYBAJO1 = 5;
static const int DELAYBAJO2 = 8;
static const int DELAYMEDIO = 10;
static const int DELAYMEDIO2 = 12;
static const int DELAYALTO = 15;
static const int DELAYALTO1 = 18;
static const int DELAYALTO2 = 20;


void menu();
int login();
void output(unsigned char);
void autoFantastico();
void delayc(int);
void autoFantasticoAlg();
void menu();
void carrera();
void pool();
void choque();
void tenis();
void tenis2();
void suicide();
bool kbhit();


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

unsigned char datosTenis[] ={
        0x81,
        0xC1,
        0xA1,
        0x91,
        0x89,
        0x85,
        0x83,
        0x83,
        0x85,
        0x89,
        0x91,
        0xA1,
        0xC1,
};




unsigned char datosSuicide[]={
    0x80,
    0x40,
    0x80,
    0x40,
    0x20,
    0x40,
    0x80,
    0x40,
    0x20,
    0x10,
    0x20,
    0x40,
    0x80,
    0x40,
    0x20,
    0x10,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
    0x40,
    0x20,
    0x10,
    0x08,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
    0x40,
    0x20,
    0x10,
    0x08,
    0x04,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
    0x40,
    0x20,
    0x10,
    0x08,
    0x04,
    0x02,
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
};



char password[6];

int main() {

    strcpy(password, "kevin");


    if(login() == 0){
        printf("\nContraseña correcta\n");

        menu();
    }else{
        return 0;
    }
    return 0;
}


void menu(){
    system("clear");
    int state = 0;
    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("\nBienvenidos al proyecto de Arquitectura de Software I por Murature y Schröder \n");
    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    do{
    char n;
    printf("\n1- Auto fantastico\n");
	printf("\n2- El choque\n");
	printf("\n3- Pool\n");
	printf("\n4- Tenis\n");
    printf("\n5- Carrera\n");
    printf("\n6- Suicida\n");
	printf("\n0- Salir\n");	

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");

    n = getchar();

    switch(n){
        case'0':
             state = 1;
             break;
        case '1':
            printf("\nPresione enter para salir\n");
            do{
                autoFantasticoAlg();
            }while (!kbhit());
            break;
        case '2':
            do{
                choque();
            }while(!kbhit());
            break;
        case '3':
            do{
                pool();
                }while(!kbhit());
            break;
        case '4':
            do{
                tenis();
               }while(!kbhit());
            break;
        case '5':
            do{
                carrera();
              }while(!kbhit());
            break;
        case '6':
        do{
            suicide();
        }while(!kbhit());
            break;
        default:
            break;
    }
    }while(!state);
}





bool kbhit(){
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    return byteswaiting > 0;
}

int login(){
    initscr();
    noecho();
    int error = 0;
    char c;
    char ingreso[5];
    do {
        printw("Ingrese su password de 5 dígitos:\n");

        for (int i = 0; i < 5; i++) {
            c = getch();
            ingreso[i] = c;
            printw("*");
        }
        if(strcmp(password, ingreso) != 0){
            error++;
            printw("\n Contraseña Incorrecta \n");
        }
    }while(error < 3 && strcmp(password, ingreso) != 0);
    echo();
    endwin();
    return strcmp(password, ingreso);

}





void delayc(int a) {
    for (int j = 0; j < a; j++) {
        unsigned int i = 0x4fffff; //raspberry 0x3fffff
        while (i)i--;
    }
}

void output(unsigned char b){
    for(int i = 8; i > 0; i--){
        if((b&1) == 1){
            printf("*");
        }else printf("_");
        b = b >> 1;
    }
    printf("\r");
    fflush(stdout);
}

void autoFantasticoAlg() {
    output(1);
    delayc(DELAYMEDIO);
    int i = 2;
    do {
        output(i);
        delayc(DELAYMEDIO);
        i *= 2;
    } while (i <= 64);
    do {
        output(i);
        delayc(DELAYMEDIO);
        i /= 2;
    } while (i > 0);
}

void pool(){
    int i = 128;
    do{
        output(i+16);
        delayc(DELAYMEDIO);
        if (i==32)
            i/=2;
        i /=2;
    }while (i>0);
}

void autoFantastico() {
    for(int i = 0; i < 8; i++){
        output(datosAuto[i]);
        delayc(DELAYMEDIO);
    }
    for(int i = 7; i != 0; i--){
        output(datosAuto[i]);
        delayc(DELAYMEDIO);
    }
}

void carrera(){
    for(int i = 0; i < 16; i++){
        output(datosCarrera[i]);
        delayc(DELAYMEDIO);
    }
}
void choque(){
    for(int i = 0; i < 8; i++){
        output(datosChoque[i]);
        delayc(DELAYMEDIO);
    }
}

void tenis(){
    for(int i = 0; i < 13; i++){
        output(datosTenis[i]);
        delayc(DELAYMEDIO);
    }
}

void tenis2(){
    int i = 64;
    do {
        output(i + 129);
        delayc(DELAYMEDIO);
        i/=2;
    }while(i>2);
    do{
        output(i+129);
        delayc(DELAYMEDIO);
        i*=2;
    }while (i<65);
}

void suicide(){
    for(int i = 0; i < 57 ; i++){
        output(datosSuicide[i]);
        delayc(DELAYMEDIO);
    }
}


