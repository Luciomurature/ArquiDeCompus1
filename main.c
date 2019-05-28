#include <stdio.h>
#include <stdlib.h>


void output(unsigned char);
void autoFantastico();


int main() {
    printf("Hello, World!\n");
    int n;
    scanf("%d", &n);
    output(n);


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

void autoFantastico(){
    int n=0;
    do{
        n++;
        char led[8] = {'_','_','_','_','_','_','_','_'};
        for (int i=0; i<8; i++){
            led[i] = '*';
            for(int i=8; i > 0 ; i--){
                printf("%c",led[i]);
            }
            printf("\n");

            char led[8] = {'_','_','_','_','_','_','_','_'};
        }

    }while(n<1);



}