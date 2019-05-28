#include <stdio.h>


void output(unsigned char);


int main() {
    printf("Hello, World!\n");
    int n;
    scanf("%d", &n);
    output(n);


    //auto fantastico







    return 0;
}


void output(unsigned char b){
    char led[8] = {'_','_','_','_','_','_','_','_'};
    int pos;

    for(int i = 0; i < 8; i++){
        if((b&1) == 1){
            pos = i;
        }
        led[pos] = '*';
        b = b >> 1;
    }


    for(int i = 8; i > 0; i--)
    printf("%c", led[i-1]);

}

void AutoFantastico(){
    char led[8] = {'_','_','_','_','_','_','_','_'};
}